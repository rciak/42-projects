/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:54:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/26 18:13:46 by reciak           ###   ########.fr       */
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
	//
	print_err(&err);
	set_err(&err, E_ARGC, 2, "main");
	print_err(&err);
	//
	set_err(&err, E_NONE, errno, "main");
	print_err(&err);
write(35535, "Wuff", 5);
	set_err(&err, E_ARGC, errno, "main: Sorry E_ARGC for the missnomer");
	print_err(&err);
//
write(35535, "Miau", 5);
	set_err(&err, E_NONE, errno, "main");
	print_err(&err);
//
	set_err(&err, E_NONE, 0, "main: This should not be printed");
	print_err(&err);
}

