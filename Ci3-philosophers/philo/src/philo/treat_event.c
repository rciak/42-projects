/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:56:00 by reciak            #+#    #+#             */
/*   Updated: 2026/03/02 18:28:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file log_event.c
 * @brief Stores the definition of log_event()
 */

#include "philosophers.h"

static void	print__message(int event, int64_t timestamp, int64_t id);
static void	elapse__time(int event, int64_t t_starved, t_philo *phi);
static void	reduce__passion_for_pasta(t_philo *phi);

/**
 * @brief Take timestamp and log the handed over event
 *        (which turns into DEAD event if too late to prevent starvation)
 */
void	treat_event(int event, t_philo *phi)
{
	t_squad_end	*s_end;
	int64_t		timestamp;

	s_end = phi->squad_end;
	pthread_mutex_lock(s_end->mutex);
	timestamp = gettimeofday_musec();
	if (timestamp >= phi->t.starved)
		event = DIED;
	if (s_end->starved == false && s_end->num_pasta_lovers > 0)
		print__message(event, timestamp - phi->t.init, phi->id);
	if (event == DIED)
		s_end->starved = true;
	pthread_mutex_unlock(s_end->mutex);
	if (event == EAT)
		phi->t.starved = timestamp + phi->tt.die;
	elapse__time(event, phi->t.starved, phi);
	pthread_mutex_lock(s_end->mutex);
	timestamp = gettimeofday_musec();
	if (event == EAT && phi->meals.min != OMITTED_PARAM
		&& phi->meals.eaten < phi->meals.min && timestamp < phi->t.starved)
		reduce__passion_for_pasta(phi);
	pthread_mutex_unlock(s_end->mutex);
}

static void	print__message(int event, int64_t timestamp, int64_t id)
{
	char	*msg;

	if (event == DIED)
		msg = "%lli %lli " RED "died" RESET "\n";
	if (event == TAKE_FIRST_FORK || event == TAKE_SECOND_FORK)
		msg = "%lli %lli has taken a fork\n";
	if (event == EAT)
		msg = "%lli %lli is " YELLOW "eating" RESET "\n";
	if (event == SLEEP)
		msg = "%lli %lli is sleeping\n";
	if (event == THINK)
		msg = "%lli %lli is thinking\n";
	if (event == DEBUG)															//REMOVE in FINAL
		msg = "\t\t\t\t\t"RED"DEBUG:"RESET"  %lli %lli\n";
	if (event == DEBUG_SIM_ENOUGH_PASTA)
		msg = "\t\t\t\t\t"RED"DEBUG: SIM ENOUGH_PASTA"RESET"  %lli %lli\n";
	printf(msg, timestamp / ONE_MS_IN_US, id + 1);
}

static void	elapse__time(int event, int64_t t_starved, t_philo *phi)
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
		wait_till(t_starved, phi->squad_end);
	else
		wait_till(timestamp + waiting_time, phi->squad_end);
}

static void	reduce__passion_for_pasta(t_philo *phi)
{
	int64_t		timestamp;
	t_squad_end	*s_end;

	s_end = phi->squad_end;
	timestamp = gettimeofday_musec();
	phi->meals.eaten++;
	if (phi->meals.eaten == phi->meals.min)
	{
		s_end->num_pasta_lovers--;
		if (s_end->num_pasta_lovers == 0 && s_end->starved == false)
			printf("%lli                     🕛👈 Cook: Let's call it a day!\n",
				(timestamp - phi->t.init) / ONE_MS_IN_US);
	}
}
