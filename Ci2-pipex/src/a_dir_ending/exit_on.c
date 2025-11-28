/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:40:09 by reciak            #+#    #+#             */
/*   Updated: 2025/11/28 17:28:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exit_on.c
 * @brief Stores the definition of exit_on()
 */

#include "pipex.h"

static t_exit_info	map__to_exit_info(t_err err);
static bool			set___matching_info(
						t_err err,
						t_err_to_exit *rel,
						t_exit_info *info,
						int num_elements
						);
static t_exit_info	default___exit_info(void);

/**
 * @brief Handles the error described by the first and (potentially) second arg
 * @warning The check `data != NULL` is needed in case that parse_argv fails!
 * @param[in] type The type of error, cf. the enum  e_pipex_errors  in pipex.h
 * @param[in] saved_errno A copy of errno or `ERRNO_IRREL`
 * @param[in] origin A string literal
 *                   (intended to indicate from where the error came from)
 * @param[in] data If not \c NULL this is
 *                 mainly stuff to tidy up, but also contains `data->i_cmd_err`.
 *                 If being \c NULL then no tidying up is done.
 * @param[in] 
 */
void	exit_on(int type, int saved_errno, const char *origin, t_data *data)
{
	t_err		err;
	t_exit_info	info;

	err.type = type;
	err.saved_errno = saved_errno;
	info = map__to_exit_info(err);
	if (ft_strcmp(info.str1, GENERAL_ERROR_MSG) == 0)
		out_str_fd(GENERAL_ERROR_MSG, STDERR_FILENO);
	else
		print_msg(info, origin, data);
	if (data != NULL)
		do_final_nonsense_tidy_up(data);
	exit (info.code);
}

/**
 * @note Each error type should have at least one `ANY` entry for `saved_errno`,
 *       Other more precise specifications for `saved_errno` are also allowed,
 *       but must be placed in lines above the one with the `ANY` entry.
 * @warning Do not add an entry for argc errors in this list, but keep treating
 *          that separately!
 */
static t_exit_info	map__to_exit_info(t_err err)
{
	static t_err_to_exit	err_to_exit[] = {
	{{E_ASSERTION, ANY}, {"Failed assertion in:", "origin", MEX_ASSERTION}},
	{{E_ALLOC, ANY}, {"Memory allocation failed in:", "origin", EX_OSERR}},
	{{E_CLOSE, ANY}, {"Close failed in:", "origin", EX_OSERR}},
	{{E_DUP_TWO, ANY}, {"dup2 failed in:", "origin", EX_OSERR}},
	{{E_EXECVE, EACCES}, {"Permission denied:", "cmd[i].av[0]", MEX_NO_PERM}},
	{{E_EXECVE, ENOENT}, {"Not found:", "cmd[i].av[0]", MEX_NOT_FOUND}},
	{{E_EXECVE, ANY}, {"Execve failed", "", MEX_GENERIC}},
	{{E_NOT_FOUND, ANY}, {"Not found:", "cmd[i].av[0]", MEX_NOT_FOUND}},
	{{E_FORK, ANY}, {"Fork failed", "", EX_OSERR}},
	{{E_CREATE_PIPE, ANY}, {"Creating of pipe failed", "", EX_OSERR}},
	{{E_OPEN_RD, EACCES}, {"r-Open: No access:", "cmd[i].infile", EX_NOPERM}},
	{{E_OPEN_RD, ENOENT}, {"r-Open: Not found:", "cmd[i].infile", EX_IOERR}},
	{{E_OPEN_RD, ANY}, {"r-Open failed in:", "origin", EX_IOERR}},
	{{E_OPEN_WR, EACCES}, {"w-Open: No access:", "cmd[i].outfile", EX_NOPERM}},
	{{E_OPEN_WR, ENOENT}, {"w-Open: Not found:", "cmd[i].outfile", EX_IOERR}},
	{{E_OPEN_WR, ANY}, {"r-Open failed for:", "cmd[i].av[0]", EX_IOERR}},
	};
	t_exit_info				info;

	if (set___matching_info(err, err_to_exit, &info,
			sizeof(err_to_exit) / sizeof(err_to_exit[0])))
		return (info);
	return (default___exit_info());
}

static bool	set___matching_info(
	t_err err,
	t_err_to_exit *rel,
	t_exit_info *info,
	int num_elements
	)
{
	int	i;

	i = 0;
	while (i < num_elements)
	{
		if (rel[i].err.type == err.type && (rel[i].err.saved_errno == ANY
				|| rel[i].err.saved_errno == err.saved_errno))
		{
			*info = rel[i].info;
			return (true);
		}
		i++;
	}
	return (false);
}

static t_exit_info	default___exit_info(void)
{
	t_exit_info	info;

	info.str1 = GENERAL_ERROR_MSG;
	info.str2 = "";
	info.code = MEX_GENERIC;
	return (info);
}
