/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create__philo_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:51:08 by reciak            #+#    #+#             */
/*   Updated: 2026/01/16 17:18:04 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create__philo_threads.c
 * @brief Stores the definition of create__philo_threads()
 */

#include "philosophers.h"

/**
 * @brief Creates the philosopher threads and inits the philo array
 * @note Each thread is detached immediately after creation
 * @note Each philosopher's ID is set to its index + 1
 * @note latest_meal is intentionally left **uninitialized** here
 * @param[out] code A pointer for storing error codes
 * @param[in,out] all A pointer to the all-encompassing struct
 * @return
 *          * true if all threads were created successfully
 *          * false if an error occurred (code is set accordingly)
 */
bool	create__philo_threads(t_all *all, t_ecode *code)
{
	long long	i;
	bool		reval;

	pthread_mutex_lock(&all->lock_philos_till_start);
	reval = true;
	i = 0;
	while (i < all->param.num_philos)
	{
		all->philo[i].id = i + 1;
		all->philo[i].perm = &all->perm;
		all->philo[i].lock_philos_till_start = &all->lock_philos_till_start;
		all->philo[i].dead = &all->dead;
		all->philo[i].lock_dead = &all->lock_dead;
		// all->philo[i].latest_meal = ; INTENTIONALLY LEFT UNINITIALIZED    !!!!
		all->philo[i].ended_meals = 0;
		if (pthread_create(&all->philo[i].thread, NULL,
				&philo_fun, (void *)(all->philo + i)) != 0)
		{
			*code = E_THREAD_CREATE;
			reval = false;
			break;
		}
		if (pthread_detach(all->philo[i].thread) != 0)
		{
			*code = E_THREAD_DETACH;
			reval = false;
			break;
		}
		i++;
	}
	usleep(MAX_TIME_BIRTH_PHILO * all->param.num_philos);					//Dummy: Better were let philos set variable that they are ready
	pthread_mutex_unlock(&all->lock_philos_till_start);
	return (reval);
}

