/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_without_creating_zombies.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:03:04 by reciak            #+#    #+#             */
/*   Updated: 2025/11/24 16:42:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_without_creating_zombies.c
 * @brief Stores the definition of wait_without_creating_zombies()
 */

#include "pipex.h"


/**
 * @brief Waits for the last command to finish such that no zombies are
 *        created.
 * @note @code wait(&termination_status); @endcode is equivalent to
         @code waitpid(-1, &termination_status, 0); @endcode,
         cf. Kerrisk (The Linux Programming Interface, Sec. 26.1.2, p. 544).
         Though the latter was used only in an older version the
         following interesting note to waitpid's last argument is kept:
 * @note Neither the flags WUNTRACED nor WCCONTINUED are given as option to 
         to waitpid.
         Thus the *wait status* set by waitpid covers exactly the
         *termination status* of the child process for the last command, cf.
         Kerrisk (The Linux Programming Interface, Sec. 26.1.3
         "The Wait Status Value", p. 545).
 */
int	wait_without_creating_zombies(pid_t pid_last_cmd)
{
	pid_t	pid;
	int		wstatus;
	int		status_last_cmd;

	pid = 1;
	while (pid > 0)
	{
		pid = wait(&wstatus);
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}


int	wait__without_creating_zombies(pid_t pid_last_cmd)
{
	pid_t	pid;
	int		wstatus;
	int		status_last_cmd;

	pid = 1;
	while (pid > 0)
	{
		pid = wait(&wstatus);
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}
