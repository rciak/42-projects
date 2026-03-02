/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/03/02 23:35:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static void	run__philo_cycle(t_philo *phi);
static void	dine___with_forks(t_philo *phi);

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
	run__philo_cycle(&phi);
	return (NULL);
}

static void	run__philo_cycle(t_philo *phi)
{
	t_squad_end		*squad_end;
	bool			*perm;
	pthread_mutex_t	*mutex;
	t_time			*t;
	
	squad_end = phi->squad_end;
	perm = &phi->maestro->allows[phi->id];
	mutex = phi->maestro->mutex;
	t = &phi->t;
	t->starved = t->init + phi->tt.die;
	while (now() < t->starved && !time_to_say_goodbye(squad_end))
	{
		//if (get_bool(perm, mutex) == false)                                               //Check after return to campus: Works better or worse with this if condition ? Ask peers if they would regard a eat|sleep|eat NO_THINK|sleep|eat... as feasible / conform to the subject
			treat_event(THINK, phi);
		while (get_bool(perm, mutex) == false
			&& now() < t->starved && !time_to_say_goodbye(squad_end))
			usleep(TIME_TILL_NEXT_FORK_CHECK);
		if (now() < t->starved && !time_to_say_goodbye(squad_end))                          //Check also if  get_bool(perm, mutex) == true  works better
			dine___with_forks(phi);
		set_bool(perm, false, mutex);
		treat_event(SLEEP, phi);
	}
	if (now() >= t->starved)
		treat_event(DIED, phi);
}

static void	dine___with_forks(t_philo *phi)
{
	if (phi->id % 2 == 0)
	{
		pthread_mutex_lock(phi->right_fork);
		treat_event(TAKE_FIRST_FORK, phi);
		pthread_mutex_lock(phi->left_fork);
		treat_event(TAKE_SECOND_FORK, phi);
		treat_event(EAT, phi);
		pthread_mutex_unlock(phi->left_fork);
		pthread_mutex_unlock(phi->right_fork);
	}
	else
	{
		pthread_mutex_lock(phi->left_fork);
		treat_event(TAKE_FIRST_FORK, phi);
		pthread_mutex_lock(phi->right_fork);
		treat_event(TAKE_SECOND_FORK, phi);
		treat_event(EAT, phi);
		pthread_mutex_unlock(phi->right_fork);
		pthread_mutex_unlock(phi->left_fork);
	}
}

