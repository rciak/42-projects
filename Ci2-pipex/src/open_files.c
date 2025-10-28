/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:48:07 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 17:13:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file open_files.c
 * @brief Stores the definition of open_files()
 */

#include "pipex.h"

static bool	open__infile(t_cmd *cmd, t_err *err);
static bool	open__outfile(t_cmd *cmd, t_err *err);

/**
 * @brief Tries to open the specified .in_file and .out_file
 * @note 
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * true, of opening of files was succesful
 *          * false, if it did not work
 */
bool	open_files(size_t num_cmds, t_cmd *cmd, t_err* err)
{
	size_t i;

	i = 0;
	while (i < num_cmds)
	{
		if (cmd[i].infile != NULL && !open__infile(&cmd[i], err))
			return (false);
		if (cmd[i].outfile != NULL && !open__outfile(&cmd[i], err))
			return (false);
		i++;
	}
	return (true);
}

static bool	open__infile(t_cmd *cmd, t_err *err)
{
	cmd->fd_in = open(cmd->infile, O_RDONLY);
	if (cmd->fd_in == -1)
	{
		out_str_fd(cmd->infile, STDERR_FILENO);
		out_str_fd(": ", STDERR_FILENO);
		set_err(err, E_OPEN_READ, errno, "open__infile");
		return (false);
	}
	return (true);
}

static bool	open__outfile(t_cmd *cmd, t_err *err)
{
	cmd->fd_out = open(cmd->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (cmd->fd_out == -1)
	{
		out_str_fd(cmd->outfile, STDERR_FILENO);
		out_str_fd(": ", STDERR_FILENO);
		set_err(err, E_OPEN_WRITE, errno, "open__outfile");
		return (false);
	}
	return (true);
}
