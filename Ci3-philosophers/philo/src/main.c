/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:15 by reciak            #+#    #+#             */
/*   Updated: 2026/02/09 12:30:40 by reciak           ###   ########.fr       */
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
// static bool join__philo_threads(t_phi *phi, t_ecode *code);

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
	if (!alloc__mem(&all, all.param.num_philos, &code))
		return (herr(code, "main: alloc__mem failed\n"));
	if (!init__mutexes(&all.mutab, all.param.num_philos, &code))
		return (herr_free(code, "main: init_mutexes failed\n", &all));
	// if (!init_most(&, &code))
	// 	return (herr_free(code, "main: init_most failed\n", &phi));
	// if (!create__philo_threads(&phi, &code))
	// 	return (herr_free(code, "main: create__philo_threads failed\n", &phi));
	// phi.perm.go = true;
	// if (!join__philo_threads(&phi, &code))
	// 	return (herr_free(code, "main: join__philo_threads failed\n", &phi));
	herr_free(E_NONE, "main: regular end\n", &all);
	return (E_NONE);
}

static bool	init__mutexes(t_mutex_tab *mutab, int64_t n, t_ecode *code)
{
	int				i;
	int				entries_before_fork;
	pthread_mutex_t	*mutex[5];
	
	entries_before_fork = 5;
	mutex[0] = &mutab->safe_cp;
	mutex[1] = &mutab->maestro;
	mutex[2] = &mutab->squad_end;
	mutex[3] = &mutab->lock_philos_till_start;
	mutex[4] = &mutab->lock_log;
	
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

static bool alloc__mem(t_all *all, int64_t n, t_ecode *code)
{
	all->maestro.allows = malloc(n * sizeof(bool));
	all->mutab.fork = malloc(n * sizeof(pthread_mutex_t));
	all->thread = malloc(n * sizeof(pthread_t));
	if (all->maestro.allows == NULL || all->mutab.fork == NULL)
	{
		free(all->maestro.allows);
		free(all->mutab.fork);
		free(all->thread);
		all->maestro.allows = NULL;
		all->mutab.fork = NULL;
		all->thread = NULL;
		*code = E_ALLOC;
		return (false);
	}
	return (true);
}

// /**
//  * @brief Joins all philiosophers threads
//  * @note This functions will join the philosopher threads in the order of their
//  *       creation and not their order of termination.
//  *       For a short time zombie threads might therefor be around
//  *       till all philo threads have ended.
//  * @note This should not be a problem though:
//  *       The zombie threads should be quite short lived since all philo threads
//  *       should end almost simultaneously.
//  *       Even without this no problem should occur since
//  *       after the initial creation of threads no more threads are created,
//  *       so that a lack of available threads can occur only at the start
//  *       of the program.
//  * @note If the project would allow more functions from @c pthread.h then
//  *       on could avoid getting many zombie threads fully by a technique
//  *       that Kerrisk demonstrated in Section 30.2.4 of this book
//  *       "The Linux Programming Interface".
//  */
// static bool join__philo_threads(t_phi *phi, t_ecode *code)
// {
// 	long long	i;
	
// 	i = 0;
// 	while (i < phi->param.num_philos)
// 	{
// 		if (pthread_join(phi->philo[i].thread, NULL) != 0)
// 			return (*code = E_THREAD_JOIN, false);
// 		i++;
// 	}
// 	return (true);
// }
// //
// //  Worüber ich mir noch klar werden muss:
// //
// //  ! Welche Ereignisse müssen erfasst werden, um korrekt zu printen?
// //
// //  ! Stop Simulation or at least Printing when a Philo died.
// //  ! How to print / announce the dead of a Philo within 10 ms?
// //
// //  Wie Freigabe geschmeidig hinbekommen?
// //
// //  Wie Zeit gut messen? 
// //    Philo wollen alle permanet die Uhrzeit abfragen...
// //
// //
// //  P L A N
// //
// // II  create philo threads, which do:
// //     [X] wait for start signal, then
// //        take fork - if access granted,
// //        eat,
// //        sleep,
// //        think,
// //                                                     [think extra if maestro
// //                                                      says so (due being ahead
// //                                                         of the other philos)]
// //        notify shared var `philo died` if philo dies
// //        repeat indefinitely or until max_num_meals reached (if specified)
// // III create maestro (and monitoring?!) thread, which does:
// //        START CLOCK and immediately after:
// //           Allow Philos that match PERMISSION PATTERN to take forks
// //        AFTERWARDS
// //           Update Permission pattern (*)
// //           When all forks have been returned
// //              Grant Philos that match PERMISSION PATTERN to take forks
// //     
// //  R E M A R K S:
// //  @ (*): modelled by add  +1  to shift var ( mod ... )

