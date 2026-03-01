/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:56:38 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 16:33:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_bool.c
 * @brief Stores the definition of set_bool()
 */

#include "philosophers.h"

/**
 * @brief Mutex protected stetting of a bool variable (shared among threads)
 */
void	set_bool(bool *var, bool value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}
