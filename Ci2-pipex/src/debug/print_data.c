/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:01:37 by reciak            #+#    #+#             */
/*   Updated: 2025/11/27 10:48:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file  print_data.c
 * @brief Stores the definition of print_data()
 */
#include "pipex.h"
#include <stdio.h>

void	print_data(t_data *data, char *what)
{
	fprintf(stderr, "======================================================\n");
	fprintf(stderr, "i_cmd_err: %d\n", data->i_cmd_err);
	fprintf(stderr, "num_cmds:  %d\n", data->num_cmds);
	print_cmds(data, "", what);
	fprintf(stderr, "path:\n");
	print_arr(data->path, "    ");
}
