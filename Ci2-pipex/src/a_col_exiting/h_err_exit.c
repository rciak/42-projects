/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 16:04:21 by reciak           ###   ########.fr       */
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
	t_err	copy;

	copy = *err;
	if (cmd != NULL)
		tidy_up_all_cmds(num_cmds, cmd, err);
	if (err->type != copy.type)
		out_str_fd("What?! Even on tidying up another error happend?!\n"
			"Not investigating that - Just reporting the previous issue..\n",
			STDERR_FILENO);
	print_exit_msg_and_exit(&copy);
}
