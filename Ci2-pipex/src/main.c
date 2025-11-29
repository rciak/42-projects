/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:21:39 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 17:26:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"

static void	pre__init_data(t_data *data, int argc);

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

static void	handle__argc_error_separately(void);

int	main(int argc, char **argv, char**envp)
{
	t_data	data;
	int		termination_status_last_cmd;

	if (argc < 1 + 4)
		handle__argc_error_separately();
	pre__init_data(&data, argc);
	parse_argv(argc, argv, &data);
	parse_path(envp, &data);
	termination_status_last_cmd
		= exec_pipeline(&data, envp);
	do_final_nonsense_tidy_up(&data);
	return (termination_status_last_cmd);
}

static void	handle__argc_error_separately(void)
{
	out_str_fd("Wrong number of arguments\n", STDERR_FILENO);
	exit(EX_USAGE);
}

static void	pre__init_data(t_data *data, int argc)
{
	int	i;

	data->i_cmd_err = UNUSED;
	data->num_cmds = argc - 3;
	data->cmd = malloc(data->num_cmds * sizeof (*data->cmd));
	if (data->cmd == NULL)
		exit_on(E_ALLOC, errno, "pre__init_data", NULL);
	i = 0;
	while (i < data->num_cmds)
	{
		data->cmd[i].ac = 0;
		data->cmd[i].av = NULL;
		data->cmd[i].pathname = NULL;
		data->cmd[i].pathname_first_match = NULL;
		data->cmd[i].infile = NULL;
		data->cmd[i].outfile = NULL;
		data->cmd[i].fd_in = UNUSED;
		data->cmd[i].fd_out = UNUSED;
		data->cmd[i].pid = UNUSED;
		i++;
	}
	data->path = NULL;
}
