/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:54:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 16:28:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

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
	t_err	err;
	t_data	data;
	pid_t	pid_last_cmd;
	int		termination_status_last_cmd;

	set_err(&err, E_NONE, 0, "main");
	if (!parse_argv(argc, argv, &data, &err))
		print_exit_msg_and_exit(&err);
	if (!parse_path(envp, data.num_cmds, data.cmd, &err))
		h_err_exit(data.num_cmds, data.cmd, &err);
	
	printf("\ndata.n_cmds:         |%zu|\n\n", data.num_cmds);
	int i = 0;
	int j;
	while (i < (int) data.num_cmds)
	{
		printf("data.cmd[%d]->infile: |%s|\n", i, data.cmd[i].infile);
		printf("data.cmd[%d]->outfile:|%s|\n", i, data.cmd[i].outfile);
		printf("data.cmd[%d]->av:     |%p|\n", i, data.cmd[i].av);
		j = 0;
		while (j < (int) data.cmd[i].ac + 1)
		{
			printf("                        |%s|\n", data.cmd[i].av[j]);
			j++;
		}
		printf("data.cmd[%d]->ac:     |%zu|\n", i, data.cmd[i].ac);
		while (*data.cmd[i].path != NULL)
		{
			printf("data.cmd[%d]->path:     |%s|\n", i, *data.cmd[i].path);
			data.cmd[i].path++;
		}
		printf("\n");
		i++;
	}


termination_status_last_cmd = 1;
	tidy_up_all_cmds(data.num_cmds, data.cmd, &err);
	return (termination_status_last_cmd);

}

