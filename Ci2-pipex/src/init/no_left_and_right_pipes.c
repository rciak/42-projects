/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_left_and_right_pipes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:55:26 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 17:43:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file no_left_and_right_pipes.c
 * @brief Stores the definition of no_left_and_right_pipes()
 */

#include "pipex.h"

/**
 * @brief Each command is ensured to have initially no left and no right pipe.
 * @note More precide: For each data->cmd[i] both pointers
 *       .left_pipe and .right_pipe are set to NULL.
 * @param[in] cmd a pointer to an array of t_parse_unit - objects.
 * @param[out] num_commands the number of elements the array consists of
 */
void	no_left_and_right_pipes(t_cmd *cmd, size_t num_commands)
{
	size_t	i;

	i = 0;
	while (i < num_commands)
	{
		cmd[i].left_pipe = NULL;
		cmd[i].right_pipe = NULL;
		i++;
	}
}