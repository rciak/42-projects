/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:59:16 by reciak            #+#    #+#             */
/*   Updated: 2025/11/28 12:59:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_cmd.c
 * @brief Stores the definition of exec_cmd()
 */

#include "pipex.h"

static void	set__pathname(t_data *data, int i);
static void prefix___with_dot_slash(char **pathname);
static void	set___pathname_via_path(t_data *data, int i);
static char	*combine____on_match(char *prog_name, char *dir, t_data *data);

/**
 * @brief Perpares the execution of a single command of the pipe(x)line
 * @param[in, out] data
 * @param[in] i The index of the current command
 * @param[in] envp The environment handed over to execve
 */
void	exec_cmd(t_data *data, int i, char **envp)
{
	set__pathname(data, i);                     // Maybe directly before execve???
	if (dup2(data->cmd[i].fd_in, STDIN_FILENO) == -1)
		exit_on(E_DUP_TWO, errno, "exec_cmd", data);
	if (dup2(data->cmd[i].fd_out, STDOUT_FILENO) == -1)
		exit_on(E_DUP_TWO, errno, "exec_cmd", data);
	close_fd_in_fd_out(data, i);
	if (i < data->num_cmds - 1)
		close_fd_in_fd_out(data, i + 1);
	if (execve(data->cmd[i].pathname, data->cmd[i].av, envp) == -1)
	{
		free (data->cmd[i].pathname);               // Redundant? 
		data->cmd[i].pathname = NULL;               // --> Done in tidy up anyway?
		exit_on(E_EXECVE, errno, "exec_cmd", data);
	}
}

/**
 * @brief Sets data->cmd[i].pathname
 * @param[in, out] data
 * @note Not that the checks
 *       `cmd->path == NULL` and `*cmd->path == NULL`, respectively,
 *       are relevant for the cases 
 *       `unset PATH` and `PATH` `PATH=":::"` (--> Empty array), respectively.
 * @note The check `av[0] == NULL` is for the case that an empty command
 *       ('' or "") was given as a parameter to pipex.
 * @param[in] i The index of the current command
 */
static void	set__pathname(t_data *data, int i)
{
	t_cmd	*cmd;
	char	**av;
	
	cmd = &(data->cmd[i]);
	av = data->cmd[i].av;
	if (av[0] == NULL)
		exit_on(E_NOT_FOUND, errno, "set__pathname", data);
	if ((ft_strlen(av[0]) >= 1 && ft_strcmp(av[0], "/") == 0)
		|| (ft_strlen(av[0]) >= 2 && ft_strcmp(av[0], "./") == 0))
	{
		cmd->pathname = ft_strdup(av[0]);
		if (cmd->pathname == NULL)
			exit_on(E_ALLOC, errno, "set__pathname", data);
	}
	else if (data->path == NULL || *data->path == NULL)
	{
		cmd->pathname = ft_strdup(av[0]);
		if (cmd->pathname == NULL)
			exit_on(E_ALLOC, errno, "set__pathname", data);
		prefix___with_dot_slash(&(cmd->pathname));
		if (cmd->pathname == NULL)
			exit_on(E_ALLOC, errno, "set__pathname", data);
	}
	else
		set___pathname_via_path(data, i);
}

static void	prefix___with_dot_slash(char **pathname)
{
	char	*new;
	
	new = ft_strjoin("./", *pathname);
	if (new == NULL)
		exit_on(E_ALLOC, errno, "prefix___with_dot_slash", NULL);
	free(*pathname);
	*pathname = new;
}

static void	set___pathname_via_path(t_data *data, int i)
{
	t_cmd	*cmd;
	char	**p_dir;

	cmd = &(data->cmd[i]);
	p_dir = data->path;
	while (*p_dir != NULL)
	{
		cmd->pathname = combine____on_match(cmd->av[0], *p_dir, data);
		if (cmd->pathname != NULL)
			return ;
		p_dir++;
	}
	exit_on(E_NOT_FOUND, errno, "set__pathname", data);
}

static char	*combine____on_match(char *prog_name, char *dir, t_data *data)
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
