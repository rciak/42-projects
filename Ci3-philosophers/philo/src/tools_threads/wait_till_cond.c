/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till_cond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:55:30 by reciak            #+#    #+#             */
/*   Updated: 2026/02/16 00:53:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_till_cond.c
 * @brief Stores the definition of wait_till_cond()
 */

#include "philosophers.h"

/**
 * @brief Waits till a condition is has been meet, then
 *        resfreshes then the state for reuse
 */
void	wait_till_cond(bool *state, bool wanted, pthread_mutex_t *mtx, int act)
{
	int64_t		duration;
	bool		local_state;

	duration = 200;
	local_state = !wanted;
	while (local_state != wanted)
	{
		pthread_mutex_lock(mtx);
		local_state = *state;
		pthread_mutex_unlock(mtx);
		usleep(duration);
	}
	if (act == RESET_STATE)
	{
		pthread_mutex_lock(mtx);
		*state = !wanted;
		pthread_mutex_unlock(mtx);
	}
}
