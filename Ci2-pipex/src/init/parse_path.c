/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:25:29 by reciak            #+#    #+#             */
/*   Updated: 2025/10/21 10:43:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_path.c
 * @brief Stores the definition of parse_path()
 */

#include "pipex.h"

static char **	extract__path(char **envp, t_x_err *x_err);
static void	free__path_before_index(t_cmd *cmd, size_t i_fail);

/**
 * @brief Check if there is envp contains a PATH variable and parses it in case.
 * @note If there is no PATH Variable in the array pointed to by envp
 *       then cmd[i] is set to \c NULL for all i = 0... num_cmds - 1.
 * @param[in] envp
 * @param[in] num_cmds
 * @param[out] cmd -> path
 * @return 
 *          * When everything is ok (also no PATH is ok!)
 *          * When there was an error (e.g. malloc failed if there was a PATH)
 */
bool	parse_path(char **envp, size_t num_cmds, t_cmd *cmd, t_x_err *x_err)
{
	size_t	i;

	if (envp == NULL || *envp == NULL)
		return (*x_err = x_error(ERR_ENVP, errno, "parse_path"), false);
	if (num_cmds < 2)
		return (*x_err = x_error(ERR_TOO_FEW_CMDS, errno, "parse_path"), false);
	i = 0;
	while (i < num_cmds)
	{
		cmd[i].path = NULL;
		i++;
	}
	i = 0;
	while (i < num_cmds)
	{
		cmd[i].path = extract__path(envp, x_err);
		if (cmd[i].path == NULL && x_err->code == ERR_ALLOC
			&& ft_strcmp(x_err->origin, "extract__path") == 0)
		{
			free__path_before_index(cmd, i);
			free (cmd);
			return (false);
		}
		i++;
	}
	return (true);
}

static char **extract__path(char **envp, t_x_err *x_err)
{
	char	**path;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", ft_strlen("PATH=")) == 0)
		{
			path = ft_split(*envp + ft_strlen("PATH="), ':');
			if (path == NULL)
				*x_err = x_error(ERR_ALLOC, errno, "extract__path");
			return (path);
		}
		envp++;
	}
	return (NULL);
}

static void	free__path_before_index(t_cmd *cmd, size_t i_fail)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < i_fail)
	{
		j = 0;
		while (cmd[i].path[j] != NULL)
		{
			free(cmd[i].path[j]);
			j++;
		}
		free(cmd[i].path);
		i++;
	}
}