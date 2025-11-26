/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:40:47 by reciak            #+#    #+#             */
/*   Updated: 2025/11/26 12:15:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right);
static void	redir__input(t_data *data, int i);
static void	redir__output(t_data *data, int i);
static void	close__io(t_data *data, int i);

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
usleep(137);
		data->i_cmd_err = i;
		if (i < data->num_cmds - 1)
			connect__by_a_pipe(data, i, i + 1);
		cmd[i].pid = fork ();
		if (cmd[i].pid == -1)
			exit_on(E_FORK, errno, "exec_pipeline", data);
		else if (cmd[i].pid == 0)
		{
#include <stdio.h>
fprintf(stderr, "\ni: %d\n", i);
print_cmds(data, "Child: Before redirs\n", "fds");
			redir__input(data, i);
			redir__output(data, i);
print_cmds(data, "\nChild: After redirs\n", "fds");
			exec_cmd(data, i, envp);
		}
//		close__io(data, i);
		i++;
	}
	return (wait_without_creating_zombies(cmd[data->num_cmds - 1].pid));
}

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right)
{
	int pfd[2];

	if (pipe(pfd) == -1)
		exit_on(E_CREATE_PIPE, errno, "connect__by_a_pipe", data);
	data->cmd[i_left].fd_out = pfd[WRITE_TO];
	data->cmd[i_right].fd_in = pfd[READ_FROM];
}

static void	redir__input(t_data *data, int i)
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
			exit_on(E_CLOSE, errno, "redir__input", data);
		cmd->fd_in = UNUSED;
	}
	cmd->fd_in = open(cmd->infile, O_RDONLY);
fprintf(stderr, "redir__input: infile: %s\n", cmd->infile);
fprintf(stderr, "redir__input: fd_in: %d\n", cmd->fd_in);
	if (cmd->fd_in == -1)
		exit_on(E_OPEN_READ, errno, "redir__input", data);
	dup2(cmd->fd_in, STDIN_FILENO);
	if (close(cmd->fd_in) == -1)
		exit_on(E_CLOSE, errno, "redir__input", data);
	cmd->fd_in = UNUSED;
}

static void	redir__output(t_data *data, int i)
{
	t_cmd *cmd;

	cmd = &(data->cmd[i]);
	if (cmd->outfile == NULL)
		return ;
	if (cmd->fd_out >= 0)
	{
		if (cmd->fd_out == STDOUT_FILENO)
			out_str_fd(RED"Warning"RESET" - closing standard fd for output"
				"(unusual for the write end of a pipe)\n",	STDERR_FILENO);
		if (close(cmd->fd_out) == -1)
			exit_on(E_CLOSE, errno, "redir__output", data);;
		cmd->fd_out = UNUSED;
	}
	cmd->fd_out = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd_out == -1)
		exit_on(E_OPEN_WRITE, errno, "redir__output", data);
	dup2(cmd->fd_out, STDOUT_FILENO);
	if (close(cmd->fd_out) == -1)
		exit_on(E_CLOSE, errno, "redir__output", data);
	cmd->fd_out = UNUSED;
}

static void	close__io(t_data *data, int i)
{
	t_cmd	*cmd;

	cmd = &(data->cmd[i]);
	if (cmd->fd_in == STDIN_FILENO || cmd->fd_out == STDOUT_FILENO
		|| cmd->fd_out == STDERR_FILENO)
		out_str_fd(RED"Warning"RESET" - closing standard fd\n", STDERR_FILENO);
	if (cmd->fd_in >= 0)
	{
		if (close (cmd->fd_in) == -1)
			exit_on(E_CLOSE, errno, "close__io", data);
		cmd->fd_in = UNUSED;
	}
	if (cmd->fd_out >= 0)
	{
		if (close (cmd->fd_out) == -1)
			exit_on(E_CLOSE, errno, "close__io", data);
		cmd->fd_out = UNUSED;
	}
}
