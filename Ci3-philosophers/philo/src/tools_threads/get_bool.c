/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:19:22 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 16:33:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_bool.c
 * @brief Stores the definition of get_bool()
 */

#include "philosophers.h"

/**
 * @brief Mutex protected getting of a bool variable (shared among threads)
 */
bool	get_bool(bool *var, pthread_mutex_t *mutex)
{
	bool	copy;

	pthread_mutex_lock(mutex);
	copy = *var;
	pthread_mutex_unlock(mutex);
	return (copy);
}
