/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 17:34:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file h_err_exit.c
 * @brief Stores the definition of h_err_exit()
 */

#include "pipex.h"

static void	default__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err);
static void	assertion__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err);

/**
 * @brief Handles the passed error and exits
 */
void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	if (err->type == E_FUN_ASSERTION)
		assertion__err_handling(num_cmds, cmd, err);
	else
		default__err_handling(num_cmds, cmd, err);
}

static void	assertion__err_handling(size_t num_cmds, t_cmd *cmd, t_err *err)
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
	out_str_fd("\nExiting ... ", STDERR_FILENO);
	out_str_fd("\n  --> Assertion in function  ", STDERR_FILENO);
	out_str_fd((char *) err->origin, STDERR_FILENO);
	out_str_fd("  failed\n", STDERR_FILENO);
	exit(err->exit.code);
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
