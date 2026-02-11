/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:04:38 by reciak            #+#    #+#             */
/*   Updated: 2026/02/10 18:46:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_for.c
 * @brief Stores the definition of wait_for()
 */

#include "philosophers.h"

/**
 * @brief Tries to let elapse the requested time in microseconds
 * @note Should hopefully be way more precise than usleep
 *       (which is used only to reduce load on the CPU)
 * @param[in] time_span The time to elapse in microseconds
 */
void	wait_for(int64_t time_span)
{
	int64_t		start;
	int64_t		end;
	char		*warning;

	start = gettimeofday_musec();
	end = start + time_span;
	warning = "WARNING: wait_for received a negative timespan";
	if (time_span < 0)
		write(STDERR_FILENO, warning, ft_strlen(warning));
	usleep (time_span * FACTOR_USLEEP_WAIT_FOR);
	while (gettimeofday_musec() < end);
}
