/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 09:54:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file h_err_exit.c
 * @brief Stores the definition of h_err_exit()
 */

#include "pipex.h"

static void	default__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err);

/**
 * @brief Handles the passed error and exits
 */
void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err)
{

	// if ...
	//else
	//  Unexpected error occured
	default__err_handling(num_cmds, cmd, err);
}

static void	default__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	t_err	copy;
	size_t	i;

	copy = *err;
	i = 0;
	while (i < num_cmds)
	{
		tidy_up_and_reset_cmd_items(&cmd[i], err);
		i++;
	}
	free (cmd);
	if (err->type != copy.type)
		out_str_fd(BLUE"What?! Even on tidying up another error happend?!\n"
			"Not investigating that (*). Just reporting the previous issue..\n"
			"\n"
			"REMARK to (*) : Who came up with the 'good' idea of cleaning\n"
			"before exiting although the OS can do this better? ;-) )\n\n"RESET,
			STDERR_FILENO);
	print_exit_msg_and_exit(&copy);
}
