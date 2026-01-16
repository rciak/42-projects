/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/01/16 12:33:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

/**
 * @brief The start function executed by each philosopher thread
 * @param[in, out] arg A pointer to a philo struct
 * @return Allways `NULL` (all philo threads are anyway detached ...)
 */
void	*philo_fun(void *arg)
{
	t_philo			*philo;
	long long		id;

	philo = (t_philo *)arg;
	id = philo->id;
	pthread_mutex_lock(philo->lock_philos_till_start);
	pthread_mutex_unlock(philo->lock_philos_till_start);
																			long long timestamp = gettimeofday_musec();
																			usleep (10* id);
																			printf("Philo %lld ready at %lld us\n", philo->id, timestamp);

	return (NULL);
}


