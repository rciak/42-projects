/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pathname_as_cur_dir_av0.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:48:43 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 14:26:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_pathname_as_cur_dir_av0.c
 * @brief Stores the definition of set_pathname_as_cur_dir_av0()
 */

#include "pipex.h"

static void	prefix__with_dot_slash(char **pathname);

/**
 * @brief Sets and checks pathname as av[0] of the current command, providing
 *        "./" prefix
 * @param[in] i the index of the current command
 * @param[in,out] data -> cmd[i].pathname
 */
void	set_pathname_as_cur_dir_av0(t_data *data, int i)
{
	data->cmd[i].pathname = ft_strdup(data->cmd[i].av[0]);
	if (data->cmd[i].pathname == NULL)
		exit_on(E_ALLOC, errno, "set_pathname_as_cur_dir_av0", data);
	if (ft_strncmp(data->cmd[i].pathname, "./", 2) != 0)
	{
		prefix__with_dot_slash(&(data->cmd[i].pathname));
		if (data->cmd[i].pathname == NULL)
			exit_on(E_ALLOC, errno, "set_pathname_as_cur_dir_av0", data);
	}
}

static void	prefix__with_dot_slash(char **pathname)
{
	char	*new;

	new = ft_strjoin("./", *pathname);
	if (new == NULL)
		exit_on(E_ALLOC, errno, "prefix__with_dot_slash", NULL);
	free(*pathname);
	*pathname = new;
}
