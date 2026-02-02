/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/02 12:57:46 by reciak           ###   ########.fr       */
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
//																			printf("Philo %lld ready at **** us\n", philo->id);
																			//printf("Philo %lld ready at %lld us\n", philo->id, timestamp);
//																			printf("Philo **** ready at %lld us\n", timestamp);
	pthread_mutex_lock(philo->lock_dead);
	if ((id == 142 || id == 143 || id == 144) && *philo->dead == NO_DEAD)
	{
																			printf(RED"philo %lld died at %lld us"RESET"\n", philo->id, timestamp);
		*philo->dead = id;
	}
	else if (*philo->dead == NO_DEAD)
	{	
																			printf(GREEN"philo %lld at %lld us"RESET"\n", philo->id, timestamp);
	}
	pthread_mutex_unlock(philo->lock_dead);
	return (NULL);
}


