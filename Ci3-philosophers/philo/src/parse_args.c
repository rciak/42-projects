/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:47:04 by reciak            #+#    #+#             */
/*   Updated: 2026/02/05 08:57:51 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_args.c
 * @brief Stores the definition of parse_args()
 */

#include "philosophers.h"

static bool	atoll__ok(int argc, t_ecode *err_code, t_ecode *code);
static bool	values__ok(int argc, t_param *par, t_ecode *code);

/**
 * @brief Parses command-line arguments for the philosophers program.
 * @note 
 * @param[in] argc The number of command-line arguments
 * @param[in] argv The array of command-line argument strings
 * @param[out] param The structure to store parsed parameters
 * @param[out] code A Code indicating success or type of error
 * @return
 *          * true if parsing was successful
 *          * false if an error occurred
 */
bool	parse_args(int argc, char **argv, t_param *param, t_ecode *code)
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
	param->meals_at_least = OMITTED_PARAM;
	if (argc == 1 + 5)
		param->meals_at_least = atoll_strict(argv[5], &err_code[4]);
	if (!atoll__ok(argc, err_code, code))
		return (false);
	if (!values__ok(argc, param, code))
		return (false);
	return (*code = E_NONE, true);
}

static bool	atoll__ok(int argc, t_ecode *err_code, t_ecode *code)
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

static bool	values__ok(int argc, t_param *par, t_ecode *code)
{
	if (par->num_philos < 1)
		return (*code = E_NUM_PHILOS_NOT_POS, false);
	if (par->tt_die < 1)
		return (*code = E_TIME_TO_DIE_NOT_POS, false);
	if (par->tt_eat < 1)
		return (*code = E_TIME_TO_EAT_NOT_POS, false);
	if (par->tt_sleep < 0)
		return (*code = E_TIME_TO_SLEEP_NEG, false);
	if (argc == 1 + 5 && par->meals_at_least < 0)
		return (*code = E_MAX_NUM_MEALS_NEG, false);
	if (par->num_philos > MAX_NUM_PHILOS
		|| par->tt_die > MAX_TT_DIE
		|| par->tt_eat > MAX_TT_EAT
		|| par->tt_sleep > MAX_TT_SLEEP
		|| (argc == 1 + 5 && par->meals_at_least > MAX_NUM_MEALS)
		|| (par->tt_eat > ONE_HOUR_IN_MS && par->tt_die > ONE_HOUR_IN_MS)
		|| (par->tt_sleep > ONE_HOUR_IN_MS && par->tt_die > ONE_HOUR_IN_MS))
		return (*code = E_DISRESPECT, false);
	return (*code = E_NONE, true);
}
