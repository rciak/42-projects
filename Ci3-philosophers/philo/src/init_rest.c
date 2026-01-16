/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:43:47 by reciak            #+#    #+#             */
/*   Updated: 2026/01/16 16:24:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_rest.c
 * @brief Stores the definition of init_rest()
 */

#include "philosophers.h"

static bool	init__forks(t_all *all, t_ecode *code);
static void	init__perm(t_all *all);

/**
 * @brief Initialize all except all->philo (done during philo threads creation)
 * @param[out] all initialised
 * @param[out] code error code
 * @return 
 *          * true, if no error occured
 *          * false, if an error occured
 */
bool	init_rest(t_all *all, t_ecode *code)
{
	if (!init__forks(all, code))
		return (false);
	init__perm(all);
	all->dead = NO_DEAD;
	pthread_mutex_init(&all->lock_philos_till_start, NULL);
	pthread_mutex_init(&all->lock_dead, NULL);
	return (true);
}

static bool	init__forks(t_all *all, t_ecode *code)
{
	long long	i;

	i = 0;
	while (i < all->param.num_philos)
	{
		if (pthread_mutex_init(&all->fork[i].mutex, NULL) != 0)
		{
			*code = E_MUTEX_INIT;
			return (false);
		}
		all->fork[i].in_hand = false;
		i++;
	}
	return (true);
}

static void	init__perm(t_all *all)
{
	long long	n;
	long long	i;

	n = all->param.num_philos;
	pthread_mutex_init(&all->perm.mutex, NULL);
	all->perm.pattern[n - 1] = false;
	all->perm.pattern[0] = true;
	i = 0;
	while (i < n - 1)
	{
		if (i % 2 == 0)
			all->perm.pattern[i] = true;
		else
			all->perm.pattern[i] = false;
		i++;
	}
	all->perm.shift = 0;
	all->perm.go = false;
}
