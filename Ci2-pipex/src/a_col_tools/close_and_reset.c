/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:48:37 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 10:28:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file close_and_reset.c
 * @brief Stores the definition of close_and_reset()
 */

#include "pipex.h"

/**
 * @brief Closes a non negative filedescriptor and sets it to -1 (== DO_NOT_USE)
 * @param[in,out] fd A pointer to a file descriptor
 * @return 
 *          * 0 on success
 *          * -1 if close fails or if fd < 0
 */
int	close_and_reset(int *fd, t_err *err)
{
	if (*fd < 0)
		return (set_err(err, E_NEGATIVE_FD, KEEP, "close_and_reset"), -1);
	if (close(*fd) == -1)
	{
		*fd = DO_NOT_USE;
		set_err(err, E_CLOSE_FAILED, errno, "close_and_reset");
		return (-1);
	}
	*fd = DO_NOT_USE;
	return (0);
}
