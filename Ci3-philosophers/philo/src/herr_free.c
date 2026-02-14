/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:47 by reciak            #+#    #+#             */
/*   Updated: 2026/02/13 14:30:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file herr_free.c
 * @brief Stores the definition of herr_free()
 */

#include "philosophers.h"

static void	destroy__mutexes(t_all *all);

/**
 * @brief herr() plus additional freeing of heap allocated mem
 * @param[in] code, an error code defined in philosophers.h
 * @param[in] debug_info, a debug message (might be NULL or "")
 * @param[in] all, the main struct
 * @return \p code
 */
int	herr_free(t_ecode code, const char *debug_info, t_all *all)
{
	if (code != E_MUTEX_INIT && code != E_THREAD_JOIN)
		destroy__mutexes(all);
	free(all->maestro.allows);
	free(all->mutab.fork);
	free(all->thread_span.thread);
	return (herr(code, debug_info));
}

static void	destroy__mutexes(t_all *all)
{
	int64_t	i;

	pthread_mutex_destroy(&all->mutab.safe_cp);
	pthread_mutex_destroy(&all->mutab.thread_span);
	pthread_mutex_destroy(&all->mutab.maestro);
	pthread_mutex_destroy(&all->mutab.squad_end);
	pthread_mutex_destroy(&all->mutab.lock_philos_till_start);
	pthread_mutex_destroy(&all->mutab.lock_log);
	i = 0;
	while (i < all->param.num_philos)
	{
		pthread_mutex_destroy(all->mutab.fork + i);
		i++;
	}
}
