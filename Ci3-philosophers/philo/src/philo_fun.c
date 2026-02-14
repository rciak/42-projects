/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/02/14 23:05:15 by reciak           ###   ########.fr       */
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
	t_time			t;
	// long long		t_meal_start;
	int64_t			id;
	pthread_mutex_t *mutex;
	t_event			event[COUNT_EVENT_KINDS];

	all = (t_all *) arg;
	mutex = &all->mutab.lock_log;
	event[DIED] = (t_event){mutex, DIED};
	event[TAKE_FIRST_FORK] = (t_event){mutex, TAKE_FIRST_FORK};
	event[TAKE_SECOND_FORK_EAT] = (t_event){mutex, TAKE_SECOND_FORK_EAT};
	event[SLEEP] = (t_event){mutex, SLEEP};
event[DEBUG] = (t_event){mutex, DEBUG};
	event[THINK] = (t_event){mutex, THINK};
	

	//Copy id from main thread and inform waiting main thread, allowing to continue
	set_int64(&id, all->thread_span.id_cur_philo,
		all->thread_span.mutex);
	set_bool(&all->thread_span.copied_id_cur_philo, true,
		all->thread_span.mutex);
	pthread_mutex_lock(&all->mutab.lock_log);
	printf("\t\t\t\t\tDummy: philo_fun: %lu\n", id + 1);
	pthread_mutex_unlock(&all->mutab.lock_log);
t.starved = 0;
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	if (all->thread_span.creating_failed)
		return (NULL);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);

	log_event(event[DEBUG], id, t.starved, &all->squad_end);

//usleep(100000 - id * 100);
	if (id % 4 == 0)
	{
		log_event(event[TAKE_FIRST_FORK], id, t.starved, &all->squad_end);
		log_event(event[TAKE_SECOND_FORK_EAT], id, t.starved, &all->squad_end);
		//usleep(1000000);
	}
	if (id % 4 == 1)
	{
		log_event(event[SLEEP], id, t.starved, &all->squad_end);
		//usleep(1000000);
	}
	if (id % 4 == 2)
	{
		log_event(event[TAKE_FIRST_FORK], id, t.starved, &all->squad_end);
		log_event(event[TAKE_SECOND_FORK_EAT], id, t.starved, &all->squad_end);
		//usleep(1000000);
	}


	if (id == 198)
		log_event(event[DIED], id, t.starved, &all->squad_end);
	
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

