/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/05 17:46:02 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static bool	philos_do_what_philos_must_do(
	t_philo *phi, long long *t_meal_start, long long *t_starved);

/**
 * @brief The usual start function executed by each philosopher thread
 * @note This start function is used for n >= 2 philosophers.
 *       For n == 1 philosophers see philo_alone_at_table()
 * @param[in, out] arg A pointer to a philo struct
 * @return Allways `NULL`
 */
void	*philo_fun(void *arg)
{
	t_philo			*phi;
	long long		t_starved;
	long long		t_meal_start;

	phi = (t_philo *)arg;
	pthread_mutex_lock(phi->lock_philos_till_start);
	pthread_mutex_unlock(phi->lock_philos_till_start);
	if (phi->meals_at_least == 0)
		return (NULL);
	t_starved = phi->t_0 + phi->tt_die;
	t_meal_start = hope_for_meal(phi, t_starved);
	if (t_meal_start >= t_starved)
		return (NULL);
	t_starved = t_meal_start + phi->tt_die;
	while(philos_do_what_philos_must_do(phi, &t_meal_start, &t_starved));
	return (NULL);
}

static bool	philos_do_what_philos_must_do(
	t_philo *phi, long long *t_meal_start, long long *t_starved)
{
	t_interval	eat;
	t_interval	sleep;
	t_interval	think;

	eat.start = *t_meal_start;
	eat.end = wait__till(eat.start + phi->tt_eat, phi, *t_starved);
	ensure__forks_on_table(phi);
	if (eat.end >= *t_starved)
		return (false);
	sleep.start = init__sleep(phi, *t_starved);
	sleep.end = wait__till(sleep.start + phi->tt_sleep, phi, *t_starved);
	if (sleep.end >= *t_starved)
		return (false);
	think.start = init__thinking(phi, *t_starved);
	think.end = hope_for_meal(phi, *t_starved);
	if (think.end >= *t_starved)
		return (false);
	*t_meal_start = think.end;
	*t_starved = *t_meal_start + phi->tt_die;
	return (true);
}


