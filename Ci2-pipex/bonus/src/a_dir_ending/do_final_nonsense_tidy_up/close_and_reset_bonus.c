/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_reset_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:48:37 by reciak            #+#    #+#             */
/*   Updated: 2025/11/30 14:39:08 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file close_and_reset.c
 * @brief Stores the definition of close_and_reset()
 */

#include "pipex_bonus.h"

/**
 * @brief Closes a non negative filedescriptor and sets it to UNUSED (== -1 < 0)
 * @param[in,out] fd A pointer to a file descriptor
 */
void	close_and_reset(int *fd)
{
	if (*fd < 0)
	{
		out_str_fd(RED"Warning"RESET
			" - close_and_reset: ignore filedescriptor < 0 \n", STDERR_FILENO);
		return ;
	}
	if (*fd == STDIN_FILENO)
		out_str_fd(RED"Warning"RESET
			" - close_and_reset:closing standard fd for input", STDERR_FILENO);
	if (*fd == STDOUT_FILENO)
		out_str_fd(RED"Warning"RESET
			" - close_and_reset:closing standard fd for output", STDERR_FILENO);
	if (close(*fd) == -1)
	{
		out_str_fd(RED"Warning"RESET
			" - close_and_reset: close failed\n", STDERR_FILENO);
		return ;
	}
	*fd = UNUSED;
	return ;
}
