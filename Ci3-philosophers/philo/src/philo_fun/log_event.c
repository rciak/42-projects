/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:56:00 by reciak            #+#    #+#             */
/*   Updated: 2026/02/13 12:56:49 by reciak           ###   ########.fr       */
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
void log_event(t_event event, int64_t id, int64_t t_starved, t_squad_end s_end)
{
	char		*msg;
	char		*msg_2;
	useconds_t	timestamp;
	bool		should_print;
	
	set__message(event.kind, &msg, &msg_2);
	timestamp = gettimeofday_musec();
	should_print = true;
	pthread_mutex_lock(s_end.mutex);
	if (s_end.starved == true || s_end.num_pasta_lovers <= 0)
		should_print = false;
	pthread_mutex_unlock(s_end.mutex);
	if (should_print == true)
	{
		pthread_mutex_lock(event.mutex);
		printf(msg, timestamp, id + 1);
		if (msg_2 != NULL)
			printf(msg_2, timestamp, id + 1);
		pthread_mutex_unlock(event.mutex);
	}
}

static void	set__message(int kind, char **msg, char **msg_2)
{
	*msg_2 = NULL;
	if (kind == DIED)
		*msg = "%u %li died\n";
	if (kind == TAKE_FIRST_FORK)
		*msg = "%u %li has taken a fork\n";
	if (kind == TAKE_SECOND_FORK_EAT)
	{
		*msg = "%u %li has taken a fork\n";
		*msg_2 = "%u %li is eating\n";
	}
	if (kind == SLEEP)
		*msg = "%u %li is sleeping\n";
	if (kind == THINK)
		*msg = "%u %li is thinking\n";
}
