/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:29 by reciak            #+#    #+#             */
/*   Updated: 2026/02/21 15:45:59 by reciak           ###   ########.fr       */
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
	
	while (1)
	{
		timestamp = gettimeofday_musec();
		if (t_stop < timestamp
			|| get_bool(&s_end->starved, s_end->mutex) == true
			|| get_int64(&s_end->num_pasta_lovers, s_end->mutex) == 0)
			return (gettimeofday_musec());
		if (t_stop - timestamp < TIME_TILL_NEXT_END_OF_SIMUL_CHECK)
			wait_for(t_stop - timestamp);
		else
			wait_for(TIME_TILL_NEXT_END_OF_SIMUL_CHECK);
	}
}
