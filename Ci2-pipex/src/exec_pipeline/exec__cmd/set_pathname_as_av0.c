/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pathname_as_av0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:43:55 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 19:54:10 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_pathname_as_av0.c
 * @brief Stores the definition of set_pathname_as_av0()
 */

#include "pipex.h"

/**
 * @brief Sets and checks pathname as av[0] of the current command
 * @note If the check with access fails the program exits
 * @param[in] i the index of the current command
 * @param[in,out] data -> cmd[i].pathname
 */
void	set_pathname_as_av0(t_data *data, int i)
{
	data->cmd[i].pathname = ft_strdup(data->cmd[i].av[0]);
	if (data->cmd[i].pathname == NULL)
		exit_on(E_ALLOC, errno, "set_pathname_as_av0", data);
	if (access(data->cmd[i].pathname, F_OK) == -1)
		exit_on(E_NOT_FOUND, errno, "set_pathname_as_av0", data);
	if (access(data->cmd[i].pathname, X_OK) == -1)
		exit_on(E_NO_PERM, errno, "set_pathname_as_av0", data);
}
