/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:35:01 by reciak            #+#    #+#             */
/*   Updated: 2026/02/15 13:39:54 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file maestro_fun.c
 * @brief Stores the definition of maestro_fun()
 */

#include "philosophers.h"

/**
 * @brief The start function executed by the maestro thread
 * @note The "maestro" "signals" every philo when it is ok to grab forks.
 * @param[in, out] arg A pointer to an all struct
 * @return Allways `NULL`
 */

void *maestro_fun(void *arg)
{
	t_all			*all;
	t_squad_end		*squad_end;
	t_safe_init_cp	*sic;
	uint64_t		n;

	all = (t_all *) arg;
	squad_end = &all->squad_end;
	sic = &all->safe_init_cp;
	n = get_int64(&all->param.num_philos, sic->mutex);

	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
																			pthread_mutex_lock(&all->mutab.lock_log); printf("Dummy: Arrived in maestro_fun\n"); pthread_mutex_unlock(&all->mutab.lock_log);
	if (get_bool(&all->thread_span.creating_failed,
		all->thread_span.mutex) == false)
		return (NULL);
	
	return (NULL);
	
}
