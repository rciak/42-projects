/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_most.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:43:47 by reciak            #+#    #+#             */
/*   Updated: 2026/02/09 18:05:53 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_most.c
 * @brief Stores the definition of init_most()
 */

#include "philosophers.h"

static void	init__perm(t_all *all);
static void	init__maestro(t_all *all);

/**
 * @brief Init most vars but those inited later during thread creation function)
 * @param[out] all mostly initialised
 * @param[out] code error code
 * @return 
 *          * true, if no error occured
 *          * false, if an error occured
 */
void	init_most(t_all *all)
{
	init__perm(all);
	init__maestro(all);
	all->squad_end.mutex = &all->mutab.squad_end;
	all->squad_end.starved = false;
	all->squad_end.num_pasta_lovers = all->param.num_philos;
	if (all->param.meals_at_least == OMITTED_PARAM)
		all->squad_end.num_pasta_lovers = OMITTED_PARAM;
	all->safe_cp.mutex = &all->mutab.safe_cp;
	all->safe_cp.just_created_thread_has_copied = false;
}


static void	init__perm(t_all *all)
{
	int64_t	n;
	int64_t	i;

	n = all->param.num_philos;
	
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
}

static void	init__maestro(t_all *all)
{
	int64_t	i;

	all->maestro.mutex = &all->mutab.maestro;
	i = 0;
	while (i < all->param.num_philos)
	{
		all->maestro.allows[i] = all->perm.pattern[i];
		i++;
	}
	all->maestro.go = false;
}