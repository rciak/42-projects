/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:17:38 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 19:04:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static int	exec__first(t_cmd first_cmd);
static int	exec__mid(t_cmd mid_cmd, int fd_read);
static void	exec__last(t_cmd _last_cmd, int fd_read);

/**
 * @brief This setups and executes the pipe(x)line
 * @param[in] data
 * @param[in] envp
 * @param[out] x_err
 */
void	exec_pipeline(t_cmd	*cmd, size_t n_cmds, char** envp, t_x_err *x_err)
{
	int		fd_read;
	size_t	i;

	if (n_cmds < 2)
		; //                                                                Error!
	i = 0;
	while (i < n_cmds)
	{
		if (i == 0)
			fd_read = exec__first(cmd[i]);
		else if (0 < i && i < n_cmds - 1)
			fd_read = exec__mid(cmd[i], fd_read);
		else if (i == n_cmds - 1)
			exec__last(cmd[i], fd_read);
		else
			; //                                                    Skip or better Error for debugging?!
		i++;
	}
}

static int	exec__first(t_cmd first_cmd)
{
	return (0);
}

static int	exec__mid(t_cmd mid_cmd, int fd_read)
{
	return (0);
}

static void	exec__last(t_cmd _last_cmd, int fd_read)
{

}
