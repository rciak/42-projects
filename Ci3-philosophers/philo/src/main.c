/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:15 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 16:51:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "philosophers.h"

static bool	alloc__mem(t_all *all, int64_t n, t_ecode *code);
static bool	init__mutexes(t_mutex_tab *mutab, int64_t n, t_ecode *code);
static bool	init___forks(pthread_mutex_t *fork, int64_t n, t_ecode *code);
static bool	join__threads(t_all *phi, t_ecode *code);

/**
 * @brief Entry point for philiosophers
 * @param[in] argc The number of arguments on the command line
 * @param[in] argv The usual list of arguments on the command line
 * @return 
 *          * > 0 if an error occured
 *          * 0 (E_NONE) if no error occured
 */
int	main(int argc, char **argv)
{
	t_ecode		code;
	t_all		all;

	code = E_NONE;
	if (!parse_args(argc, argv, &all.param, &code))
		return (herr(code, "main: parse_args failed\n"));
	if (all.param.meals_at_least == 0)
		return (E_NONE);
	if (!alloc__mem(&all, all.param.num_philos, &code))
		return (herr(code, "main: alloc__mem failed\n"));
	if (!init__mutexes(&all.mutab, all.param.num_philos, &code))
		return (herr_free(code, "main: init_mutexes failed\n", &all));
	init_most(&all);
	if (!create_threads(&all, &code))
		return (herr_free(code, "main: create__philo_threads failed\n", &all));
	if (!join__threads(&all, &code))
		return (herr_free(code, "main: Wtf: join__threads failed?!\n", &all));
	herr_free(E_NONE, "main: regular end\n", &all);
	return (E_NONE);
}

static bool	alloc__mem(t_all *all, int64_t n, t_ecode *code)
{
	all->maestro.allows = malloc(n * sizeof(bool));
	all->mutab.fork = malloc(n * sizeof(pthread_mutex_t));
	all->thread_span.philo_thread = malloc(n * sizeof(pthread_t));
	if (all->maestro.allows == NULL
		|| all->mutab.fork == NULL
		|| all->thread_span.philo_thread == NULL)
	{
		free(all->maestro.allows);
		free(all->mutab.fork);
		free(all->thread_span.philo_thread);
		all->maestro.allows = NULL;
		all->mutab.fork = NULL;
		all->thread_span.philo_thread = NULL;
		*code = E_ALLOC;
		return (false);
	}
	return (true);
}

static bool	init__mutexes(t_mutex_tab *mutab, int64_t n, t_ecode *code)
{
	int				i;
	int				entries_before_fork;
	pthread_mutex_t	*mutex[4];

	entries_before_fork = 4;
	mutex[0] = &mutab->thread_span;
	mutex[1] = &mutab->maestro;
	mutex[2] = &mutab->squad_end;
	mutex[3] = &mutab->lock_philos_till_start;
	i = 0;
	while (i < entries_before_fork && pthread_mutex_init(mutex[i], NULL) == 0)
		i++;
	if (i < entries_before_fork)
	{
		while (i-- > 0)
			pthread_mutex_destroy(mutex[i]);
		return (*code = E_MUTEX_INIT, false);
	}
	if (!init___forks(&mutab->fork[0], n, code))
		return (false);
	return (true);
}

static bool	init___forks(pthread_mutex_t *fork, int64_t n, t_ecode *code)
{
	int64_t	i;

	i = 0;
	while (i < n && pthread_mutex_init(fork + i, NULL) == 0)
		i++;
	if (i < n)
	{
		while (i-- > 0)
			pthread_mutex_destroy(fork + i);
		return (*code = E_MUTEX_INIT, false);
	}
	return (true);
}

/**
 * @brief Joins all philiosophers threads
 * @note This functions will join the philosopher threads in the order of their
 *       creation and not their order of termination.
 *       For a short time zombie threads might therefor be around
 *       till all philo threads have ended.
 * @note This should not be a problem though:
 *       The zombie threads should be quite short lived since all philo threads
 *       should end almost simultaneously.
 *       Even without this no problem should occur since
 *       after the initial creation of threads no more threads are created,
 *       so that a lack of available threads can occur only at the start
 *       of the program.
 * @note If the project would allow more functions from @c pthread.h then
 *       on could avoid getting many zombie threads fully by a technique
 *       that Kerrisk demonstrated in Section 30.2.4 of this book
 *       "The Linux Programming Interface".
 */
static bool	join__threads(t_all *all, t_ecode *code)
{
	int64_t	i;

	if (pthread_join(all->thread_span.maestro_thread, NULL) != 0)
		return (*code = E_THREAD_JOIN, false);
	i = 0;
	while (i < all->param.num_philos)
	{
		if (pthread_join(all->thread_span.philo_thread[i], NULL) != 0)
			return (*code = E_THREAD_JOIN, false);
		i++;
	}
	return (true);
}
