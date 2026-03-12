/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_in_fd_out_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:17:30 by reciak            #+#    #+#             */
/*   Updated: 2025/11/30 14:37:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file close_fd_in_fd_out.c
 * @brief Stores the definition of close_fd_in_fd_out()
 */

#include "pipex_bonus.h"

/**
 * @brief Closes fd_in and fd_out of the i-th command provided they are >= 0
 * @note A warning is given for the unexpected case that they are equal to
 *       STDIN_FILENO and STDOUT_FILENO, respecticely.
 * @param[in] data providing access to cmd
 * @param[in] i The index of the command
 */
void	close_fd_in_fd_out(t_data *data, int i)
{
	t_cmd	*cmd;

	cmd = &(data->cmd[i]);
	if (cmd->fd_in == STDIN_FILENO || cmd->fd_out == STDOUT_FILENO
		|| cmd->fd_out == STDERR_FILENO)
		out_str_fd(RED"Warning"RESET" - closing standard fd\n", STDERR_FILENO);
	if (cmd->fd_in >= 0)
	{
		if (close (cmd->fd_in) == -1)
			exit_on(E_CLOSE, errno, "close__fd_in_fd_out", data);
		cmd->fd_in = UNUSED;
	}
	if (cmd->fd_out >= 0)
	{
		if (close (cmd->fd_out) == -1)
			exit_on(E_CLOSE, errno, "close__fd_in_fd_out", data);
		cmd->fd_out = UNUSED;
	}
}
