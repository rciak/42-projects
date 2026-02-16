/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/16 18:08:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static void	set__values(int64_t *id, t_philo *phi, t_all *all);      //style: Rename to  set__most_values
//////////////////////////////////////////static bool	philos_do_what_philos_must_do(long *t_meal_start, long long *t_starved);

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
	t_time			*t;

	all = (t_all *) arg;
	set__values(&id, &phi, all);                                 // function name bad: phi.t does not get initialised there;
													             //   if it works with norm: outsource to own stack var t ?
	t = &phi.t;                                                  // refactor: mv t.init elsewhere?!
	set_bool(&all->thread_span.new_thread_copied_vars, true,
		all->thread_span.mutex);
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
	set_int64(&phi.t.init, all->thread_span.t_simulation_start,
		all->thread_span.mutex);
	if (get_bool(&all->thread_span.creating_failed,
		all->thread_span.mutex) == true)
		return (NULL);
	
	if (hope_for_meal(&phi, t) == false)
		return (NULL);
	// CHECK for end of sim


	// t_starved = all->t_0 + all->tt_die;
	// pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	// pthread_mutex_unlock(&all->mutab.lock_philos_till_start);

	// t_meal_start = hope_for_meal(all, t_starved);
	// if (t_meal_start >= t_starved || t_meal_start == END_SIMULATION)
	// 	return (NULL);
	// t_starved = t_meal_start + all->tt_die;
/////////////////////////////	while(philos_do_what_philos_must_do(all, &t_meal_start, &t_starved));


////////////////////////////////////////////////////////////////////////////////
// Temporary Code to test if maestro_fun gets ended on dead or enough pasta!
//
	if (id == 0)
	{
		set_int64(&all->squad_end.num_pasta_lovers, 0, all->squad_end.mutex);
	log_event(DEBUG_SIM_ENOUGH_PASTA, &phi);  // Nothing should show up
	pthread_mutex_lock(&all->mutab.lock_log); printf(YELLOW"No more pasta please!"RESET"\n"); pthread_mutex_unlock(&all->mutab.lock_log);
	}
	if (id == 1)
		log_event(DIED, &phi);
////////////////////////////////////////////////////////////////////////////////
	
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
	if (eat->end >= *t_starved || *t_meal_start == END_OF_SIMULATION)
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
	phi->left_hand = NULL;
	phi->right_hand = NULL;
	pthread_mutex_unlock(all->thread_span.mutex);
}
