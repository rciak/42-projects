/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:59:16 by reciak            #+#    #+#             */
/*   Updated: 2025/11/27 10:47:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_cmd.c
 * @brief Stores the definition of exec_cmd()
 */

#include "pipex.h"

static void	set__pathname(t_data *data, int i);
static char	*combine___on_match(char *prog_name, char *dir, t_data *data);
static void	close__nonstd_fds(t_data *data, int i);

/**
 * @brief Perpares the execution of a single command of the pipe(x)line
 * @param[in, out] data
 * @param[in] i The index of the current command
 * @param[in] envp The environment handed over to execve
 */

void	exec_cmd(t_data *data, int i, char **envp)
{
	set__pathname(data, i);
	if (dup2(data->cmd[i].fd_in, STDIN_FILENO) == -1)
		exit_on(E_DUP_TWO, errno, "exec_cmd", data);
	if (dup2(data->cmd[i].fd_out, STDOUT_FILENO) == -1)
		exit_on(E_DUP_TWO, errno, "exec_cmd", data);
	close__nonstd_fds(data, i);
	if (i < data->num_cmds - 1)
		close__nonstd_fds(data, i + 1);
	if (execve(data->cmd[i].pathname, data->cmd[i].av, envp) == -1)
	{
		free (data->cmd[i].pathname);
		data->cmd[i].pathname = NULL;
		exit_on(E_EXECVE, errno, "exec_pipeline", data);
	}
}

static void	close__nonstd_fds(t_data *data, int i)
{
	t_cmd	*cmd;

	if (i > data->num_cmds - 1)
	{
		out_str_fd(RED"Warning"RESET" - close__nonstd_fds: Miscalled\n",
			STDERR_FILENO);
		return ;
	}
	cmd = &(data->cmd[i]);
	if (cmd->fd_in == STDIN_FILENO || cmd->fd_out == STDOUT_FILENO
		|| cmd->fd_out == STDERR_FILENO)
		out_str_fd(RED"Warning"RESET" - closing standard fd\n", STDERR_FILENO);
	if (cmd->fd_in >= 0)
	{
		if (close (cmd->fd_in) == -1)
			exit_on(E_CLOSE, errno, "close__nonstd_fds", data);
		cmd->fd_in = UNUSED;
	}
	if (cmd->fd_out >= 0)
	{
		if (close (cmd->fd_out) == -1)
			exit_on(E_CLOSE, errno, "close__nonstd_fds", data);
		cmd->fd_out = UNUSED;
	}
}

/**
 * @brief Sets data->cmd[i].pathname
 * @param[in, out] data
 * @note Not that the checks
 *       `cmd->path == NULL` and `*cmd->path == NULL`, respectively,
 *       are relevant for the cases 
 *       `unset PATH` and `PATH` `PATH=":::"` (--> Empty array), respectively.
 * @param[in] i The index of the current command
 */
static void	set__pathname(t_data *data, int i)
{
	t_cmd	*cmd;
	char	**av;
	char	**p_dir;

	cmd = &(data->cmd[i]);
	av = data->cmd[i].av;
	if (data->path == NULL || *data->path == NULL || is_in('/', av[0]))
	{
		cmd->pathname = ft_strdup(av[0]);
		if (cmd->pathname == NULL)
			exit_on(E_ALLOC, errno, "set__pathname", data);
		return ;
	}
	p_dir = data->path;
	while (*p_dir != NULL)
	{
		cmd->pathname = combine___on_match(cmd->av[0], *p_dir, data);
		if (cmd->pathname != NULL)
			return ;
		p_dir++;
	}
	exit_on(E_NOT_FOUND, errno, "set__pathname", data);
}

static char	*combine___on_match(char *prog_name, char *dir, t_data *data)
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
