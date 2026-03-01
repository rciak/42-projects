/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_most.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:43:47 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 16:27:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_most.c
 * @brief Stores the definition of init_most()
 */

#include "philosophers.h"

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
	init__maestro(all);
	all->squad_end.mutex = &all->mutab.squad_end;
	all->squad_end.starved = false;
	all->squad_end.num_pasta_lovers = all->param.num_philos;
	all->thread_span.mutex = &all->mutab.thread_span;
	all->thread_span.new_thread_copied_vars = false;
}

static void	init__maestro(t_all *all)
{
	int64_t	i;

	all->maestro.mutex = &all->mutab.maestro;
	i = 0;
	while (i < all->param.num_philos)
	{
		all->maestro.allows[i] = false;
		i++;
	}
}
