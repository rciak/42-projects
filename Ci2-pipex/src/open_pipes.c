/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:31:07 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 18:16:31 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file open_pipes.c
 * @brief Stores the definition of open_pipes()
 */

#include "pipex.h"

/**
 * @brief Opens pipes for interconnecting the to be later executed commands.
 * @param[in] num_cmds
 * @param[out] cmd
 * @param[out] err
 * @return 
 *          * true if opening of pipes worked
 *          * false on error (stored in *err)
 */
bool	open_pipes(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	int		pfd[2];
	size_t	i;

	i = 0;
	while (i < num_cmds - 1)
	{
		if (pipe(pfd) == -1)
			return (set_err(err, E_CREATE_PIPE, errno, "open_pipes"), false);
		cmd[i].fd_out = pfd[WRITE_TO];
		cmd[i + 1].fd_in = pfd[READ_FROM];
		i++;
	}
	return (true);
}
