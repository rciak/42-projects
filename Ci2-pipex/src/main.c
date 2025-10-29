/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:54:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 18:16:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"

static bool	argc__ok(int argc, t_err *err);
static bool	alloc__cmds_pre_init(t_data *data, t_err *err);
static void	final__tidy_up(size_t num_cmds, t_cmd *cmd, t_err *err);
static int	wait__without_creating_zombies(pid_t pid_last_cmd);

/**
 * @brief The entry point and dirigent for the pipex programm ...
 * @note A note 
 * @note For building the documentation from comment blocks like this one run
 *         make doc; open doc/html/index.html
 * @param[in] argc The number of arguments handed over by the calling shell
 * @param[in] argv argv[0], argv[1], ... argv[argc - 1] are pointers to strings
 *                  containing the programms name and the command-line arguments
 *                  passed to the program.
 * @param[in] envp Well similar but for the environment variables.
 * @return a return code indicating success or an error.
 */
int	main(int argc, char **argv, char**envp)
{
	t_err	err;
	t_data	data;
	int		termination_status_last_cmd;

	set_err(&err, E_NONE, 0, "main");
	err.cmd_index = -1;
	data.num_cmds = (size_t) argc - 3;
	if (!argc__ok(argc, &err)
		|| !alloc__cmds_pre_init(&data, &err)
		|| !parse_argv(argc, argv, &data, &err))
		print_exit_msg_and_exit(&err);
	if (!parse_path(envp, data.num_cmds, data.cmd, &err)
		|| !open_pipes(data.num_cmds, data.cmd, &err)
		|| !open_files(data.num_cmds, data.cmd, &err))
		h_err_exit(data.num_cmds, data.cmd, &err);
	if (!exec_pipeline(&data, envp, &err))
		h_err_exit(data.num_cmds, data.cmd, &err);
	termination_status_last_cmd
		= wait__without_creating_zombies(data.cmd[data.num_cmds - 1].pid);
	final__tidy_up(data.num_cmds, data.cmd, &err);
	return (termination_status_last_cmd);
}

static bool	argc__ok(int argc, t_err *err)
{
	if (argc >= 1 + 4)
		return (true);
	set_err(err, E_ARGC, errno, "main");
	return (false);
}

static bool	alloc__cmds_pre_init(t_data *data, t_err *err)
{
	size_t	num_cmds;
	t_cmd	*cmd;
	size_t	i;

	data->cmd = malloc(data->num_cmds * sizeof (*data->cmd));
	if (data->cmd == NULL)
		return (set_err(err, E_ALLOC, errno, "alloc__cmds_pre_init"), false);
	num_cmds = data->num_cmds;
	cmd = data->cmd;
	i = 0;
	while (i < num_cmds)
	{
		cmd[i].ac = 0;
		cmd[i].av = NULL;
		cmd[i].path = NULL;
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		cmd[i].fd_in = DO_NOT_USE;
		cmd[i].fd_out = DO_NOT_USE;
		cmd[i].pid = DO_NOT_USE;
		i++;
	}
	return (true);
}

static void	final__tidy_up(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	t_err	copy;
	size_t	i;

	copy = *err;
	i = 0;
	while (i < num_cmds)
	{
		tidy_up_and_reset_cmd_items(&cmd[i], err);
		i++;
	}
	free (cmd);
	if (err->type != copy.type)
		out_str_fd(BLUE"What?! Even on tidying up another error happend?!\n"
			"Not investigating that ...\n"RESET, STDERR_FILENO);
}

/**
 * @note Neither the flags WUNTRACED nor WCCONTINUED are given as option to 
         to waitpid.
         Thus the *wait status* set by waitpid covers exactly the
         *termination status* of the child process for the last command, cf.
         Kerrisk (The Linux Programming Interface, Sec. 26.1.3
         "The Wait Status Value", p. 545).
 * @note @code waitpid(-1, &termination_status, 0); @endcode is equivalent to
 *       @code wait(&termination_status); @endcode
 */
static int	wait__without_creating_zombies(pid_t pid_last_cmd)
{
	pid_t	pid;
	int		wstatus;
	int		status_last_cmd;

	pid = 1;
	while (pid > 0)
	{
		pid = waitpid(-1, &wstatus, 0);
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}
