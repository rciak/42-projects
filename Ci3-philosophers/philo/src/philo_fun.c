/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:40 by reciak            #+#    #+#             */
/*   Updated: 2026/01/14 19:25:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_fun.c
 * @brief Stores the definition of philo_fun()
 */

#include "philosophers.h"

/**
 * @brief The start function executed by each philosopher thread
 * @param[in, out] arg A pointer to a philo struct
 * @return Allways `NULL` (all philo threads are anyway detached ...)
 */
void	*philo_fun(void *arg)
{
	t_philo			*philo;
	long long		id;

	philo = (t_philo *)arg;
	id = philo->id;
	return (NULL);
}