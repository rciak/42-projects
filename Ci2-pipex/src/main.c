/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/05 17:48:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

static	bool	verbose__add(unsigned int a, unsigned int b, t_err *err);

/**
 * @brief The entry point and dirigent for the pipex programm ...
 * @note A note 
 * @note A yes: run
 *         make doc; open doc/html/index.html
 * @param[in]  argc The number of arguments handed over by the calling shell
 * @param[in] argv argv[0], argv[1], ... argv[argc - 1] are pointers to strings
 *                  containing the programms name and the command-line arguments
 *                  passed to the program.
 * @param[in] envp Well similar but for the environment variables.
 * @return 
 *          * 
 *          * 
 */
int	main(int argc, char **argv, char**envp)
{
	t_err	err;

	err = error(ERR_NONE);
	(void) argc;
	(void) argv;
	(void) envp;
	hello();
	if (verbose__add(1, UINT_MAX - 1, &err) == false)
		ft_putstr_fd("main --> stderr: Something wrong. \n\n", STDERR_FILENO);
	else
		ft_putstr_fd("main --> stdout: Ok. \n\n", STDOUT_FILENO);
	if (verbose__add(1, UINT_MAX, &err) == false)
		ft_putstr_fd("main --> stderr: Something wrong. \n\n", STDERR_FILENO);
	else
		ft_putstr_fd("main --> stdout: Ok. \n\n", STDOUT_FILENO);
	bye();
	return (err.code);
}

static	bool	verbose__add(unsigned int a, unsigned int b, t_err *err)
{
	unsigned int	sum;
	bool			re_val;

	sum = add_with_overflow_indicator(a, b, err);
	if (err->code == ERR_NONE)
		re_val = true;
	else
		re_val = false;
	printf("a:         %u\n", a);
	printf("b:         %u\n", b);
	printf("sum:       %u\n", sum);
	printf("err->code: %d\n", err->code);
	printf("err->msg:  %s\n", err->msg);
	printf("re_val:    %d\n", re_val);
	printf("Well the rest is left to main ...\n");
	return (re_val);
}
