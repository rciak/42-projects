/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:04:57 by reciak            #+#    #+#             */
/*   Updated: 2025/10/16 22:57:23 by reciak           ###   ########.fr       */
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
	size_t			j;
	t_parse_unit	*cmd;

	cmd = data.cmd;
	i = 0;
	while (i < data.n_cmds)
	{
		free(cmd[i].infile);
		free(cmd[i].outfile);
		j = 0;
		while (j < cmd->ac + 1)                                 // simpler use my free_array when everything works?!
		{
			free(cmd[i].av[j]);
			j++;
		}
		free (cmd[i].av);
		i++;
	}
	free(cmd);
}
