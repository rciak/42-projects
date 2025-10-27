/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 13:17:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file h_err_exit.c
 * @brief Stores the definition of h_err_exit()
 */

#include "pipex.h"

static void	standard__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err);

/**
 * @brief Handles the passed error and exits
 */
void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err)
{

	// if ...
	//else
	//  Unexpected error occured
	standard__err_handling(num_cmds, cmd, err);
}

static void	standard__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	size_t	i;
	t_err	copy;

	copy = *err;
	if (cmd != NULL)
	{
		i = 0;
		while (i < num_cmds)
		{
			cmd[i].ac = 0;
			free_array_and_reset(&cmd[i].av);
			free_array_and_reset(&cmd[i].path);
			free_and_reset(&cmd[i].infile);
			free_and_reset(&cmd[i].outfile);
			close_and_reset(&cmd[i].fd_in, err);
			close_and_reset(&cmd[i].fd_out, err);
			i++;
		}
	}
	if (err->type != copy.type)
		out_str_fd("What?! Even on tidying up another error happend?!\n"
			"Not investigating that - Just reporting the previous issue..\n",
			STDERR_FILENO);
	print_exit_msg_and_exit(&copy);
}

