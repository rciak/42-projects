/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:29 by reciak            #+#    #+#             */
/*   Updated: 2026/02/27 12:26:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_till.c
 * @brief Stores the definition of wait_till()
 */

#include "philosophers.h"

/**
 * @brief Wait till the specified time (in microseconds since the epoch) is over
 *        or till a simulation ending event had happened.
 * @warning The caller must have no lock on the mutex of `s_end` !
 */
int64_t	wait_till(int64_t t_stop, t_squad_end *s_end)
{
	int64_t	timestamp;
	int64_t	waiting_time;

	while (true)
	{
		timestamp = gettimeofday_musec();
		waiting_time = t_stop - timestamp;
		if (waiting_time <= 0
			|| get_bool(&s_end->starved, s_end->mutex) == true
			|| get_int64(&s_end->num_pasta_lovers, s_end->mutex) == 0)
			return (gettimeofday_musec());
		if (waiting_time < THRESHOLD_SWITCH_TO_BUSY_WAIT)
			break;
		usleep(waiting_time * USLEEP_FACTOR_WAIT_TILL);
	}
	if (waiting_time <= 0)
		return (timestamp);
	while (waiting_time > 0 
		&& get_bool(&s_end->starved, s_end->mutex) == false
		&& get_int64(&s_end->num_pasta_lovers, s_end->mutex) > 0)
		waiting_time = t_stop - gettimeofday_musec();
	return (gettimeofday_musec());
}
