/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:56:00 by reciak            #+#    #+#             */
/*   Updated: 2026/02/16 00:34:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file log_event.c
 * @brief Stores the definition of log_event()
 */

#include "philosophers.h"

static void	set__message(int kind, char **msg, char **msg_2);

/**
 * @brief Take timestamp and log the handed over event
 */
void log_event(int event, t_philo *phi)
{
	char		*msg;
	char		*msg_2;
	useconds_t	timestamp;
	bool		should_print;
	t_squad_end *s_end;
	
	s_end = phi->squad_end;
	set__message(event, &msg, &msg_2);
	should_print = true;
	pthread_mutex_lock(phi->lock_log);
	pthread_mutex_lock(s_end->mutex);
	timestamp = gettimeofday_musec();
	if (s_end->starved == true || s_end->num_pasta_lovers == 0)
		should_print = false;
	if (timestamp >= phi->t.starved)
		event = DIED;
	if (event == DIED)
		s_end->starved = true;
	pthread_mutex_unlock(s_end->mutex);
	if (should_print == true)
	{
		printf(msg, timestamp, phi->id + 1);
		if (msg_2 != NULL)
			printf(msg_2, timestamp, phi->id + 1);
	}
	pthread_mutex_unlock(phi->lock_log);
}

static void	set__message(int event, char **msg, char **msg_2)
{
	*msg_2 = NULL;
	if (event == DIED)
		*msg = "%u %li "RED"died"RESET"\n";
	if (event == TAKE_FIRST_FORK)
		*msg = "%u %li has taken a fork\n";
	if (event == TAKE_SECOND_FORK_EAT)
	{
		*msg = "%u %li has taken a fork\n";
		*msg_2 = "%u %li is eating\n";
	}
	if (event == SLEEP)
		*msg = "%u %li is sleeping\n";
	if (event == THINK)
		*msg = "%u %li is thinking\n";
if (event == DEBUG)
	*msg = "\t\t\t\t\t"RED"DEBUG:"RESET"  %u %li\n";
if (event == DEBUG_SIM_ENOUGH_PASTA)
	*msg = "\t\t\t\t\t"RED"DEBUG: SIM ENOUGH_PASTA"RESET"  %u %li\n";
}
