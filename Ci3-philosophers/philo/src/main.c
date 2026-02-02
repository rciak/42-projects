/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:15 by reciak            #+#    #+#             */
/*   Updated: 2026/02/02 10:53:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "philosophers.h"

static bool	alloc__mem(t_all *all, t_ecode *code);

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
	t_ecode	code;
	t_all	all;

	code = E_NONE;
	if (!parse_args(argc, argv, &all.param, &code))
		return (herr(code, "main: parse_args failed\n"));
	if (!alloc__mem(&all, &code))
		return (herr(code, "main: alloc__mem failed\n"));
	if (!init_rest(&all, &code))
		return (herr_free(code, "main: init_rest failed\n", &all));
	if (!create__philo_threads(&all, &code))
		return (herr_free(code, "main: create__philo_threads failed\n", &all));
	all.perm.go = true;
	usleep (4000000);      													// For now a dummy to keep main thread alive for some time ...
	//sauberer: threads nicht detachen, sondern joinen und main (thread) erst
	//dann (sicher!) beenden, weil im Stack von Main variablen liegen,
	//welche die anderen Threads benutzen.
	herr_free(E_NONE, "main: regular end", &all);
	return (E_NONE);
}

static bool alloc__mem(t_all *all, t_ecode *code)
{
	long long	n;

	n = all->param.num_philos;
	all->philo = malloc(n * sizeof(t_philo));
	all->fork = malloc(n * sizeof(t_fork));
	all->perm.pattern = malloc(n * sizeof(bool));
	if (all->philo == NULL || all->fork == NULL || all->perm.pattern == NULL)
	{
		free(all->philo);
		free(all->fork);
		free(all->perm.pattern);
		all->philo = NULL;
		all->fork = NULL;
		all->perm.pattern = NULL;
		*code = E_ALLOC;
		return (false);
	}
	return (true);
}


//
//  Worüber ich mir noch klar werden muss:
//
//  ! Welche Ereignisse müssen erfasst werden, um korrekt zu printen?
//
//  ! Stop Simulation or at least Printing when a Philo died.
//  ! How to print / announce the dead of a Philo within 10 ms?
//
//  Wie Freigabe geschmeidig hinbekommen?
//
//  Wie Zeit gut messen? 
//    Philo wollen alle permanet die Uhrzeit abfragen...
//
//
//  P L A N
//
// II  create philo threads, which do:
//     [X] wait for start signal, then
//        take fork - if access granted,
//        eat,
//        sleep,
//        think,
//                                                     [think extra if maestro
//                                                      says so (due being ahead
//                                                         of the other philos)]
//        notify shared var `philo died` if philo dies
//        repeat indefinitely or until max_num_meals reached (if specified)
// III create maestro (and monitoring?!) thread, which does:
//        START CLOCK and immediately after:
//           Allow Philos that match PERMISSION PATTERN to take forks
//        AFTERWARDS
//           Update Permission pattern (*)
//           When all forks have been returned
//              Grant Philos that match PERMISSION PATTERN to take forks
//     
//  R E M A R K S:
//  @ (*): modelled by add  +1  to shift var ( mod ... )

