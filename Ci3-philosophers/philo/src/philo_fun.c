/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 17:09:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static void	run__philo_cycle(t_philo *phi);
static void	dine___with_forks(t_philo *phi);
static bool	i___m_alive(t_philo *phi);

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
	t_squad_end	*squad_end;
	bool		*perm;
	t_time		*t;
	t_time_to	*tt;

	squad_end = phi->squad_end;
	perm = &phi->maestro->allows[phi->id];
	t = &phi->t;
	tt = &phi->tt;
	t->starved = t->init + tt->die;
	while (i___m_alive(phi) && !time_to_say_goodbye(squad_end))
	{
		treat_event(THINK, phi);
		while (i___m_alive(phi) && !time_to_say_goodbye(squad_end)
			&& get_bool(perm, phi->maestro->mutex) == false)
			usleep(TIME_TILL_NEXT_FORK_CHECK);
		dine___with_forks(phi);
		set_bool(perm, false, phi->maestro->mutex);
		treat_event(SLEEP, phi);
	}
	if (i___m_alive(phi) == false)
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

static bool	i___m_alive(t_philo *phi)
{
	int64_t	timestamp;

	timestamp = gettimeofday_musec();
	if (timestamp < phi->t.starved)
		return (true);
	return (false);
}
