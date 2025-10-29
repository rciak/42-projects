/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 16:01:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file h_err_exit.c
 * @brief Stores the definition of h_err_exit()
 */

#include "pipex.h"

static void	do__nonsense_cleanup(size_t num_cmds, t_cmd *cmd, t_err *err);
static void	assertion__err_handling(t_err *err);
static void not_found__err_handling(t_cmd *cmd);
static void	execve__err_handling(t_cmd *cmd, t_err *err);

/**
 * @brief Handles the passed error and exits
 */
void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	t_err	backup;	

	backup = *err;
	do__nonsense_cleanup(num_cmds, cmd, err);
	*err = backup;
	if (err->type == E_FUN_ASSERTION)
		assertion__err_handling(err);
	else if (err->type == E_NOT_FOUND)
		not_found__err_handling(cmd);
	else if (err->type == E_EXECVE_FAILED)
		execve__err_handling(cmd, err);
	else
		print_exit_msg(err);
	exit(err->exit.code);
}

static void	do__nonsense_cleanup(size_t num_cmds, t_cmd *cmd, t_err *err)
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
}
static void	assertion__err_handling(t_err *err)
{
	out_str_fd("\nExiting ... ", STDERR_FILENO);
	out_str_fd("\n  --> Assertion in function  ", STDERR_FILENO);
	out_str_fd((char *) err->origin, STDERR_FILENO);
	out_str_fd("  failed\n", STDERR_FILENO);
}

static void not_found__err_handling(t_cmd *cmd)
{
	out_str_fd("\nExiting ... ", STDERR_FILENO);
	out_str_fd("\n  --> not found: ", STDERR_FILENO);
	out_str_fd(cmd->av[0], STDERR_FILENO);
	out_str_fd("\n", STDERR_FILENO);
}

static void	execve__err_handling(t_cmd *cmd, t_err *err)
{
	out_str_fd("\nExiting ... ", STDERR_FILENO);
	if (err->saved_errno == ENOENT)
	{
		out_str_fd("\n  --> not found: ", STDERR_FILENO);
		out_str_fd(cmd->av[0], STDERR_FILENO);
		out_str_fd("\n", STDERR_FILENO);
	}
	else if (err->saved_errno == EACCES)
	{
		out_str_fd("\n  --> no access: ", STDERR_FILENO);
		out_str_fd(cmd->av[0], STDERR_FILENO);
		out_str_fd("\n", STDERR_FILENO);
	}
	else
		print_exit_msg(err);
}
