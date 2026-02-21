/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:56:00 by reciak            #+#    #+#             */
/*   Updated: 2026/02/21 20:55:58 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file log_event.c
 * @brief Stores the definition of log_event()
 */

#include "philosophers.h"

static void		print__message(int event, int64_t timestamp, int64_t id);
static int64_t	elapse__time(int event, int64_t t_starved, t_philo *phi);

/**
 * @brief Take timestamp and log the handed over event
 *        (which turns into DEAD event if too late to prevent starvation)
 */
void	log_event(int event, t_philo *phi)
{
	t_squad_end *s_end;
	int64_t		timestamp;

	s_end = phi->squad_end;
	pthread_mutex_lock(phi->lock_log);
	pthread_mutex_lock(s_end->mutex);                                           //refactor: Move that lock closer to where it is needed!?!
	timestamp = gettimeofday_musec();
	if (timestamp >= phi->t.starved)
		event = DIED;
	if (s_end->starved == false && s_end->num_pasta_lovers > 0)
		print__message(event, timestamp, phi->id);
	if (event == DIED)
		s_end->starved = true;
	pthread_mutex_unlock(s_end->mutex);
	pthread_mutex_unlock(phi->lock_log);
	if (event == EAT)
		phi->t.starved += phi->tt.die;
	(void) elapse__time(event, phi->t.starved, phi);                          //refactor: return type to void
	pthread_mutex_lock(s_end->mutex);
	if (event == EAT && phi->meals.min != OMITTED_PARAM
			&& phi->meals.eaten < phi->meals.min && timestamp < phi->t.starved)
	{
		timestamp = gettimeofday_musec();        // Remove when below test print "Cook:..." is removed
		phi->meals.eaten++;
		if (phi->meals.eaten == phi->meals.min)
		{
			s_end->num_pasta_lovers--;
			if (s_end->num_pasta_lovers == 0)    // This printing is unsecure: JUST FOR TESTING --> MUST BE REMOVED when everything is working
				printf("%li, Cook: Let's call it a day!\n", timestamp);
		}
	}
	pthread_mutex_unlock(s_end->mutex);
}

static void	print__message(int event, int64_t timestamp, int64_t id)
{
	char		*msg;

	if (event == DIED)
		msg = "%li %li "RED"died"RESET"\n";
	if (event == TAKE_FIRST_FORK || event == TAKE_SECOND_FORK)
		msg = "%li %li has taken a fork\n";
	if (event == EAT)
		msg = "%li %li is "YELLOW"eating"RESET"\n";
	if (event == SLEEP)
		msg = "%li %li is sleeping\n";
	if (event == THINK)
		msg = "%li %li is thinking\n";
	if (event == DEBUG)															    //REMOVE in FINAL
		msg = "\t\t\t\t\t"RED"DEBUG:"RESET"  %li %li\n";
	if (event == DEBUG_SIM_ENOUGH_PASTA)
		msg = "\t\t\t\t\t"RED"DEBUG: SIM ENOUGH_PASTA"RESET"  %li %li\n";
	printf(msg, timestamp / ONE_MS_IN_US, id + 1);
}

static int64_t	elapse__time(int event, int64_t t_starved, t_philo *phi)
{
	int64_t	timestamp;
	int64_t	waiting_time;

	if (event == EAT)
		waiting_time = phi->tt.eat;
	else if (event == SLEEP)
		waiting_time = phi->tt.sleep;
	else
		waiting_time = 0;
	timestamp = gettimeofday_musec();
	if (timestamp + waiting_time >= t_starved)
		timestamp = wait_till(t_starved, phi->squad_end);                                       //Speedup simulation when everything works in principle: Check if simulation was ended by other threads... --> Extend wait till....
	else
		timestamp = wait_till(timestamp + waiting_time, phi->squad_end);
	return (timestamp);
}
