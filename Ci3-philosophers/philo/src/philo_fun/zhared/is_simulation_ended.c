/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_ended.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:04:52 by reciak            #+#    #+#             */
/*   Updated: 2026/02/06 12:22:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_simulation_ended.c
 * @brief Stores the definition of is_simulation_ended()
 */

#include "philosophers.h"

/**
 * @brief Checks if a flag `end_simul` was set to indicate that the 
 *        simulation should end.
 * @note 
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
bool	is_simulation_ended(t_philo *phi)
{
	bool	end_simul;

	pthread_mutex_lock(phi->lock_end_simul);
	end_simul = phi->end_simul;
	pthread_mutex_unlock(phi->lock_end_simul);
	return (end_simul);
}
