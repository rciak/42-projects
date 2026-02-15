/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/15 21:56:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

static void	init__vars(int64_t *id, t_philo *phi, t_all *all);
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
	t_philo			phi;
	t_time			*t;
	int64_t			id;

	t_event			event[COUNT_EVENT_KINDS];

	all = (t_all *) arg;
	t = &phi.t;
	init__vars(&id, &phi, all);
	//Copy id from main thread and inform waiting main thread, allowing to continue
	set_bool(&all->thread_span.new_thread_copied_vars, true,
		all->thread_span.mutex);                                  //CAUTION: NEED EXTENSION LATER

	pthread_mutex_t *mutex;
	mutex = &all->mutab.lock_log;
	event[DIED] = (t_event){mutex, DIED};
	event[TAKE_FIRST_FORK] = (t_event){mutex, TAKE_FIRST_FORK};
	event[TAKE_SECOND_FORK_EAT] = (t_event){mutex, TAKE_SECOND_FORK_EAT};
	event[SLEEP] = (t_event){mutex, SLEEP};
	event[THINK] = (t_event){mutex, THINK};
event[DEBUG] = (t_event){mutex, DEBUG};
event[DEBUG_SIM_ENOUGH_PASTA] = (t_event){mutex, DEBUG_SIM_ENOUGH_PASTA};

pthread_mutex_lock(&all->mutab.lock_log); printf("\t\t\t\t\tBefore Sim: philo_fun: %lu\n", id + 1); pthread_mutex_unlock(&all->mutab.lock_log);
t->starved = 0;
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
//	log_event(event[DEBUG], id, t->starved, &all->squad_end);
//pthread_mutex_lock(&all->mutab.lock_log); printf("\t\t\t\t\tSim go: philo_fun: %lu\n", id + 1); pthread_mutex_unlock(&all->mutab.lock_log);
	
	if (get_bool(&all->thread_span.creating_failed,
		all->thread_span.mutex) == true)
		return (NULL);

//usleep(100000 - id * 100);
	if (id % 4 == 0)
	{
		log_event(event[TAKE_FIRST_FORK], id, t->starved, &all->squad_end);
		log_event(event[TAKE_SECOND_FORK_EAT], id, t->starved, &all->squad_end);
		//usleep(1000000);
	}
	if (id % 4 == 1)
	{
		log_event(event[SLEEP], id, t->starved, &all->squad_end);
		//usleep(1000000);
	}
	if (id % 4 == 2)
	{
		log_event(event[TAKE_FIRST_FORK], id, t->starved, &all->squad_end);
		log_event(event[TAKE_SECOND_FORK_EAT], id, t->starved, &all->squad_end);
		//usleep(1000000);
	}

usleep(10000);

//
// Temporary Code to test if maestro_fun gets ended on dead or enough pasta!
//
	if (id == 0)
	{
 		set_int64(&all->squad_end.num_pasta_lovers, 0, all->squad_end.mutex);
log_event(event[DEBUG_SIM_ENOUGH_PASTA], id, t->starved, &all->squad_end);  // Nothing should show up
pthread_mutex_lock(&all->mutab.lock_log); printf(YELLOW"No more pasta please!"RESET"\n"); pthread_mutex_unlock(&all->mutab.lock_log);
	}
	if (id == 1)
		log_event(event[DIED], id, t->starved, &all->squad_end);

		


		
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



static void	init__vars(int64_t *id, t_philo *phi, t_all *all)
{
	int64_t	n;

	pthread_mutex_lock(all->thread_span.mutex);
	*id = all->thread_span.id_cur_philo;
	phi->tt = all->param.tt;
	phi->meals.eaten = 0;
	phi->meals.min = all->param.meals_at_least;
	phi->maestro = &all->maestro;
	phi->squad_end = &all->squad_end;
	n = all->param.num_philos;
	if (*id == 0)
	{
		phi->left_fork = &all->mutab.fork[n - 1];
		phi->right_fork = &all->mutab.fork[0];
	}
	else
	{
		phi->left_fork = &all->mutab.fork[*id - 1];
		phi->right_fork = &all->mutab.fork[*id];
	}

	pthread_mutex_unlock(all->thread_span.mutex);
}

// UNSET VARS: 
//  t;

