/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:47 by reciak            #+#    #+#             */
/*   Updated: 2026/02/09 09:35:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file herr_free.c
 * @brief Stores the definition of herr_free()
 */

#include "philosophers.h"

/**
 * @brief herr() plus additional freeing of heap allocated mem
 * @param[in] code, an error code defined in philosophers.h
 * @param[in] debug_info, a debug message (might be NULL or "")
 * @param[in] all, the main struct
 * @return \p code
 */
int	herr_free(t_ecode code, const char *debug_info, t_all *all)
{
	free(all->maestro.allows);
	free(all->mutab.fork);


	
	// pthread_mutex_destroy(&all->mutab.perm);
	// pthread_mutex_destroy(&all->mutab.lock_philos_till_start);
	// pthread_mutex_destroy(&all->mutab.lock_dead);
	// pthread_mutex_destroy(&all->mutab.lock_end_simul);
	// pthread_mutex_destroy(&all->mutab.lock_still_love_pasta);
	return (herr(code, debug_info));
}
