/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:17:38 by reciak            #+#    #+#             */
/*   Updated: 2025/10/21 12:50:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static int		exec__first(t_cmd first_cmd, t_x_err *x_err);
static int		exec__mid(t_cmd mid_cmd, int fd_read, t_x_err *x_err);
static pid_t	exec__last(t_cmd _last_cmd, int fd_read, t_x_err *x_err);

/**
 * @brief This setups and executes the pipe(x)line
 * @param[in] data
 * @param[out] pid Stores the pid returned by fork before exec the last command 
 *                 (or -1 if an error occured before that)
 * @param[out] x_err Providing feedback to the caller for error handling
 * @return
 *          * false,  if a fork failed or if an execv failed
 *          * true, else 
 */
bool	exec_pipeline(t_cmd	*cmd, size_t n_cmds, t_x_err *x_err)
{
	int		fd_read;
	size_t	i;
	
	if (n_cmds < 2)
		; //                                                                Error!
	i = 0;
	while (i < n_cmds)
	{
		if (i == 0)
			fd_read = exec__first(cmd[i], x_err);
		else if (0 < i && i < n_cmds - 1)
			fd_read = exec__mid(cmd[i], fd_read, x_err);
		else
			*pid = exec__last(cmd[i], fd_read, x_err);
		if (x_err->code == ERR_FORK || x_err->code == ERR_EXECV)
			return (false);
		i++;
	}
	return (true);
}

static int	exec__first(t_cmd first_cmd, t_x_err *x_err)
{
																			return (0);
}

static int	exec__mid(t_cmd mid_cmd, int fd_read, t_x_err *x_err)
{
																			return (0);
}

static pid_t	exec__last(t_cmd _last_cmd, int fd_read, t_x_err *x_err)
{
																			return (0);
}
