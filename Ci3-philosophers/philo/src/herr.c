/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:54:03 by reciak            #+#    #+#             */
/*   Updated: 2026/03/01 15:50:54 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file herr.c
 * @brief Stores the definition of herr()
 */

#include "philosophers.h"

static void		copy__error_definitions(t_err *err);
static t_err	get___definition(int code);
static bool		check__validity(t_err *err);

/**
 * @brief Prints an error message and returns an error code - the received one
 * @param[in] code, an error code defined in philosophers.h
 * @param[in] debug_info, a debug message (might be NULL or "")
 *                        --> activate by compliling with flag DEBUG_PRINT=1
 *                            i.e. run  `make DEBUG_PRINT=1 [...]`
 * @return \p code
 */
int	herr(t_ecode code, const char *debug_info)
{
	static t_err	err[E_COUNT_THEM_ALL];

	copy__error_definitions(err);
	if (code < 0 || code >= E_COUNT_THEM_ALL)
		putstr_fd("herr: Invalid error code (internal issue)\n", STDERR_FILENO);
	if (!check__validity(err))
		putstr_fd("herr: internal problem with error list\n", STDERR_FILENO);
	putstr_fd(err[code].msg, STDERR_FILENO);
	if (debug_info != NULL && debug_info[0] != '\0' && DEBUG_PRINT == 1)
		putstr_fd(debug_info, STDERR_FILENO);
	return (code);
}

static void	copy__error_definitions(t_err *err)
{
	size_t	i;

	i = 0;
	while (i < E_COUNT_THEM_ALL)
	{
		err[i] = get___definition(i);
		i++;
	}
}

static t_err	get___definition(int code)
{
	static const t_err	err[E_COUNT_THEM_ALL] = {
	{E_NONE, ""},
	{E_ARGC, "Invalid number of arguments\n"},
	{E_MAX_NUM_MEALS_NEG, "Number of meals must be at least 0 (or omitted)\n"},
	{E_NUM_PHILOS_NOT_POS, "Number of philosophers must be at least 1\n"},
	{E_TIME_TO_DIE_NOT_POS, "Time to die must be at least 1 (ms)\n"},
	{E_TIME_TO_EAT_NOT_POS, "Time to eat must be at least 1 (ms)\n"},
	{E_TIME_TO_SLEEP_NEG, "Time to sleep must be at least 0 (ms)\n"},
	{E_ATOLL_NO_ERR, "I would like to be printed but no pointer leads to me\n"},
	{E_ATOLL_BAD_STRING, "Atoll: I need integer numbers to do my job!\n"},
	{E_ATOLL_RANGE, "Atoll: Sorry the number would be out of range ...\n"},
	{E_DISRESPECT, "Sorry - philosophers do not support sadistic values\n"},
	{E_OVERFLOW_AHEAD, "Canceling risky multiplication (undefined behaviour);\n"
		"Please enter only reasonable values closer to 0	\n"},
	{E_ALLOC, "Memory allocation failed\n"},
	{E_MUTEX_INIT, "Mutex initialization failed\n"},
	{E_THREAD_CREATE, "pthread_create failed\n"},
	{E_THREAD_JOIN, "pthread_join failed? -> Not risking destroying mutexes\n"},
	};

	return (err[code]);
}

static bool	check__validity(t_err *err)
{
	size_t	i;

	i = 0;
	while (i < E_COUNT_THEM_ALL)
	{
		if (err[i].code != i)
			return (false);
		i++;
	}
	return (true);
}
