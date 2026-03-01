/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create__threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:51:08 by reciak            #+#    #+#             */
/*   Updated: 2026/02/10 17:46:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create__threads.c
 * @brief Stores the definition of create__threads()
 */

#include "philosophers.h"

static bool	create__maestro_thread(t_all *all, t_ecode *code);
static bool	create__philo_threads(t_all *all, t_ecode *code);
static bool	create___single_philo_thread(int64_t i, t_all *all);
static void	clear__threads(int64_t i, t_all *all);

/**
 * @brief Creates the philosopher threads and inits the philo array
 * @note Each thread is detached immediately after creation
 * @note Each philosopher's ID is set to its index + 1
 * @note latest_meal is intentionally left **uninitialized** here
 * @param[out] code A pointer for storing error codes
 * @param[in,out] all A pointer to the all-encompassing struct
 * @return
 *          * true if all threads were created successfully
 *          * false if an error occurred (code is set accordingly)
 */
bool	create_threads(t_all *all, t_ecode *code)
{
	bool	reval;
	
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	if (!create__maestro_thread(all, code))
		return (false);
	set_bool(&all->thread_span.creating_failed, false,
		all->thread_span.mutex);
	reval =	create__philo_threads(all, code);
	all->thread_span.t_simulation_start = gettimeofday_musec();

// XXX usleep ?!

	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
	return (reval);
}
static bool	create__maestro_thread(t_all *all, t_ecode *code)
{
	if (0 != pthread_create(&all->thread_span.maestro_thread, NULL,	maestro_fun,
			(void *) all))
	{
		*code = E_THREAD_CREATE;
		return (false);
	}
	return (true);
}

static bool	create__philo_threads(t_all *all, t_ecode *code)
{
	int64_t	i;
	
	i = 0;
	while (i < all->param.num_philos)
	{
		set_int64(&all->thread_span.id_cur_philo, i,
			all->thread_span.mutex);
		set_bool(&all->thread_span.new_thread_copied_vars, false,
			all->thread_span.mutex);
		if (!create___single_philo_thread(i, all))
		{
			set_bool(&all->thread_span.creating_failed, true,
				all->thread_span.mutex);
			clear__threads(i, all);
			*code = E_THREAD_CREATE;
			return (false);
		}
		wait_till_cond(&all->thread_span.new_thread_copied_vars, true,
			all->thread_span.mutex, RESET_STATE);
		i++;
	}
	return (true);
}

static bool	create___single_philo_thread(int64_t i, t_all *all)
{
	void		*(*start_function)(void *);

	if (all->param.num_philos == 1)
		start_function = &philo_alone_at_table;
	else
		start_function = &philo_fun;
	if (0 != pthread_create(&all->thread_span.philo_thread[i], NULL, start_function,
			(void *)all))
		return (false);
	return (true);
}

static void	clear__threads(int64_t i, t_all *all)
{
	pthread_join(all->thread_span.maestro_thread, NULL);
	while (i-- > 0)
		pthread_join(all->thread_span.philo_thread[i], NULL);
}
