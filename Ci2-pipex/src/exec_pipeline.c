/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:40:47 by reciak            #+#    #+#             */
/*   Updated: 2025/11/21 15:47:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right);
static void	close__io(t_data *data, int i);

 /**
 * @brief Executes the pipe(x)line
 * @param[in, out] data
 * @param[in] envp
 */
void	exec_pipeline(t_data *data, char **envp)
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
		connect__by_a_pipe(data, i, i + 1);
		cmd[i].pid = fork ();
		if (cmd[i].pid == -1)
			exit_on(E_FORK, errno, "exec_pipeline", data);
		else if (cmd[i].pid == 0)
			exec_cmd(data, i);
		close__io(data, i);
		i++;
	}
}

static void	connect__by_a_pipe(t_data *data, int i_left, int i_right)
{
	int pfd[2];

	if (i_right >= data->num_cmds)
		return ;
	if (pipe(pfd) == -1)
		exit_on(E_CREATE_PIPE, errno, "connect__by_a_pipe", data);
	data->cmd[i_left].fd_out = pfd[WRITE_TO];
	data->cmd[i_right].fd_in = pfd[READ_FROM];
}

static void	close__io(t_data *data, int i)
{
	t_cmd	*cmd;

	cmd = &(data->cmd[i]);
	if (cmd->fd_in == STDIN_FILENO || cmd->fd_out == STDOUT_FILENO)
		out_str_fd(RED"Warning"RESET" - closing standard fd\n", STDERR_FILENO);
	if (cmd->fd_in >= 0)
	{
		close (cmd->fd_in);
		cmd->fd_in = UNUSED;
	}
	if (cmd->fd_out >= 0)
	{
		close (cmd->fd_out);
		cmd->fd_out = UNUSED;
	}
}
