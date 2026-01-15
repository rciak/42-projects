/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/01/15 16:05:34 by reciak           ###   ########.fr       */
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
wait_for(300 * id);
printf("Philo %lld \t wants %lld \n", id, 4000 * id );
long long start = gettimeofday_musec();
wait_for(4000 * id);
long long end = gettimeofday_musec();
printf("                                  Philo %lld : %lld \n", id, end - start);

	return (NULL);
}


