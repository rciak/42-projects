/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_most.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:43:47 by reciak            #+#    #+#             */
/*   Updated: 2026/02/08 16:33:05 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_most.c
 * @brief Stores the definition of init_most()
 */

#include "philosophers.h"

static bool	init__forks(t_phi *phi, t_ecode *code);
static void	init__perm(t_phi *phi);

/**
 * @brief Init most vars but those inited later during thread creation function)
 * @param[out] phi mostly initialised
 * @param[out] code error code
 * @return 
 *          * true, if no error occured
 *          * false, if an error occured
 */
bool	init_most(t_phi *phi, t_ecode *code)
{
	if (!init__forks(phi, code))
		return (false);
	init__perm(phi);
	phi->dead = NO_DEAD;
	phi->still_loving_pasta = phi->param.num_philos;
	if (phi->param.meals_at_least == OMITTED_PARAM)
		phi->still_loving_pasta = OMITTED_PARAM;
	phi->end_simul = false;
	pthread_mutex_init(&phi->lock_still_love_pasta, NULL);
	pthread_mutex_init(&phi->lock_dead, NULL);
	pthread_mutex_init(&phi->lock_end_simul, NULL);
	pthread_mutex_init(&phi->lock_philos_till_start, NULL);
	return (true);
}

static bool	init__forks(t_phi *phi, t_ecode *code)
{
	long long	i;

	i = 0;
	while (i < phi->param.num_philos)
	{
		if (pthread_mutex_init(&phi->fork[i].mutex, NULL) != 0)
		{
			*code = E_MUTEX_INIT;
			return (false);
		}
		phi->fork[i].in_hand = false;
		i++;
	}
	return (true);
}

static void	init__perm(t_phi *phi)
{
	long long	n;
	long long	i;

	n = phi->param.num_philos;
	pthread_mutex_init(&phi->perm.mutex, NULL);
	phi->perm.pattern[n - 1] = false;
	phi->perm.pattern[0] = true;
	i = 0;
	while (i < n - 1)
	{
		if (i % 2 == 0)
			phi->perm.pattern[i] = true;
		else
			phi->perm.pattern[i] = false;
		i++;
	}
	phi->perm.shift = 0;
	phi->perm.go = false;
}
