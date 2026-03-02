/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   now.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:43:28 by reciak            #+#    #+#             */
/*   Updated: 2026/02/10 18:46:59 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file now.c
 * @brief Stores the definition of now()
 */

#include "philosophers.h"

/**
 * @brief Get a timestamp from gettimeofday and converts it into microseconds
 * @return Time in microseconds that has passed since the Epoch.
 */
int64_t	now(void)
{
	int64_t			musec;
	struct timeval	pair;

	(void) gettimeofday(&pair, NULL);
	musec = pair.tv_sec * ONE_SECOND_IN_US + pair.tv_usec;
	return (musec);
}
