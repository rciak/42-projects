/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create__philo_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:51:08 by reciak            #+#    #+#             */
/*   Updated: 2026/01/13 12:12:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create__philo_threads.c
 * @brief Stores the definition of create__philo_threads()
 */

#include "philosophers.h"

/**
 * @brief Creates the philosopher threads and inits the philo array
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
bool	create__philo_threads(t_all *all, t_ecode *code)
{
	long long	i;

	i = 0;
	while (i < all->param.num_philos)
	{
		if (pthread_create(&all->philo[i].thread, NULL, &philo_fun, all) != 0)
		{
			*code = E_THREAD_CREATE;
			return (false);
		}
		if (pthread_detach(&all->philo[i].thread) != 0)
		{
			*code = E_THREAD_DETACH;
			return (false);
		}
		all->philo[i].id = i + 1;
		// all->philo[i].latest_meal = ;
		all->philo[i].ended_meals = 0;
		i++;		
	}
	return (true);
}
