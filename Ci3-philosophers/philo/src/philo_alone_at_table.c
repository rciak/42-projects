/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alone_at_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:30:01 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 16:55:31 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_alone_at_table.c
 * @brief Stores the definition of philo_alone_at_table()
 */

#include "philosophers.h"

static void	run__single_philo_tragedy(t_philo *phi);

/**
* @brief The start function for the edge case of only one philosopher thread.
* @note For n >= 2 philosophers the start function is philo_fun()
* @param[in, out] arg A pointer to a philo struct
* @return Allways `NULL`
*/
void	*philo_alone_at_table(void *arg)
{
	t_all			*all;
	t_philo			phi;

	all = (t_all *) arg;
	set_values(&phi, all);
	set_bool(&all->thread_span.new_thread_copied_vars, true,
		all->thread_span.mutex);
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
	set_int64(&phi.t.init, all->thread_span.t_simulation_start,
		all->thread_span.mutex);
	if (get_bool(&all->thread_span.creating_failed,
			all->thread_span.mutex) == true)
		return (NULL);
	run__single_philo_tragedy(&phi);
	return (NULL);
}

static void	run__single_philo_tragedy(t_philo *phi)
{
	t_time		*t;
	t_time_to	*tt;

	t = &phi->t;
	tt = &phi->tt;
	t->starved = t->init + tt->die;
	treat_event(THINK, phi);
	treat_event(TAKE_FIRST_FORK, phi);
	wait_till(phi->t.starved, phi->squad_end);
	treat_event(DIED, phi);
}
