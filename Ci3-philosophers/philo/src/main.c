/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:15 by reciak            #+#    #+#             */
/*   Updated: 2026/01/11 17:53:30 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */


#include "philosophers.h"

static bool	parse__args(int argc, char **argv, t_param *param, t_ecode *code);
static bool	atoll___ok(int argc, t_ecode *err_code, t_ecode *code);
static bool	values___ok(int argc, t_param *par, t_ecode *code);

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
	if (!parse__args(argc, argv, &all.param, &code))
		return (herr(code, "main: parse__args failed\n"));
	return (0);
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
// I    Alloc and Init
//        a) forks
//        b1) PERMISSION pattern
//        b2) NO_PHILO_HAS_PERMISSION pattern
//
// II  create philo threads, which do:
//     wait for start signal, then
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


static bool	parse__args(int argc, char **argv, t_param *param, t_ecode *code)
{
	t_ecode	err_code[5];

	if (argc < 1 + 4 || argc > 1 + 5)
		return (*code = E_ARGC, false);
	err_code[0] = E_ATOLL_NO_ERR;
	err_code[1] = E_ATOLL_NO_ERR;
	err_code[2] = E_ATOLL_NO_ERR;
	err_code[3] = E_ATOLL_NO_ERR;
	err_code[4] = E_ATOLL_NO_ERR;
	param->num_philos = atoll_strict(argv[1], &err_code[0]);
	param->tt_die = atoll_strict(argv[2], &err_code[1]);
	param->tt_eat = atoll_strict(argv[3], &err_code[2]);
	param->tt_sleep = atoll_strict(argv[4], &err_code[3]);
	param->max_num_meals = -1;
	if (argc == 1 + 5)
		param->max_num_meals = atoll_strict(argv[5], &err_code[4]);
	if (!atoll___ok(argc, err_code, code))
		return (false);
	if (!values___ok(argc, param, code))
		return (false);
	return (*code = E_NONE, true);
}

static bool	atoll___ok(int argc, t_ecode *err_code, t_ecode *code)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (err_code[i] != E_ATOLL_NO_ERR)
			return (*code = err_code[i], false);
		i++;
	}
	if (argc == 1 + 5 && err_code[4] != E_ATOLL_NO_ERR)
		return (*code = err_code[4], false);
	return (*code = E_NONE, true);
}

static bool	values___ok(int argc, t_param *par, t_ecode *code)
{
	if (par->num_philos < 1)
		return (*code = E_NUM_PHILOS_NOT_POS, false);
	if (par->tt_die < 1)
		return (*code = E_TIME_TO_DIE_NOT_POS, false);
	if (par->tt_eat < 1)
		return (*code = E_TIME_TO_EAT_NOT_POS, false);
	if (par->tt_sleep < 0)
		return (*code = E_TIME_TO_SLEEP_NEG, false);
	if (argc == 1 + 5 && par->max_num_meals < 0)
		return (*code = E_MAX_NUM_MEALS_NEG, false);
	if (par->num_philos > MAX_NUM_PHILOS
		|| par->tt_die > MAX_TT_DIE
		|| par->tt_eat > MAX_TT_EAT
		|| par->tt_sleep > MAX_TT_SLEEP
		|| (argc == 1 + 5 && par->max_num_meals > MAX_NUM_MEALS)
		|| (par->tt_eat > ONE_HOUR_IN_MS && par->tt_die > ONE_HOUR_IN_MS)
		|| (par->tt_sleep > ONE_HOUR_IN_MS && par->tt_die > ONE_HOUR_IN_MS))
		return (*code = E_DISRESPECT, false);
	return (*code = E_NONE, true);
}
