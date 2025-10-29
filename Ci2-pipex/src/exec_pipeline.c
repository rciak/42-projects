/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:56:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 17:09:23 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static bool	do__child_stuff(t_data *data, size_t i, char **envp, t_err *err);
static bool	set___pathname(char	**pathname, t_cmd *cmd, t_err *err);
static char *combine____on_match(char *prog, char *dir, t_err *err);
static void	close__nonstd_fds(t_data *data);

/**
 * @brief Executes the pipe(x)line
 * @param[in] num_cmds
 * @param[in] cmd
 * @param[in] envp
 * @param[in] err
 * @return 
 *          * false, if a fork or if an execve
 *          * true, if the parent process successfully launched
 */
bool	exec_pipeline(t_data *data, char **envp, t_err *err)
{
	size_t	i;
	t_cmd	*cmd;

	cmd = data->cmd;
	if (err->type != E_NONE || data->num_cmds < 2)
		return (set_err(err, E_FUN_ASSERTION, errno, "exec_pipeline"), false);
	i = 0;
	while (i < data->num_cmds)
	{
		cmd[i].pid = fork();
		if (cmd[i].pid == -1)
			return (set_err(err, E_FORK, errno, "exec_pipeline"), false);
		else if (cmd[i].pid == 0 && !do__child_stuff(data, i, envp, err))
		{
			err->cmd_index = i;
			return (false);
		}
		i++;
	}
	close__nonstd_fds(data);
	return (true);
}

static bool	do__child_stuff(t_data *data, size_t i, char **envp, t_err *err)
{
	t_cmd	*cmd;
	char	*pathname;

	cmd = &data->cmd[i];
	pathname = NULL;
	if (cmd->av == NULL || *cmd->av == NULL)
		return (set_err(err, E_FUN_ASSERTION, errno, "do__child_stuff"), false);
	// likely not needed: Hsould be handled with the other stuff              ,,..   
	// if (ft_strcmp(cmd->av[0], "") == 0)
	// 	return (set_err(err, E_EMPTY_CMD, errno, "do__child_stuff"), false);
	dup2(cmd->fd_in, STDIN_FILENO);
	dup2(cmd->fd_out, STDOUT_FILENO);
	close__nonstd_fds(data);

#include <stdio.h>
fprintf(stderr, "\nA:\n");
	if (!set___pathname(&pathname, cmd, err))
		return (false);
fprintf(stderr, "B:\n");
fprintf(stderr, "pathname: |%s|\n", pathname);
	execve(pathname, cmd->av, envp);
fprintf(stderr, "C:\n");
	set_err(err, E_EXECVE_FAILED, errno, "do__child_stuff");
	free (pathname);
	return (false);
}

static bool set___pathname(char	**pathname, t_cmd *cmd, t_err *err)
{
	char	**av;
	char	**p_dir;

	av = cmd->av;
	if (ft_strncmp(av[0], "/", 1) == 0 || ft_strncmp(av[0], "./", 2) == 0)
	{
		*pathname = ft_strdup(av[0]);
		if (*pathname == NULL)
			return (set_err(err, E_ALLOC, errno, "set___pathname"), false);
		return (true);
	}
	p_dir = cmd->path;
	while (*p_dir != NULL)
	{
		*pathname = combine____on_match(cmd->av[0], *p_dir, err);
		if (*pathname != NULL)
			return (true);
		p_dir++;
	}
	set_err(err, E_NOT_FOUND, errno, "set___pathname");
	return (false);
}

static char *combine____on_match(char *prog, char *dir, t_err *err)
{
	char *dir_with_slash;
	char *combined;

	dir_with_slash = ft_strjoin(dir, "/");
	if (dir_with_slash == NULL)
	{
		set_err(err, E_ALLOC, errno, "combine____on_match");
		return (NULL);
	}
	combined = ft_strjoin(dir_with_slash, prog);
	if (combined == NULL)
	{
		set_err(err, E_ALLOC, errno, "combine____on_match");
		free (dir_with_slash);
		return (NULL);
	}
	free (dir_with_slash);
	if (access(combined, X_OK) == -1)
	{
		free(combined);
		return (NULL);
	}
	return(combined);
}

static void	close__nonstd_fds(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->num_cmds)
	{
		if (data->cmd[i].fd_in > 0)
			close(data->cmd[i].fd_in);
		data->cmd[i].fd_in = -1;
		if (data->cmd[i].fd_out > 0)
			close(data->cmd[i].fd_out);
		data->cmd[i].fd_out = -1;
		i++;
	}
}
