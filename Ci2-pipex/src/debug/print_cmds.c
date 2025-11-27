/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:02:14 by reciak            #+#    #+#             */
/*   Updated: 2025/11/27 10:49:14 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_cmds.c
 * @brief Stores the definition of print_cmds()
 */

#include "pipex.h"
#include <stdio.h>

void	print_cmds(t_data *data, char *intro, char *what)
{
	int	i;

	fprintf(stderr, "%s", intro);
	i = 0;
	while (i < data->num_cmds)
	{
		print_cmd_i(data, i, what);
		i++;
	}
}
