/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_for_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:12:11 by reciak            #+#    #+#             */
/*   Updated: 2026/02/15 23:59:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hope_for_meal.c
 * @brief Stores the definition of hope_for_meal()
 */

#include "philosophers.h"

/**
 * @brief Tries to pick up forks and log these events (also eating event)
 * @note If philo staved, the ending will be marked in the squd_end struct.
 * @param[in,out] phi A pointer to one of the philos
 * @param[in] t_starved timepoint (in microseconds) at which starvation occurs
 *                      (if not eaten till then)
 * @return A value @c T (in microseconds) with two meanings:
 *          * if @c 0 < T < t_starved: meal was started in time
 *          * if @c    T >= t_starved: starvation happened
 */
int64_t	hope_for_meal(t_philo *phi, t_time *t)
{
	t_squad_end	*squad_end;
	bool		*perm;
	int64_t		t_cur;
	
	perm = &phi->maestro->allows[phi->id];

	while (true)
	{
		if (!may__grab_forks(perm, phi->maestro->mutex)
	}
			&& !sim_end(squad_end))
		usleep(TIME_TILL_NEXT_FORK_CHECK);




	long long	id;
	t_perm		*perm;
	long long	shift;
	long long	n;
	bool		may_grab_forks;
	bool		simulation_ended;
	long long	t;

	id = phi->id;
	perm = phi->perm;
	shift = perm->shift;
	n = phi->num_philos;
	may_grab_forks = false;
	simulation_ended = false;
	t = gettimeofday_musec();
	while (!may_grab_forks && t < t_starved)
	{
		pthread_mutex_lock(&perm->mutex);
		may_grab_forks = perm->pattern[(id + shift) % n];
		pthread_mutex_unlock(&perm->mutex);
		wait_for(TIME_TILL_NEXT_FORK_CHECK);
		if(is_simulation_ended(phi) == true)
			return (END_OF_SIMULATION);
		t = gettimeofday_musec();
	}
	if (t >= t_starved)
		return (t = log_event(phi, DIED, t_starved));
	pthread_mutex_lock(phi->fork[(id - 1) % n]);
	pthread_mutex_lock(phi->fork[id % n]);
	t = log_event(phi, MEALTIME, t_starved);
	if (t >= t_starved)
	pthread_mutex_unlock(phi->fork[(id - 1) % n]);
	pthread_mutex_unlock(phi->fork[id % n]);
	return (t);
}
