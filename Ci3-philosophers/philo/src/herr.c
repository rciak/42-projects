/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:54:03 by reciak            #+#    #+#             */
/*   Updated: 2026/01/07 23:57:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file herr.c
 * @brief Stores the definition of herr()
 */

 #include "philosophers.h"

/**
 * @brief Prints an error message and returns an error code - the received one
 * @param[in] code, an error code defined in philosophers.h
 * @param[in] debug_info, a debug message (might be NULL or "")
 * @return \p code
 */
int	herr(t_ecode code, const char *debug_info)
{
	static t_err	err[] = {
	{E_NONE, "No error\n"},
	{E_ARGC, "Invalid number of arguments\n"},
	{E_MAX_NUM_MEALS_NEG, "Sorry: The cook will get angry if a negative number "
		"of meals is ordered ...\n"},
	{E_NUM_PHILOS_NOT_POS, "Number of philosophers must be at least 1\n"},
	{E_TIME_TO_DIE_NOT_POS, "Time to die must be at least 1 (ms)\n"},
	{E_TIME_TO_EAT_NOT_POS, "Time to eat must be at least 1 (ms)\n"},
	{E_TIME_TO_SLEEP_NEG, "Time to sleep must be at least 0 (ms)\n"},
	{E_DISRESPECT, "Sorry - philosophers do not support masochism / sadism\n"},
	{E_ATOLL_NO_ERR, "I would like to be printed but no pointer leads to me\n"},
	{E_ATOLL_BAD_STRING, "Atoll: I need numbers to do my job!\n"},
	{E_ATOLL_RANGE, "Atoll: Sorry the number would be out of range ...\n"},
	};

	if (code < 0 || code >= E_COUNT_THEM_ALL)
		putstr_fd("herr: Invalid error code (internal issue)\n", STDERR_FILENO);
	if (code != err[code].code)
		putstr_fd("herr: internal problem with error list\n", STDERR_FILENO);
	putstr_fd(err[code].msg, STDERR_FILENO);
	if (debug_info != NULL && debug_info[0] != '\0' && DEBUG_PRINT == 1)
		putstr_fd(debug_info, STDERR_FILENO);
	return (code);
}
