/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alone_at_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:30:01 by reciak            #+#    #+#             */
/*   Updated: 2026/02/11 11:44:20 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_alone_at_table.c
 * @brief Stores the definition of philo_alone_at_table()
 */

#include "philosophers.h"

/**
* @brief The start function for the edge case of only one philosopher thread.
* @note For n >= 2 philosophers the start function is philo_fun()
* @param[in, out] arg A pointer to a philo struct
* @return Allways `NULL`
*/
void		*philo_alone_at_table(void *arg)
{
	t_all *all;

	all = (t_all *) arg;
	pthread_mutex_lock(&all->mutab.lock_log);
	printf("Dummy: In philo_alone_at_table: Dummy\n");
	pthread_mutex_unlock(&all->mutab.lock_log);
	return (NULL);
}