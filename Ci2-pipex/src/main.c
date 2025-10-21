/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/21 11:19:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

static int	wait__without_creating_zombies(pid_t pid_last_cmd);

/**
 * @brief The entry point and dirigent for the pipex programm ...
 * @note A note 
 * @note For building the documentation from comment blocks like this one run
 *         make doc; open doc/html/index.html
 * @param[in] argc The number of arguments handed over by the calling shell
 * @param[in] argv argv[0], argv[1], ... argv[argc - 1] are pointers to strings
 *                  containing the programms name and the command-line arguments
 *                  passed to the program.
 * @param[in] envp Well similar but for the environment variables.
 * @return a return code indicating success or an error.
 */
int	main(int argc, char **argv, char**envp)
{
	t_data	data;
	t_x_err	x_err;
	pid_t	pid_last_cmd;
	int		termination_status_last_cmd;

	pid_last_cmd = -1;
	x_err = x_error(ERR_NONE, 0, "main");
	if (!parse(argc, argv, &data, &x_err)
		|| !parse_path(envp, data.num_cmds, data.cmd, &x_err)
		|| !exec_pipeline(data.cmd, data.num_cmds, &pid_last_cmd, &x_err))
		return (handle_error(x_err));
printf("data.n_cmds:      |%zu|\n", data.num_cmds);
printf("data.cmd:         |%p|\n", data.cmd);
printf("data.cmd->infile: |%s|\n", data.cmd[0].infile);
printf("data.cmd->outfile:|%s|\n", data.cmd[0].outfile);
printf("data.cmd->infile: |%s|\n", data.cmd[1].infile);
printf("data.cmd->outfile:|%s|\n", data.cmd[1].outfile);
printf("data.cmd->av:     |%p|\n", data.cmd[0].av);
printf("                  |%s|\n", data.cmd[0].av[0]);
printf("                  |%s|\n", data.cmd[0].av[1]);
printf("data.cmd->av:     |%p|\n", data.cmd[0].av);
printf("                  |%s|\n", data.cmd[1].av[0]);
printf("                  |%s|\n", data.cmd[1].av[1]);
printf("data.cmd->path:   |%p|\n", data.cmd[0].path);
printf("                  |%s|\n", data.cmd[1].path[0]);
printf("                  |%s|\n", data.cmd[1].path[1]);
printf("                  |%s|\n", data.cmd[1].path[1]);
printf("                  |%s|\n", data.cmd[1].path[2]);
printf("                  |%s|\n", data.cmd[1].path[3]);
printf("                  |%s|\n", data.cmd[1].path[4]);
printf("                  |%s|\n", data.cmd[1].path[5]);
printf("                  |%s|\n", data.cmd[1].path[6]);
printf("                  |%s|\n", data.cmd[1].path[7]);
printf("                  |%s|\n", data.cmd[1].path[8]);
printf("                  |%s|\n", data.cmd[1].path[9]);

printf("                  |%s|\n", data.cmd[1].path[10]);
printf("                  |%s|\n", data.cmd[1].path[11]);
printf("                  |%s|\n", data.cmd[1].path[11]);
printf("                  |%s|\n", data.cmd[1].path[12]);
printf("                  |%s|\n", data.cmd[1].path[13]);
printf("                  |%s|\n", data.cmd[1].path[14]);
printf("                  |%s|\n", data.cmd[1].path[15]);
printf("                  |%s|\n", data.cmd[1].path[16]);
printf("                  |%s|\n", data.cmd[1].path[17]);
printf("                  |%s|\n", data.cmd[1].path[18]);
printf("                  |%s|\n", data.cmd[1].path[19]);
printf("                  |%s|\n", data.cmd[1].path[20]);
printf("                  |%s|\n", data.cmd[1].path[21]);
printf("                  |%s|\n", data.cmd[1].path[21]);
printf("                  |%s|\n", data.cmd[1].path[22]);
printf("                  |%s|\n", data.cmd[1].path[23]);
printf("                  |%s|\n", data.cmd[1].path[24]);
printf("                  |%s|\n", data.cmd[1].path[25]);
printf("                  |%s|\n", data.cmd[1].path[26]);
printf("                  |%s|\n", data.cmd[1].path[27]);
printf("                  |%s|\n", data.cmd[1].path[28]);
printf("                  |%s|\n", data.cmd[1].path[29]);

printf("                  |%s|\n", data.cmd[1].path[30]);
printf("                  |%s|\n", data.cmd[1].path[31]);
printf("                  |%s|\n", data.cmd[1].path[31]);
printf("                  |%s|\n", data.cmd[1].path[32]);
printf("                  |%s|\n", data.cmd[1].path[33]);
printf("                  |%s|\n", data.cmd[1].path[34]);
printf("                  |%s|\n", data.cmd[1].path[35]);
printf("                  |%s|\n", data.cmd[1].path[36]);
printf("                  |%s|\n", data.cmd[1].path[37]);
printf("                  |%s|\n", data.cmd[1].path[38]);
	termination_status_last_cmd = wait__without_creating_zombies(pid_last_cmd);
	final_free(data);
	return (termination_status_last_cmd);
}
/**
 * @note Neither the flags WUNTRACED nor WCCONTINUED are given as option to 
         to waitpid.
         Thus the *wait status* set by waitpid covers exactly the
         *termination status* of the child process for the last command, cf.
         Kerrisk (The Linux Programming Interface, Sec. 26.1.3
         "The Wait Status Value", p. 545).
 * @note @code waitpid(-1, &termination_status, 0); @endcode is equivalent to
 *       @code wait(&termination_status); @endcode
 */
static int	wait__without_creating_zombies(pid_t pid_last_cmd)
{
	pid_t	pid;
	int		wstatus;
	int		status_last_cmd;

	pid = 1;
	wstatus = 0;
	status_last_cmd = 0;
	while(pid > 0)
	{
		pid = waitpid(-1, &wstatus, 0);
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}