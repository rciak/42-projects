/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:57:48 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 10:27:58 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_err.c
 * @brief Stores the definition of set_err()
 */

#include "pipex.h"

static char		*error__message(int type);
static t_exit	exit__pair(int type, int cur_errno);

/**
 * @brief Sets and error struct based on the handed over information.
 * @param[out] err Address of an error struct s_err
 * @param[in]  type The error type / code from e_pipex_errors, see pipex.h
 * @param[in]  cur_errno The current errno value
 * @param[in]  origin A string literal (which should help in debugging)
 */
void	set_err(t_err *err, int type, int cur_errno, const char *origin)
{
	if (cur_errno >= 0)
		err->saved_errno = cur_errno;
	err->type = type;
	err->msg = error__message(type);
	err->origin = origin;
	err->exit = exit__pair(type, cur_errno);
}

static char	*error__message(int type)
{
	static t_err_type_to_msg	pair[] = {
		{E_NONE, "success - no error detected"},
		{E_ARGC, "argc: Wrong number of arguments"},
		{E_ALLOC, "memory allocation failed"},
		{E_NEGATIVE_FD, "filedesciptor is < 0"},
		{E_CLOSE_FAILED, "close failed"},
	};

	if (type < 0 || (unsigned long) type > sizeof(pair) / sizeof(pair[0]) - 1)
		logic_error_exit(RED"error__message: "RESET"param type out of range");
	return (pair[type].msg);
}

static t_exit	exit__pair(int type, int cur_errno)
{
	t_exit	pair;

	if (type == E_NONE && cur_errno == 0)
		pair = (t_exit){0, error__message(type)};
	else if (type == E_ARGC)
		pair = (t_exit){EX_USAGE, error__message(type)};
	else if (type == E_ALLOC)
		pair = (t_exit){2, error__message(type)};
	else if (type == E_NEGATIVE_FD)
		pair = (t_exit){2, error__message(type)};
	else if (type == E_CLOSE_FAILED)
		pair = (t_exit){EX_IOERR, error__message(type)};
	else if (type == E_NONE && cur_errno != 0)
		logic_error_exit(RED"exit__pair: "RESET"E_NONE but cur_errno != 0 ?!");
	else
		logic_error_exit(RED"exit__pair: "RESET"No pair defined");
	return (pair);
}
