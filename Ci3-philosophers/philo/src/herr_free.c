/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:47 by reciak            #+#    #+#             */
/*   Updated: 2026/02/08 15:59:18 by reciak           ###   ########.fr       */
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
 * @param[in] phi, the main struct
 * @return \p code
 */
int	herr_free(t_ecode code, const char *debug_info, t_phi *phi)
{
	free(phi->share.maestro->allows);
	free(phi->mutab->fork);
	// pthread_mutex_destroy(&phi->perm.mutex);
	// pthread_mutex_destroy(&phi->lock_philos_till_start);
	// pthread_mutex_destroy(&phi->lock_dead);
	// pthread_mutex_destroy(&phi->lock_end_simul);
	// pthread_mutex_destroy(&phi->lock_still_love_pasta);
	return (herr(code, debug_info));
}
