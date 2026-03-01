/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:35:01 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 17:05:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file maestro_fun.c
 * @brief Stores the definition of maestro_fun()
 */

#include "philosophers.h"

static void	con__duct(t_maestro *mae, int64_t n, int64_t *shift);
static bool	all___forks_on_table(t_maestro *mae, int64_t num_philos);

/**
 * @brief The start function executed by the maestro thread
 * @note The "maestro" "signals" every philo when it is ok to grab forks.
 * @param[in, out] arg A pointer to an all struct
 * @return Allways `NULL`
 */

void	*maestro_fun(void *arg)
{
	t_all			*all;
	t_thread_span	*thread_span;
	t_maestro		*maestro;
	int64_t			n;
	int64_t			shift;

	all = (t_all *) arg;
	thread_span = &all->thread_span;
	maestro = &all->maestro;
	n = get_int64(&all->param.num_philos, thread_span->mutex);
	shift = 0;
	pthread_mutex_lock(&all->mutab.lock_philos_till_start);
	pthread_mutex_unlock(&all->mutab.lock_philos_till_start);
	if (get_bool(&all->thread_span.creating_failed,
			all->thread_span.mutex) == true)
		return (NULL);
	while (!time_to_say_goodbye(&all->squad_end))
	{
		con__duct(maestro, n, &shift);
		usleep(MAESTRO_WAIT);
	}
	return (NULL);
}

static void	con__duct(t_maestro *mae, int64_t n, int64_t *shift)
{
	int64_t	i;
	int64_t	i_rotated;

	if (!all___forks_on_table(mae, n))
		return ;
	*shift = (*shift + 1) % n;
	pthread_mutex_lock(mae->mutex);
	mae->allows[(n - 1 + *shift) % n] = false;
	mae->allows[(0 + *shift) % n] = true;
	i = 0;
	while (i < n - 1)
	{
		i_rotated = (i + *shift) % n;
		if (i % 2 == 0)
			mae->allows[i_rotated] = true;
		else
			mae->allows[i_rotated] = false;
		i++;
	}
	pthread_mutex_unlock(mae->mutex);
}

static bool	all___forks_on_table(t_maestro *mae, int64_t num_philos)
{
	bool	reval;
	int64_t	i;

	reval = true;
	i = 0;
	pthread_mutex_lock(mae->mutex);
	while (i < num_philos)
	{
		if (mae->allows[i] == true)
		{
			reval = false;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(mae->mutex);
	return (reval);
}
