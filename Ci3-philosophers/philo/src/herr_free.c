/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:47 by reciak            #+#    #+#             */
/*   Updated: 2026/01/16 16:23:59 by reciak           ###   ########.fr       */
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
 * @return \p code
 */
int	herr_free(t_ecode code, const char *debug_info, t_all *all)
{
	free(all->philo);
	free(all->fork);
	free(all->perm.pattern);
	pthread_mutex_destroy(&all->perm.mutex);
	pthread_mutex_destroy(&all->lock_philos_till_start);
	pthread_mutex_destroy(&all->lock_dead);
	return (herr(code, debug_info));
}
