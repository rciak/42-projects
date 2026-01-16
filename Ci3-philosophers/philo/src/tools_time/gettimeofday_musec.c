/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday_musec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:43:28 by reciak            #+#    #+#             */
/*   Updated: 2026/01/15 20:06:17 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file gettimeofday_musec.c
 * @brief Stores the definition of gettimeofday_musec()
 */

#include "philosophers.h"

/**
 * @brief Get a timestamp from gettimeofday and converts it into microseconds
 * @return Time in microseconds that has passed since the Epoch.
 */
long long	gettimeofday_musec(void)
{
	long long		musec;
	struct timeval	pair;

	(void) gettimeofday(&pair, NULL);
	musec = pair.tv_sec * ONE_SECOND_IN_US + pair.tv_usec;
	return (musec);
}
