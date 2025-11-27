/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:53:28 by reciak            #+#    #+#             */
/*   Updated: 2025/11/27 16:43:59 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_msg.c
 * @brief Stores the definition of print_msg()
 */

#include "pipex.h"

static void	treat_str2(t_exit_info info, const char *origin, t_data *data);

/**
 * @brief Print a message on exititing
 * @note This function should be called only by exit_on()
 * @param[in] info exit info
 * @param[in] origin the name of the function which caused the error
 * @param[in] data providing access to usuable information
 */

void	print_msg(t_exit_info info, const char *origin, t_data *data)
{
	t_cmd	*cmd;
	int		i;

	cmd = NULL;
	if (data != NULL)
	{
		cmd = data->cmd;
		i = data->i_cmd_err;
	}
	out_str_fd("\nExiting ... ", STDERR_FILENO);
	out_str_fd("\n  --> ", STDERR_FILENO);
	out_str_fd(info.str1, STDERR_FILENO);
	out_str_fd(" ", STDERR_FILENO);
	treat_str2(info, origin, data);
	out_str_fd("\n", STDERR_FILENO);
}

static void	treat_str2(t_exit_info info, const char *origin, t_data *data)
{
	t_cmd	*cmd;
	int		i;

	cmd = data->cmd;
	i = data->i_cmd_err;
	if (ft_strcmp(info.str2, "cmd[i].av[0]") == 0)
		out_str_fd(cmd[i].av[0], STDERR_FILENO);
	else if (ft_strcmp(info.str2, "cmd[i].infile") == 0)
		out_str_fd(cmd[i].infile, STDERR_FILENO);
	else if (ft_strcmp(info.str2, "cmd[i].outfile") == 0)
		out_str_fd(cmd[i].outfile, STDERR_FILENO);
	else if (ft_strcmp(info.str2, "origin") == 0)
		out_str_fd((char *) origin, STDERR_FILENO);
	else
		out_str_fd(info.str2, STDERR_FILENO);
}
