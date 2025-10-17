/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:04:57 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 19:26:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file final_free.c
 * @brief Stores the definition of final_free()
 */

#include "pipex.h"

/**
 * @brief Final freeing, be it meaningful or not ...
 * @param[in,out] data Acces the to be freed items (amongst others)
 */

void	final_free(t_data data)
{
	size_t			i;
	t_cmd	*cmd;

	cmd = data.cmd;
	i = 0;
	while (i < data.num_cmds)
	{
		free(cmd[i].infile);
		free(cmd[i].outfile);
		free_array(cmd[i].av);
		i++;
	}
	free(cmd);
}
