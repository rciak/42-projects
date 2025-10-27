/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidy_up_all_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:04:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 16:11:05 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file tidy_up_all_cmds.c
 * @brief Stores the definition of tidy_up_all_cmds()
 */

#include "pipex.h"

/**
 * @brief A general tidy up function
 * @warning This is quite nonsense since this function is called before exiting;
 *          Since this program is not made for embedded systems but for
 *          "usual" systems where the OS will automatically take care of
 *          cleaning after exiting. I hope it does at least not turn good
 *          bugs into bad (hard to detect) bugs...)
 * @param[in] num_cmds The number of commands
 * @param[in] cmd Pointing to an array of command struct instances
 * @param[in] err Pointing to error struct instance
 */
void	tidy_up_all_cmds(size_t num_cmds, t_cmd *cmd, t_err *err)
{	
	size_t	i;
	
	i = 0;
	while (i < num_cmds)
	{
		cmd[i].ac = 0;
		free_array_and_reset(&cmd[i].av);
		free_array_and_reset(&cmd[i].path);
		free_and_reset(&cmd[i].infile);
		free_and_reset(&cmd[i].outfile);
		close_and_reset(&cmd[i].fd_in, err);
		close_and_reset(&cmd[i].fd_out, err);
		i++;
	}
}
