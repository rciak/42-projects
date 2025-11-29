/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pathname_via_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:56:15 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 14:29:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_pathname_via_path.c
 * @brief Stores the definition of set_pathname_via_path()
 */

#include "pipex.h"

static char	*combine__on_match(char *prog_name, char *dir, t_data *data);

/**
 * @brief Search the path for an executable that matches the cur program name
 * @note If there is no such executable the program exits with "no permission"
 *       error, or "not found" errror (if there was not even a matching 
 *       (not executable) file).
 * @param[in] i the index of the current command
 * @param[in,out] data -> cmd[i].pathname
 */
void	set_pathname_via_path(t_data *data, int i)
{
	t_cmd	*cmd;
	char	**p_dir;

	cmd = &(data->cmd[i]);
	p_dir = data->path;
	while (*p_dir != NULL)
	{
		cmd->pathname = combine__on_match(cmd->av[0], *p_dir, data);
		if (cmd->pathname != NULL)
			return ;
		p_dir++;
	}
	exit_on(E_NOT_FOUND, errno, "set__pathname", data);
}

static char	*combine__on_match(char *prog_name, char *dir, t_data *data)
{
	char	*dir_with_slash;
	char	*combined;

	dir_with_slash = ft_strjoin(dir, "/");
	if (dir_with_slash == NULL)
		exit_on(E_ALLOC, errno, "combine__on_match", data);
	combined = ft_strjoin(dir_with_slash, prog_name);
	free(dir_with_slash);
	if (combined == NULL)
		exit_on(E_ALLOC, errno, "combine__on_match", data);
	if (access(combined, X_OK) == -1)
	{
		free(combined);
		return (NULL);
	}
	return (combined);
}
