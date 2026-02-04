/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create__philo_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:51:08 by reciak            #+#    #+#             */
/*   Updated: 2026/02/04 15:01:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create__philo_threads.c
 * @brief Stores the definition of create__philo_threads()
 */

#include "philosophers.h"

static void	set__philo_vars_except_thread_val_and_t_0(long long i, t_all *all);
static bool	create__single_philo_thread(long long i, t_all *all);
static void	set__philo_var_t_0(t_all *all);

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
bool	create__philo_threads(t_all *all, t_ecode *code)
{
	bool		reval;
	long long	i;

	reval = true;
	pthread_mutex_lock(&all->lock_philos_till_start);
	i = 0;
	while (i < all->param.num_philos)
	{
		set__philo_vars_except_thread_val_and_t_0(i, all);
		if (!create__single_philo_thread(i, all))
		{
			*code = E_THREAD_CREATE;
			reval = false;
			break;
		}
		i++;
	}
	set__philo_var_t_0(all);
	pthread_mutex_unlock(&all->lock_philos_till_start);
	return (reval);
}

static void	set__philo_vars_except_thread_val_and_t_0(long long i, t_all *all)
{
	all->philo[i].id = i + 1;
	all->philo[i].perm = &all->perm;
	all->philo[i].lock_philos_till_start = &all->lock_philos_till_start;
	all->philo[i].dead = &all->dead;
	all->philo[i].lock_dead = &all->lock_dead;
	all->philo[i].ended_meals = 0;
	all->philo[i].tt_die = all->param.tt_die;
	all->philo[i].tt_eat = all->param.tt_eat;
	all->philo[i].tt_sleep = all->param.tt_sleep;
	all->philo[i].meals_at_least = all->param.meals_at_least;
}

static bool	create__single_philo_thread(long long i, t_all *all)
{
	void		*(*start_function)(void *);

	if (all->param.num_philos == 1)
		start_function = &philo_alone_at_table;
	else
		start_function = &philo_fun;
	if (0 != pthread_create(&all->philo[i].thread, NULL, start_function,
			(void *)(all->philo + i)))
		return (false);
	return (true);
}

static void	set__philo_var_t_0(t_all *all)
{
	long long	simulation_start;
	long long	i;

	simulation_start = gettimeofday_musec();
	i = 0;
	while (i < all->param.num_philos)
	{
		all->philo[i].t_0 = simulation_start;
		i++;
	}
}
