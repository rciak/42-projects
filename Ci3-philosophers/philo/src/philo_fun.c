/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/22 01:39:53 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static void	set__values(int64_t *id, t_philo *phi, t_all *all);      //style: Rename to  set__most_values
static void	run__philo_cycle(t_philo *phi);
static bool may___take_forks(bool *perm, t_philo *phi);
static bool i___m_alive(t_philo *phi);

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
	int64_t			id;
	t_philo			phi;

	all = (t_all *) arg;
	set__values(&id, &phi, all);                                                 // function name bad: phi.t does not get initialised there; if it works with norm: outsource to own stack var t ?
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

static void	set__values(int64_t *id, t_philo *phi, t_all *all)
{
	// Not yet set VARS: 
	//  t;
	pthread_mutex_lock(all->thread_span.mutex);
	*id = all->thread_span.id_cur_philo;                                          //refactor leftover id away; phi->id is sufficient
	phi->id = all->thread_span.id_cur_philo;
	phi->t.init = all->thread_span.t_simulation_start;
	phi->t.starved = phi->t.init + all->param.tt.die;
	phi->tt = all->param.tt;
	phi->meals.eaten = 0;
	phi->meals.min = all->param.meals_at_least;
	phi->maestro = &all->maestro;
	phi->squad_end = &all->squad_end;
	phi->lock_log = &all->mutab.lock_log;
	if (*id == 0)
	{
		phi->left_fork = &all->mutab.fork[all->param.num_philos - 1];
		phi->right_fork = &all->mutab.fork[0];
	}
	else
	{
		phi->left_fork = &all->mutab.fork[*id - 1];
		phi->right_fork = &all->mutab.fork[*id];
	}
	pthread_mutex_unlock(all->thread_span.mutex);
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
		log_event(THINK, phi);
		while(i___m_alive(phi) && !time_to_say_goodbye(squad_end)
				&& !may___take_forks(perm, phi))
			usleep(TIME_TILL_NEXT_FORK_CHECK);

if (phi->id % 2 == 0)
{
	pthread_mutex_lock(phi->right_fork);
	log_event(TAKE_FIRST_FORK, phi);
	pthread_mutex_lock(phi->left_fork);
	log_event(TAKE_SECOND_FORK, phi);
	log_event(EAT, phi);
	pthread_mutex_unlock(phi->left_fork);
	pthread_mutex_unlock(phi->right_fork);
}
else
{
	pthread_mutex_lock(phi->left_fork);
	log_event(TAKE_FIRST_FORK, phi);
	pthread_mutex_lock(phi->right_fork);
	log_event(TAKE_SECOND_FORK, phi);
	log_event(EAT, phi);
	pthread_mutex_unlock(phi->right_fork);
	pthread_mutex_unlock(phi->left_fork);
}

		//bool shall_take_forks;
		// take_forks = i___m_alive(phi) && !time_to_say_goodbye(squad_end);
		// if (shall_take_forks)
		//		Take 1. fork
		//		Take 2. fork

		


		// if (shall_take_forks)
		//Release fork 2
		//Release fork 1
		set_bool(&phi->maestro->allows[phi->id], false, phi->maestro->mutex);
		
		log_event(SLEEP, phi);
	}
	if (i___m_alive(phi) == false)
		log_event(DIED, phi);
}

static bool may___take_forks(bool *perm, t_philo *phi)
{
	return (get_bool(perm, phi->maestro->mutex));
}

static bool i___m_alive(t_philo *phi)
{
	int64_t	timestamp;

	timestamp = gettimeofday_musec();
	if (timestamp < phi->t.starved)
		return (true);
	return (false);
}
