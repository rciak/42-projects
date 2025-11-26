/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_final_nonsense_tidy_up.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:51:22 by reciak            #+#    #+#             */
/*   Updated: 2025/11/26 08:40:23 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file do_final_nonsense_tidy_up.c
 * @brief Stores the definition of do_final_nonsense_tidy_up()
 */

#include "pipex.h"

/**
 * @brief Free allocated memory, close open filedescriptors...
 * @note Since pipex is intended to be executed only on system where the 
 *       operating system will clean up anyway when the program ends
 *       this feels somewhat like overkill...
 * @param[in,out] data
 */

void	do_final_nonsense_tidy_up(t_data *data)
{
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		tidy_up_and_reset_cmd_items(&data->cmd[i]);
		i++;
	}
	free (cmd);
	free_array_and_reset(&data->path);
}

/**
 * @brief For tidying up /resetting the items of a command struct instance.
 * @warning This is quite nonsense since this function is called before exiting;
 *          Since this program is not made for embedded systems but for
 *          "usual" systems where the OS will automatically take care of
 *          cleaning after exiting. I hope it does at least not turn good
 *          bugs into bad (hard to detect) bugs...)
 * @param[in] cmd Pointing to command struct instances
 */
static void	tidy_up_and_reset_cmd_items(t_cmd *cmd)
{
	cmd->ac = 0;
	if (cmd->av != NULL)
		free_array_and_reset(&cmd->av);
	if (cmd->pathname != NULL)
		free_and_reset(&cmd->pathname);
	if (cmd->infile != NULL)
		free_and_reset(&cmd->infile);
	if (cmd->outfile != NULL)
		free_and_reset(&cmd->outfile);
	if (cmd->fd_in >= 0)
		close_and_reset(&cmd->fd_in, err);
	if (cmd->fd_out >= 0)
		close_and_reset(&cmd->fd_out, err);
	cmd->pid == UNUSED;
}
