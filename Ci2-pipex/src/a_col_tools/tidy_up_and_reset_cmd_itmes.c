/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidy_up_and_reset_cmd_itmes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:03:31 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 18:39:10 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file tidy_up_and_reset_cmd_itmes.c
 * @brief Stores the definition of tidy_up_and_reset_cmd_itmes()
 */

#include "pipex.h"

/**
 * @brief For tidying up /resetting the items of a command struct instance.
 * @warning This is quite nonsense since this function is called before exiting;
 *          Since this program is not made for embedded systems but for
 *          "usual" systems where the OS will automatically take care of
 *          cleaning after exiting. I hope it does at least not turn good
 *          bugs into bad (hard to detect) bugs...)
 * @param[in] num_cmds The number of commands
 * @param[in] cmd Pointing to command struct instances
 * @param[in] err Pointing to error struct instance
 */
void	tidy_up_and_reset_cmd_items(t_cmd *cmd, t_err *err)
{	
	cmd->ac = 0;
	free_array_and_reset(&cmd->av);
	free_array_and_reset(&cmd->path);
	free_and_reset(&cmd->infile);
	free_and_reset(&cmd->outfile);
	if (cmd->fd_in >= 0)
		close_and_reset(&cmd->fd_in, err);
	if (cmd->fd_out >= 0)
		close_and_reset(&cmd->fd_out, err);
}
