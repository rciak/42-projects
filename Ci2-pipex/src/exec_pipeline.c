/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:40:47 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 19:03:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right);
static void	update__fd_in_on_redir(t_data *data, int i);
static void	update__fd_out_on_redir(t_data *data, int i);
static void	exec__cmd(t_data *data, int i, char **envp);

/**
* @brief Executes the pipe(x)line
* @param[in, out] data
* @param[in] envp
* @return Exitstatus of the last (rightmost) command of the pipe(x)line
*/
int	exec_pipeline(t_data *data, char **envp)
{
	t_cmd	*cmd;
	int		i;

	cmd = data->cmd;
	if (data->num_cmds < 2)
		exit_on(E_ASSERTION, ERRNO_IRREL, "exec_pipeline", data);
	i = 0;
	while (i < data->num_cmds)
	{
		data->i_cmd_err = i;
		if (i < data->num_cmds - 1)
			connect__by_a_pipe(data, i, i + 1);
		cmd[i].pid = fork ();
		if (cmd[i].pid == -1)
			exit_on(E_FORK, errno, "exec_pipeline", data);
		else if (cmd[i].pid == 0)
		{
			update__fd_in_on_redir(data, i);
			update__fd_out_on_redir(data, i);
			exec__cmd(data, i, envp);
		}
		close_fd_in_fd_out(data, i);
		i++;
	}
	return (wait_without_creating_zombies(cmd[data->num_cmds - 1].pid));
}

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right)
{
	int	pfd[2];

	if (pipe(pfd) == -1)
		exit_on(E_CREATE_PIPE, errno, "connect__by_a_pipe", data);
	data->cmd[i_left].fd_out = pfd[WRITE_TO];
	data->cmd[i_right].fd_in = pfd[READ_FROM];
}

static void	update__fd_in_on_redir(t_data *data, int i)
{
	t_cmd	*cmd;

	cmd = &(data->cmd[i]);
	if (cmd->infile == NULL)
		return ;
	if (cmd->fd_in >= 0)
	{
		if (cmd->fd_in == STDIN_FILENO)
			out_str_fd(RED"Warning"RESET" - closing standard fd for input"
				"(unusual for the read end of a pipe)\n", STDERR_FILENO);
		if (close(cmd->fd_in) == -1)
			exit_on(E_CLOSE, errno, "update__fd_in_on_redir", data);
		cmd->fd_in = UNUSED;
	}
	cmd->fd_in = open(cmd->infile, O_RDONLY);
	if (cmd->fd_in == -1)
		exit_on(E_OPEN_RD, errno, "update__fd_in_on_redir", data);
}

static void	update__fd_out_on_redir(t_data *data, int i)
{
	t_cmd	*cmd;

	cmd = &(data->cmd[i]);
	if (cmd->outfile == NULL)
		return ;
	if (cmd->fd_out >= 0)
	{
		if (cmd->fd_out == STDOUT_FILENO)
			out_str_fd(RED"Warning"RESET" - closing standard fd for output"
				"(unusual for the write end of a pipe)\n", STDERR_FILENO);
		if (close(cmd->fd_out) == -1)
			exit_on(E_CLOSE, errno, "update__fd_out_on_redir", data);
		cmd->fd_out = UNUSED;
	}
	cmd->fd_out = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd_out == -1)
		exit_on(E_OPEN_WR, errno, "update__fd_out_on_redir", data);
}

/**
 * @brief Perpares and executes a single command of the pipe(x)line
 * @note The check `av[0] == NULL` is for the case that an empty command
 *       ('' or "") was given as a parameter to pipex.
 * @param[in, out] data The data
 * @param[in] i The index of the current command
 * @param[in] envp The environment handed over to execve
 */
static void	exec__cmd(t_data *data, int i, char **envp)
{
	t_cmd	*cmd;
	char	**av;

	cmd = &(data->cmd[i]);
	av = data->cmd[i].av;
	if (dup2(cmd->fd_in, STDIN_FILENO) == -1
		|| dup2(cmd->fd_out, STDOUT_FILENO) == -1)
		exit_on(E_DUP_TWO, errno, "exec_cmd", data);
	close_fd_in_fd_out(data, i);
	if (i < data->num_cmds - 1)
		close_fd_in_fd_out(data, i + 1);
	if (av[0] == NULL)
		exit_on(E_NOT_FOUND, errno, "exec__cmd", data);
	if ((ft_strncmp(av[0], "/", 1) == 0 || ft_strncmp(av[0], "./", 2) == 0))
		set_pathname_as_av0(data, i);
	else if (data->path == NULL || *data->path == NULL)
		set_pathname_as_cur_dir_av0(data, i);
	else
		set_pathname_via_path(data, i);
	if (execve(cmd->pathname, av, envp) == -1)
	{
		free (cmd->pathname);               // Redundant? 
		cmd->pathname = NULL;               // --> Done in tidy up anyway?
		exit_on(E_EXECVE, errno, "exec_cmd", data);
	}
}
