/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:56:00 by reciak            #+#    #+#             */
/*   Updated: 2026/02/17 13:57:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file log_event.c
 * @brief Stores the definition of log_event()
 */

#include "philosophers.h"

static void		print__message(int event, int64_t timestamp, int64_t id);
static void		set___message(int kind, char **msg, char **msg_2, char **msg_3);
static int64_t	elapse__time(int event, int64_t t_starved, t_philo *phi);

/**
 * @brief Take timestamp and log the handed over event
 *        (which turns into DEAD event if too late to prevent starvation)
 */
int64_t	log_event(int event, t_philo *phi)
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

	if (event == EAT)
		phi->t.starved += phi->tt.die;
	timestamp = elapse__time(event, phi->t.starved);
	
	


	// wait
	if (event == DIED)
		s_end->starved = true;
	if (event == EAT && phi->meals.min != OMITTED_PARAM)
	{
		//
	}


	if (timestamp >= phi->t.starved)
		event = DIED;
	if (event == DIED)
		s_end->starved = true;
	pthread_mutex_unlock(s_end->mutex);
	pthread_mutex_unlock(phi->lock_log);
	return (timestamp);
}

static void	print__message(int event, int64_t timestamp, int64_t id)
{
	char		*msg;
	char		*msg_2;
	char		*msg_3;

	set___message(event, &msg, &msg_2, &msg_3);
	printf(msg, timestamp / ONE_MS_IN_US, id + 1);
	if (msg_2 != NULL)
		printf(msg_2, timestamp / ONE_MS_IN_US, id + 1);
	if (msg_3 != NULL)
		printf(msg_3, timestamp / ONE_MS_IN_US, id + 1);
}

static void	set___message(int event, char **msg, char **msg_2, char **msg_3)
{
	*msg_2 = NULL;
	*msg_3 = NULL;
	if (event == DIED)
		*msg = "%li %li "RED"died"RESET"\n";
	if (event == TAKE_FORKS_EAT)
	{
		*msg = "%li %li has taken a fork\n";
		*msg_2 = "%li %li has taken a fork\n";
		*msg_3 = "%li %li is eating\n";
	}
	if (event == SLEEP)
		*msg = "%li %li is sleeping\n";
	if (event == THINK)
		*msg = "%li %li is thinking\n";
if (event == DEBUG)
	*msg = "\t\t\t\t\t"RED"DEBUG:"RESET"  %li %li\n";
if (event == DEBUG_SIM_ENOUGH_PASTA)
	*msg = "\t\t\t\t\t"RED"DEBUG: SIM ENOUGH_PASTA"RESET"  %li %li\n";
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
		timestamp = wait_till(t_starved);
	else
		timestamp = wait_till(timestamp + waiting_time);
	return (timestamp);
}
