/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pathname_via_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:56:15 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 19:22:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_pathname_via_path.c
 * @brief Stores the definition of set_pathname_via_path()
 */

#include "pipex.h"

static char	*combine__to_abs_path(char *prog_name, char *dir, t_data *data);
static void	update__first_match(char **first, char *abs_path, t_data *data);

/**
 * @brief Search the path for an executable that matches the cur program name
 * @note If there is no such executable the program exits with "no permission"
 *       error, or "not found" errror (if there was not even a matching 
 *       (not executable) file).
 * @warning The error treatment is somewhat ad hoc -- assuming that
 *          access will fail by no other errors than E_NOT_FOUND and E_NO_PERM
 *          This assumption should usually be true, but probably not always.
 *          After having bad experience with execve producing unexpected errno
 *          relying on errno is tried to be avoided.
 * @param[in] i the index of the current command
 * @param[in,out] data -> cmd[i].pathname
 */
void	set_pathname_via_path(t_data *data, int i)
{
	t_cmd	*cmd;
	char	**p_dir;
	char	*abs_path;

	cmd = &(data->cmd[i]);
	p_dir = data->path;
	abs_path = NULL;
	while (*p_dir != NULL)
	{
		abs_path = combine__to_abs_path(cmd->av[0], *p_dir, data);
		update__first_match(&cmd->pathname_first_match, abs_path, data);
		if (access(abs_path, X_OK) != -1)
		{
			cmd->pathname = abs_path;
			return ;
		}
		free(abs_path);
		p_dir++;
	}
	if (cmd->pathname_first_match == NULL)
		exit_on(E_NOT_FOUND, errno, "set_pathname_via_path", data);
	else
		exit_on(E_NO_PERM_VIA_PATH, errno, "set_pathname_via_path", data);
}

static char	*combine__to_abs_path(char *prog_name, char *dir, t_data *data)
{
	char	*dir_with_slash;
	char	*combined;

	dir_with_slash = ft_strjoin(dir, "/");
	if (dir_with_slash == NULL)
		exit_on(E_ALLOC, errno, "combine__to_abs_path", data);
	combined = ft_strjoin(dir_with_slash, prog_name);
	free(dir_with_slash);
	if (combined == NULL)
		exit_on(E_ALLOC, errno, "combine__to_abs_path", data);
	return (combined);
}

static void	update__first_match(char **first, char *abs_path, t_data *data)
{
	if (*first != NULL)
		return ;
	if (access(abs_path, F_OK) != -1)
	{
		*first = ft_strdup(abs_path);
		if (*first == NULL)
			exit_on(E_ALLOC, errno, "update__first_match", data);
	}
}
