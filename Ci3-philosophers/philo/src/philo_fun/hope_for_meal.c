/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope_for_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:12:11 by reciak            #+#    #+#             */
/*   Updated: 2026/02/16 03:50:39 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hope_for_meal.c
 * @brief Stores the definition of hope_for_meal()
 */

#include "philosophers.h"

static bool may__grab_forks(bool *perm, t_philo *phi);

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
bool	hope_for_meal(t_philo *phi, t_time *t)
{
	t_squad_end	*squad_end;
	bool		*perm;
	int64_t		forks_in_hand;
	int64_t		t_cur;

	squad_end = phi->squad_end;
	perm = &phi->maestro->allows[phi->id];
	forks_in_hand = 0;

	while (true)
	{
		t_cur = gettimeofday_musec();
		if (t_cur >= t->starved)
			return (log_event(DIED, phi));
		if (may__grab_forks(perm, phi))
		{
			pthread_mutex_lock(phi->left_fork);
			
			// forks_in_hand++;
			t->eat.start = log_event(TAKE_FORKS_EAT, phi);
			t->starved = t->eat.start + phi->
			tt.die;
			pthread_mutex_unlock(phi->left_fork);
			if (it_s_time_to_say_goodbye(squad_end))
				return (false);


			
			//FEEDBACK to maestro that forks have been grabed
		}
			


		
	}
	
}

static bool may__grab_forks(bool *perm, t_philo *phi)
{
	if (get_bool(perm, phi->maestro->mutex) == true)
		return (true);
	return (false);
}

// 			&& !sim_end(squad_end))
// 		usleep(TIME_TILL_NEXT_FORK_CHECK);




// 	long long	id;
// 	t_perm		*perm;
// 	long long	shift;
// 	long long	n;
// 	bool		may_grab_forks;
// 	bool		simulation_ended;
// 	long long	t;

// 	id = phi->id;
// 	perm = phi->perm;
// 	shift = perm->shift;
// 	n = phi->num_philos;
// 	may_grab_forks = false;
// 	simulation_ended = false;
// 	t = gettimeofday_musec();
// 	while (!may_grab_forks && t < t_starved)
// 	{
// 		pthread_mutex_lock(&perm->mutex);
// 		may_grab_forks = perm->pattern[(id + shift) % n];
// 		pthread_mutex_unlock(&perm->mutex);
// 		wait_for(TIME_TILL_NEXT_FORK_CHECK);
// 		if(is_simulation_ended(phi) == true)
// 			return (END_OF_SIMULATION);
// 		t = gettimeofday_musec();
// 	}
// 	if (t >= t_starved)
// 		return (t = log_event(phi, DIED, t_starved));
// 	pthread_mutex_lock(phi->fork[(id - 1) % n]);
// 	pthread_mutex_lock(phi->fork[id % n]);
// 	t = log_event(phi, MEALTIME, t_starved);
// 	if (t >= t_starved)
// 	pthread_mutex_unlock(phi->fork[(id - 1) % n]);
// 	pthread_mutex_unlock(phi->fork[id % n]);
// 	return (t);
// }
