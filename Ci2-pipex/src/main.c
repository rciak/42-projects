/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/23 09:09:32 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

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
	t_x_err	x_err;
	t_data	data;
	pid_t	pid_last_cmd;
	int		termination_status_last_cmd;

	x_err = x_error(ERR_NONE, 0, "main");
	if (!parse(argc, argv, &data, &x_err)
		|| !parse_path(envp, data.num_cmds, data.cmd, &x_err)
		|| !exec_pipeline(data.cmd, data.num_cmds, &x_err))
		return (handle_error(x_err));
	pid_last_cmd = data.cmd[data.num_cmds - 1].pid;
	termination_status_last_cmd
		= wait__without_creating_zombies(pid_last_cmd);
	final_free(data);
	return (termination_status_last_cmd);
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
	wstatus = 0;
	status_last_cmd = 0;
	while(pid > 0)
	{
		pid = waitpid(-1, &wstatus, 0);
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}
