/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:35:01 by reciak            #+#    #+#             */
/*   Updated: 2026/02/11 12:10:46 by reciak           ###   ########.fr       */
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
	t_all	*all;

	all = (t_all *) arg;

	pthread_mutex_lock(&all->mutab.lock_log);
	printf("Dummy: Arrived in maestro_fun\n");
	pthread_mutex_unlock(&all->mutab.lock_log);
	return (NULL);
}