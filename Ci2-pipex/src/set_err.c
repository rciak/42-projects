/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:57:48 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 18:12:14 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_err.c
 * @brief Stores the definition of set_err()
 */

#include "pipex.h"

static char		*error__message(int type);
static t_exit	exit__pair(int type, int cur_errno);
static t_exit	other__situation(int type, int cur_errno);
// static void		more__other_situation(int type, int cur_errno);

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
		{E_ENVP_NULL, "envp == NULL"},
		{E_ENVP_EMPTY_ARRAY, "envp contains no strings"},
		{E_TOO_FEW_CMDS, "number of commands too little, min. 2 required"},
		{E_CREATE_PIPE, "creation of pipe failed"},
		{E_OPEN_READ, "Opening for reading failed"},
		{E_OPEN_WRITE, "Opening for writing failed"},
		{E_FUN_ASSERTION, "Assertion in function failed"},
		{E_FORK, "Fork failed"},
	};
	
	if (type < 0 || (unsigned long) type > sizeof(pair) / sizeof(pair[0]) - 1)
		logic_error_exit(RED"error__message: "RESET"param type out of range");
	return (pair[type].msg);
}

static t_exit	exit__pair(int type, int cur_errno)
{
	if (type == E_NONE 
		&& cur_errno == 0)
		return ((t_exit){error__message(type), 0});
	if (type == E_ARGC)
		return ((t_exit){error__message(type), EX_USAGE});
	if (type == E_ALLOC)
		return ((t_exit){error__message(type), EX_OSERR});
	if (type == E_NEGATIVE_FD)
		return ((t_exit){error__message(type), 1});
	if (type == E_CLOSE_FAILED)
		return ((t_exit){error__message(type), EX_IOERR});
	if (type == E_ENVP_NULL)
		return ((t_exit){error__message(type), 2});
	if (type == E_ENVP_EMPTY_ARRAY)
		return ((t_exit){error__message(type), 2});
	if (type == E_TOO_FEW_CMDS)
		return ((t_exit){error__message(type), 1});
	if (type == E_CREATE_PIPE)
		return ((t_exit){error__message(type), EX_OSERR});
	if (type == E_FUN_ASSERTION)
		return ((t_exit){error__message(type), 2});
	if (type == E_FORK)
		return ((t_exit){error__message(type), 2});
	return (other__situation(type, cur_errno));
}

static t_exit	other__situation(int type, int cur_errno)
{
	if (type == E_OPEN_READ && cur_errno == ENOENT)
		return ((t_exit){"r-Open failed: not found", EX_IOERR});
	if (type == E_OPEN_READ && cur_errno == EACCES)
		return ((t_exit){"r-Open failed: no access", EX_NOPERM});
	if (type == E_OPEN_WRITE && cur_errno == ENOENT)
		return ((t_exit){"w-Open failed: not found", EX_IOERR});
	if (type == E_OPEN_WRITE && cur_errno == EACCES)
		return ((t_exit){"w-Open failed: no access", EX_NOPERM});
	if (type == E_OPEN_READ && (cur_errno != ENOENT && cur_errno != EACCES))
		return ((t_exit){"r-Open failed", EX_IOERR});
	if (type == E_OPEN_WRITE && (cur_errno != ENOENT && cur_errno != EACCES))
		return ((t_exit){"w-Open failed", EX_NOPERM});
	if (type == E_NONE && cur_errno != 0)
		logic_error_exit(RED"exit__pair: "RESET"E_NONE but cur_errno != 0 ?!");
	else
		logic_error_exit(RED"exit__pair: "RESET"No pair defined");
	return ((t_exit){"Silencing compiler - how can this ever be reached?!", 1});
}

// static void	more__other_situation(int type, int cur_errno)
// {
	
// }