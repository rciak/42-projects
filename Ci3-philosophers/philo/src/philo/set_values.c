/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:54:34 by reciak            #+#    #+#             */
/*   Updated: 2026/02/22 18:56:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_values.c
 * @brief Stores the definition of set_values()
 */

#include "philosophers.h"

/**
 * @brief Inits the philo struct of each start function of a philo thread
 */
void	set_values(t_philo *phi, t_all *all)
{
	pthread_mutex_lock(all->thread_span.mutex);
	phi->id = all->thread_span.id_cur_philo;
	phi->t.init = all->thread_span.t_simulation_start;
	phi->t.starved = phi->t.init + all->param.tt.die;
	phi->tt = all->param.tt;
	phi->meals.eaten = 0;
	phi->meals.min = all->param.meals_at_least;
	phi->maestro = &all->maestro;
	phi->squad_end = &all->squad_end;
	phi->lock_log = &all->mutab.lock_log;
	if (phi->id == 0)
	{
		phi->left_fork = &all->mutab.fork[all->param.num_philos - 1];
		phi->right_fork = &all->mutab.fork[0];
	}
	else
	{
		phi->left_fork = &all->mutab.fork[phi->id - 1];
		phi->right_fork = &all->mutab.fork[phi->id];
	}
	pthread_mutex_unlock(all->thread_span.mutex);
}
