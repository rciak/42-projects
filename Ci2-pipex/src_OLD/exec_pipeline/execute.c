/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:18:48 by reciak            #+#    #+#             */
/*   Updated: 2025/10/24 14:55:08 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute.c
 * @brief Stores the definition of execute()
 */
																		#include <stdio.h>
#include "pipex.h"

static bool	exec__abs_path(char **av, t_x_err *x_err);
static bool	exec__in_working_dir(char **av, t_x_err *x_err);
static bool	exec__by_path(char **av, char **path, t_x_err *x_err);

/**
 * @brief This essentially a pimped execv including path search
 * @param[in] av The to be executed program and its parameters
 * @param[in] path
 */
bool	execute(char **av, char **path, t_x_err *x_err)
{
	if (av == NULL || *av == NULL)
		return (*x_err = x_error(ERR_DENY_NULL, errno, "execute"), false);
	if (ft_strcmp(av[0], "") == 0)
		return (*x_err = x_error(ERR_EMPTY_STRING, errno, "execute"), false);
fprintf (stderr, "C: Checking if ABSOLUTE path\n");
	if (av[0][0] == '/')
		return (exec__abs_path(av, x_err));
fprintf (stderr, "D: Checking if in WORKING DIR\n");
	if (ft_strlen(av[0]) >= 2 && ft_strncmp(av[0], "./", 2) == 0)
		return (exec__in_working_dir(av, x_err));
fprintf (stderr, "E: Checking if IN PATH\n");
	return (exec__by_path(av, path, x_err));
}

static bool	exec__abs_path(char **av, t_x_err *x_err)
{
	if (execv(av[0], av) == -1)
	{
		*x_err = x_error(ERR_EXECVE, errno, "exec__abs_path");
		return (false);
	}
	return (true);
}

static bool	exec__in_working_dir(char **av, t_x_err *x_err)
{
	if (execv(av[0], av) == -1)
	{
		*x_err = x_error(ERR_EXECVE, errno, "exec__in_working_dir");
		return (false);
	}
	return (true);
}

static bool	exec__by_path(char **av, char **path, t_x_err *x_err)
{
	char	*dir_with_slash;
	char	*prefixed;
	
	if (path == NULL || *path == NULL)
		return (*x_err = x_error(ERR_PATH, errno, "exec__by_path"), false);
	while (*path != NULL)
	{
fprintf (stderr, "path: %s \n", *path);
		dir_with_slash = ft_strjoin(*path, "/");
		if (dir_with_slash == NULL)
			return (*x_err = x_error(ERR_ALLOC, errno, "exec__by_path"), false);
		prefixed = ft_strjoin(dir_with_slash, av[0]);
		if (prefixed == NULL)
		{
			free(dir_with_slash);
			*x_err = x_error(ERR_ALLOC, errno, "exec__by_path");
			return (false);
		}
		execv(prefixed, av);
		path++;
	}
	free(dir_with_slash);
	free(prefixed);
	*x_err = x_error(ERR_EXECVE, errno, "exec__in_working_dir");
	return (false);
}
