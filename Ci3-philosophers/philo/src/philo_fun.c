/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/11 12:38:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

//////////////////////////////////////////static bool	philos_do_what_philos_must_do(
//	t_philo *phi, long long *t_meal_start, long long *t_starved);

/**
 * @brief The usual start function executed by each philosopher thread
 * @note This start function is used for n >= 2 philosophers.
 *       For n == 1 philosophers see philo_alone_at_table()
 * @param[in, out] arg A pointer to an all struct
 * @return Allways `NULL`
 */
void	*philo_fun(void *arg)
{
	t_all			*all;
	// long long		t_starved;
	// long long		t_meal_start;
	int64_t			id;

	all = (t_all *) arg;
	set_int64(&id, all->thread_span.id_cur_philo, all->thread_span.mutex);
	pthread_mutex_lock(&all->mutab.lock_log);
	printf("Dummy: In philo_fun: %lu\n", id);
	pthread_mutex_unlock(&all->mutab.lock_log);
	// t_starved = all->t_0 + all->tt_die;
	// if (all->meals_at_least == 0)
	// 	return (NULL);
	// pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	// if (all->thread_span.creating_of_threads_failed)
	// 	return (NULL);
	// pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
	// t_meal_start = hope_for_meal(all, t_starved);
	// if (t_meal_start >= t_starved || t_meal_start == END_SIMULATION)
	// 	return (NULL);
	// t_starved = t_meal_start + all->tt_die;
/////////////////////////////	while(philos_do_what_philos_must_do(all, &t_meal_start, &t_starved));
	return (NULL);
}

/*
static bool	philos_do_what_philos_must_do(
	t_philo *phi, long long *t_meal_start, long long *t_starved)
{
	t_interval	eat;
	t_interval	sleep;
	t_interval	think;

	eat.start = *t_meal_start;
	eat.end = wait_till(eat.start + phi->tt_eat, phi, *t_starved);
	ensure__forks_on_table(phi);
	if (eat.end >= *t_starved || *t_meal_start == END_OF_SIMULATION)
		return (false);
	sleep.start = init_sleep(phi, *t_starved);
	sleep.end = wait_till(sleep.start + phi->tt_sleep, phi, *t_starved);
	if (sleep.end >= *t_starved || sleep.end == END_OF_SIMULATION)
		return (false);
	think.start = init_thinking(phi, *t_starved);
	think.end = hope_for_meal(phi, *t_starved);
	if (think.end >= *t_starved || think.end == END_OF_SIMULATION)
		return (false);
	*t_meal_start = think.end;
	*t_starved = *t_meal_start + phi->tt_die;
	return (true);
}
*////////////////////////////

