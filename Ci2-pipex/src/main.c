/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/20 11:31:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

static int handle__error(t_x_err x_err);

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

	pid_last_cmd = -1;
	x_err = x_error(ERR_NONE, 0, "main");
	if (!parse(argc, argv, &data, &x_err)
		|| !extract_path(envp, data.cmd)
		|| !exec_pipeline(data.cmd, data.num_cmds, &pid_last_cmd, &x_err))
		return (handle__error(x_err));
	wait_without_creating_zombies(pid_last_cmd);
	final_free(data);
	return (EXIT_OK);
}

static int handle__error(t_x_err x_err)
{
	if (x_err.code == ERR_NONE)
		return (EX_OK);
	else
}