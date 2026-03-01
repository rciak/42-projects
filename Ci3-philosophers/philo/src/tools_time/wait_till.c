/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:29 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 01:02:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_till.c
 * @brief Stores the definition of wait_till()
 */

#include "philosophers.h"

static void	not__so_busy_wait(int64_t t_stop, t_squad_end *s_end);
static void	busy__wait(int64_t t_stop, t_squad_end *s_end);

/**
 * @brief Wait till the specified time (in microseconds since the epoch) is over
 *        or till a simulation ending event had happened.
 * @warning The caller must have no lock on the mutex of `s_end` !
 */
int64_t	wait_till(int64_t t_stop, t_squad_end *s_end)
{
	not__so_busy_wait(t_stop, s_end);
	if (gettimeofday_musec() < t_stop)
		busy__wait(t_stop, s_end);
	return (gettimeofday_musec());
}

static void	not__so_busy_wait(int64_t t_stop, t_squad_end *s_end)
{
	int64_t	timestamp;
	int64_t	waiting_time;

	while (!time_to_say_goodbye(s_end))
	{
		timestamp = gettimeofday_musec();
		waiting_time = t_stop - timestamp;
		if (waiting_time <= TH_BUSY_WAIT)
			return;
		else if (TH_BUSY_WAIT < waiting_time && waiting_time <= TH_SINGLE_WAIT)
			usleep(waiting_time - TH_BUSY_WAIT / 2);
		else if (TH_SINGLE_WAIT < waiting_time && waiting_time <= 2 * TH_SINGLE_WAIT)
			usleep(TH_SINGLE_WAIT - TH_SINGLE_WAIT);
		else if (2 * TH_SINGLE_WAIT < waiting_time)
			usleep(TH_SINGLE_WAIT);
	}
}

static void busy__wait(int64_t t_stop, t_squad_end *s_end)
{
	int64_t	t_start;
	int64_t	delta_t;
	int64_t	i;

	t_start = gettimeofday_musec();
	delta_t = (t_stop - t_start) / 10;                                            // Currently just a magic number; even 1 did unexpectedly not produce so bad result!???
	i = 0;
	while (gettimeofday_musec() < t_stop)
	{	
		if (gettimeofday_musec() > t_start + i * delta_t)
		{
			i++;
			if (time_to_say_goodbye(s_end))
				break;
		}
	}
	//while (gettimeofday_musec() < t_stop && !time_to_say_goodbye(s_end));
}
