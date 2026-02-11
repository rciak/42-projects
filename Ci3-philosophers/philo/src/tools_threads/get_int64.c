/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:16:16 by reciak            #+#    #+#             */
/*   Updated: 2026/02/11 11:21:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_int64.c
 * @brief Stores the definition of get_int64()
 */

#include "philosophers.h"

/**
 * @brief Mutex protected getting of an int64_t variable (shared among threads)
 */
int64_t	get_int64(int64_t *var, pthread_mutex_t *mutex)
{
	int64_t	copy;

	pthread_mutex_lock(mutex);
	copy = *var;
	pthread_mutex_unlock(mutex);
	return (copy);
}