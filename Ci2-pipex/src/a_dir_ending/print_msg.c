/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:53:28 by reciak            #+#    #+#             */
/*   Updated: 2025/11/28 13:17:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_msg.c
 * @brief Stores the definition of print_msg()
 */

#include "pipex.h"

static char *interpretation__str2(t_exit_info info, t_data *data);

/**
 * @brief Print a message on exititing
 * @note This function should be called only by exit_on()
 * @param[in] info exit info
 * @param[in] origin the name of the function which caused the error
 * @param[in] data providing access to usuable information
 */

void	print_msg(t_exit_info info, const char *origin, t_data *data)
{
	char	*str2_final;
	char	*msg;
	
	str2_final = treat__str2(info, data);
	if (str2_final == NULL)
		exit_on(E_ALLOC, errno, "print_msg", data);
	msg = NULL;
	if (!add_to_str(&msg, "\nExiting ... \n  --> ")
		|| !add_to_str(&msg, info.str1)
		|| !add_to_str(&msg, " ")
		|| !add_to_str(&msg, str2_final)
		|| !add_to_str(&msg, "           (origin: ")
		|| !add_to_str(&msg, origin)
		|| !add_to_str(&msg, ")\n")
	)
	{
		free(str2_final);
		free(msg);
		exit_on(E_ALLOC, errno, "print_msg", data);
	}
	out_str_fd(msg, STDERR_FILENO);
	free(str2_final);
	free(msg);
}

static bool add__to_str(char **str, const char *post_fix)
{
	char	*new;
	
	if (*str == NULL)
		new = ft_strdup(post_fix);
	else
		new = ft_strjoin(*str, post_fix);
	if (new == NULL)
		return (false);
	free(*str);
	*str = new;
	return (true);
}

static char *interpretation__str2(t_exit_info info, t_data *data)
{
	t_cmd	*cmd;
	int		i;
	char *interpreted;

	cmd = data->cmd;
	i = data->i_cmd_err;
	interpreted = NULL;


	
	return (interpreted);
}
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
