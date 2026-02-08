/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create__philo_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:51:08 by reciak            #+#    #+#             */
/*   Updated: 2026/02/08 11:26:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create__philo_threads.c
 * @brief Stores the definition of create__philo_threads()
 */

#include "philosophers.h"

static void	set__philo_vars_except_thread_val_and_t_0(long long i, t_phi *phi);
static bool	create__single_philo_thread(long long i, t_phi *phi);
static void	set__philo_var_t_0(t_phi *phi);

/**
 * @brief Creates the philosopher threads and inits the philo array
 * @note Each thread is detached immediately after creation
 * @note Each philosopher's ID is set to its index + 1
 * @note latest_meal is intentionally left **uninitialized** here
 * @param[out] code A pointer for storing error codes
 * @param[in,out] phi A pointer to the all-encompassing struct
 * @return
 *          * true if all threads were created successfully
 *          * false if an error occurred (code is set accordingly)
 */
bool	create__philo_threads(t_phi *phi, t_ecode *code)
{
	bool		reval;
	long long	i;

	reval = true;
	pthread_mutex_lock(&phi->lock_philos_till_start);
	i = 0;
	while (i < phi->param.num_philos)
	{
		set__philo_vars_except_thread_val_and_t_0(i, phi);
		if (!create__single_philo_thread(i, phi))
		{
			*code = E_THREAD_CREATE;
			reval = false;
			break;
		}
		i++;
	}
	set__philo_var_t_0(phi);
	pthread_mutex_unlock(&phi->lock_philos_till_start);
	return (reval);
}

static void	set__philo_vars_except_thread_val_and_t_0(long long i, t_phi *phi)
{
	phi->philo[i].id = i + 1;
	phi->philo[i].perm = &phi->perm;
	phi->philo[i].lock_philos_till_start = &phi->lock_philos_till_start;
	phi->philo[i].dead = &phi->dead;
	phi->philo[i].lock_dead = &phi->lock_dead;
	phi->philo[i].still_love_pasta = &phi->still_loving_pasta;
	phi->philo[i].lock_still_love_pasta = &phi->lock_still_love_pasta;
	phi->philo[i].end_simul = &phi->end_simul;
	phi->philo[i].lock_end_simul = &phi->lock_end_simul;
	phi->philo[i].ended_meals = 0;
	phi->philo[i].num_philos = phi->param.num_philos;
	phi->philo[i].tt_die = phi->param.tt_die;
	phi->philo[i].tt_eat = phi->param.tt_eat;
	phi->philo[i].tt_sleep = phi->param.tt_sleep;
	phi->philo[i].meals_at_least = phi->param.meals_at_least;
}

static bool	create__single_philo_thread(long long i, t_phi *phi)
{
	void		*(*start_function)(void *);

	if (phi->param.num_philos == 1)
		start_function = &philo_alone_at_table;
	else
		start_function = &philo_fun;
	if (0 != pthread_create(&phi->philo[i].thread, NULL, start_function,
			(void *)(phi->philo + i)))
		return (false);
	return (true);
}

static void	set__philo_var_t_0(t_phi *phi)
{
	long long	simulation_start;
	long long	i;

	simulation_start = gettimeofday_musec();
	i = 0;
	while (i < phi->param.num_philos)
	{
		phi->philo[i].t_0 = simulation_start;
		i++;
	}
}
