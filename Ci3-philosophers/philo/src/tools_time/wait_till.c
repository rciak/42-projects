/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:29 by reciak            #+#    #+#             */
/*   Updated: 2026/02/17 12:47:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_till.c
 * @brief Stores the definition of wait_till()
 */

#include "philosophers.h"

/**
 * @brief Wait till the specified time (in microseconds since the epoch)
 */
int64_t	wait_till(int64_t t_stop)
{
	int64_t	timestamp;

	timestamp = gettimeofday_musec();
	if (t_stop > timestamp)
		wait_for(t_stop - timestamp);                                                // OPTIMIZATION: this might be inprecise;  Better implement something which compares to t_stop
	return (gettimeofday_musec());
}
