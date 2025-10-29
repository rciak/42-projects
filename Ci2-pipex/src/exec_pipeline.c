/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:56:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 22:58:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static bool	do__child_stuff(t_data *data, size_t i, char **envp, t_err *err);
static bool set___pathname(char	**pathname, t_cmd *cmd, t_err *err);
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

	if (err->type != E_NONE || data->num_cmds < 2)
		return (set_err(err, E_FUN_ASSERTION, errno, "exec_pipeline"), false);
	cmd = data->cmd;
	i = 0;
	while (i < data->num_cmds)
	{
		cmd[i].pid = fork();
		if (cmd[i].pid == -1)
			return (set_err(err, E_FORK, errno, "exec_pipeline"), false);
		else if (cmd[i].pid == 0 && !do__child_stuff(data, i, envp, err))
			return (false);
		i++;
	}
	close__nonstd_fds(data);
	return (true);
}

static bool	do__child_stuff(t_data *data, size_t i, char **envp, t_err *err)
{
	char *pathname;

	dup2(data->cmd[i].fd_in, STDIN_FILENO);
	dup2(data->cmd[i].fd_out, STDOUT_FILENO);
	close__nonstd_fds(data);
	if (!set___pathname(&pathname, &data->cmd[i], err))
		return (false);
	execve(pathname, data->cmd[i].av, envp);
	set_err(err, E_EXECVE_FAILED, errno, "do__child_stuff");
	free (pathname);
	return (false);
}

/////////////////////////////
if (pathname == NULL)
return (set_err(err, E_CMD_NOT_FOUND, errno, "do__child_stuff"), false);
//
static bool set___pathname(char	**pathname, t_cmd *cmd, t_err *err)
{
	char **av;

	av = cmd->av;
	if (av == NULL || *av == NULL)
		return (set_err(err, E_FUN_ASSERTION, errno, "set___pathname"), false);
	if (ft_strcmp(av[0], "") == 0)
		return (set_err(err, E_EMPTY_CMD, errno, "set___pathname"), false);
	if (av[0][0] == '/')
		*pathname = ft_strdup(av[0]);
	else if (ft_strlen(av[0]) >= 2 && ft_strncmp(av[0], "./", 2) == 0)
		*pathname = ft_strdup(av[0]);
	else
		*pathname = 
	if (*pathname == NULL)
		return (false);
	return (true);
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