/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:17:38 by reciak            #+#    #+#             */
/*   Updated: 2025/10/24 18:41:24 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

static int		exec__first(t_cmd *first_cmd, t_x_err *x_err);
static int		exec__mid(t_cmd *mid_cmd, int left_pipe_fd_read, t_x_err *x_err);
static void		exec__last(t_cmd *last_cmd, int left_pipe_fd_read, t_x_err *x_err);

/**
 * @brief This setups and executes the pipe(x)line
 * @param[in] data
 * @param[out] pid Stores the pid returned by fork before exec the last command 
 *                 (or -1 if an error occured before that)
 * @param[out] x_err Providing feedback to the caller for error handling
 * @return
 *          * false,  if a fork failed or if an execv failed
 *          * true, else 
 */
bool	exec_pipeline(t_cmd	*cmd, size_t n_cmds, t_x_err *x_err)
{
	int		pfd_read;
	size_t	i;
	
	if (x_err->code != ERR_NONE)
		exit (ERR_LOGIC);
	if (n_cmds < 2)
	{
		; //                                                                Error!
	}

	i = 0;
	while (i < n_cmds)
	{
		if (i == 0)
			pfd_read = exec__first(&cmd[i], x_err);
		else if (0 < i && i < n_cmds - 1)
			pfd_read = exec__mid(&cmd[i], pfd_read, x_err);
		else
			exec__last(&cmd[i], pfd_read, x_err);
		if (x_err->code != ERR_NONE)
			return (false);
		i++;
sleep(1);
	}
	return (true);
}

static int	exec__first(t_cmd *first_cmd, t_x_err *x_err)
{
	int	pfd[2];

	pipe(pfd);
	first_cmd->pid = fork();
	if (first_cmd->pid == 0)
	{
		first_cmd->fd_in = open(first_cmd->infile, O_RDONLY);
		dup2(first_cmd->fd_in, STDIN_FILENO);
		dup2(pfd[WRITE_TO], STDOUT_FILENO);
		close(first_cmd->fd_in);
		close(pfd[READ_FROM]);
		close(pfd[WRITE_TO]);
		// Check mit access
		execute(first_cmd->av, first_cmd->path, x_err);
		//-1 ...  
	}
	close(pfd[WRITE_TO]);
	return (pfd[READ_FROM]);
}

static int	exec__mid(t_cmd *mid_cmd, int left_pipe_fd_read, t_x_err *x_err)
{
	int	pfd[2];
// Was wenn left_pipe_fd_read < 0 ????
	pipe (pfd);
	mid_cmd->pid = fork();
	if (mid_cmd->pid == 0)
	{
		dup2(left_pipe_fd_read, STDIN_FILENO);
		dup2(pfd[WRITE_TO], STDOUT_FILENO);
		close (left_pipe_fd_read);
		close(pfd[WRITE_TO]);
		close(pfd[READ_FROM]);
		if (!execute(mid_cmd->av, mid_cmd->path, x_err))
		{
			;  // Handle error
		}
	}
	close (left_pipe_fd_read);
	close (pfd[WRITE_TO]);
	return (pfd[READ_FROM]);
	}

static void	exec__last(t_cmd *last_cmd, int left_pipe_fd_read, t_x_err *x_err)
{
	last_cmd->pid = fork();
	if (last_cmd->pid == 0)
	{
		last_cmd->fd_out = open(last_cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(last_cmd->fd_out, STDOUT_FILENO);
		dup2(left_pipe_fd_read, STDIN_FILENO);
		close (last_cmd->fd_out);
		close (left_pipe_fd_read);
		execute(last_cmd->av, last_cmd->path, x_err);
	}
	close (left_pipe_fd_read);
}



// static int	exec__first(t_cmd first_cmd, t_x_err *x_err)
// {
// 	int	pfd[2];

// 	// TODO Safty checks with access...
// 	// TODO look in path if not found...
// 	// TODO check if a directory was provided (use open ( O_DIRECTORY)?!)
// 	if (pipe(pfd) == -1)
// 	{
// 		close(first_cmd.fd_in);
// 		first_cmd.fd_in = -1;
// 		return (*x_err = x_error(ERR_OPEN, errno, "exec__first"), -1);
// 	}
// 	first_cmd.pid = fork();
// 	if (first_cmd.pid == -1)
// 	{
// 		close(pfd[READ_FROM]);
// 		close(pfd[WRITE_TO]);
// 		close(first_cmd.fd_in);
// 		first_cmd.fd_in = -1;
// 		return (*x_err = x_error(ERR_FORK, errno, "exec__first"), -1);
// 	}
// 	if (first_cmd.pid == 0)
// 	{
// 		first_cmd.fd_in = open(first_cmd.infile, O_RDONLY);
// 		if (first_cmd.fd_in == -1)
// 			return (*x_err = x_error(ERR_OPEN, errno, "exec__first"), -1);
// 		if (dup2(pfd[WRITE_TO], STDOUT_FILENO) < 0)
// 		{
// 			close(pfd[READ_FROM]);
// 			close(pfd[WRITE_TO]);
// 			close(first_cmd.fd_in);
// 			first_cmd.fd_in = -1;
// 			return (*x_err = x_error(ERR_DUP, errno, "exec__first"), -1);
// 		}
// 		close(pfd[READ_FROM]);
// 		close(pfd[WRITE_TO]);
// 		close(first_cmd.fd_in);
// 		execv(first_cmd.av[0], first_cmd.av);
// 		return (*x_err = x_error(ERR_EXECV, errno, "exec__first"), -1);
// 	}
// 	close(pfd[WRITE_TO]);
// 	close(first_cmd.fd_in);
// 	return (pfd[READ_FROM]);
// }

// static int	exec__mid(t_cmd mid_cmd, int fd_read, t_x_err *x_err)
// {
// 																		return (0);
// }

// static void	exec__last(t_cmd last_cmd, int fd_read, t_x_err *x_err)
// {
// 	last_cmd.fd_out = open(last_cmd.outfile, O_WRONLY | O_CREAT);
// 	if (last_cmd.fd_out == -1)
// 	{
// 		*x_err = x_error(ERR_CLOSE, errno, "exec__last");
// 		return ;
// 	}
// 	last_cmd.pid = fork();
// 	if (last_cmd.pid == -1)
// 	{
// 		close(fd_read);
// 		close (last_cmd.fd_out);
// 	}
// 	if (last_cmd.pid == 0)
// 	{
// 		if (dup2(fd_read, STDIN_FILENO) < 0)
// 		{
// 			close(fd_read);
// 			close(last_cmd.fd_out);
// 			last_cmd.fd_out = -1;
// 			*x_err = x_error(ERR_DUP, errno, "exec__last");
// 			return ;
// 		}
// 		close(fd_read);
// 		execv(last_cmd.av[0], last_cmd.av);
// 		*x_err = x_error(ERR_EXECV, errno, "exec__last");
// 		return ;
// 	}
// 	close(fd_read);
// 	close(last_cmd.fd_out);
// 	last_cmd.fd_out = -1;
// }
