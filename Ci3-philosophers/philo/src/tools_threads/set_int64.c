/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:05:07 by reciak            #+#    #+#             */
/*   Updated: 2026/02/11 11:19:56 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_int64.c
 * @brief Stores the definition of set_int64()
 */

#include "philosophers.h"

/**
 * @brief Mutex protected stetting of an int64_t variable (shared among threads)
 */
void	set_int64(int64_t *var, int64_t value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}