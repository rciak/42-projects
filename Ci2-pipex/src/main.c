/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/11 11:07:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"
#include <stdio.h>                                           // Forbidden function...

static	bool	verbose__add(unsigned int a, unsigned int b, t_err *err);
static	void	handle__error(t_err err);
static	void	print__numbers_and_their_max(int a, int b);

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

	(void) argc;
	(void) argv;
	(void) envp;
	err = error(ERR_NONE);
	hello();
	print__numbers_and_their_max(1, -3);
	if (verbose__add(1, UINT_MAX - 1, &err) == false)
		return (handle__error(err), err.code);
	if (verbose__add(1, UINT_MAX, &err) == false)
		return (handle__error(err), err.code);
	bye();
	return (err.code);
}

static	bool	verbose__add(unsigned int a, unsigned int b, t_err *err)
{
	unsigned int	sum;
	bool			re_val;

	printf("------------------------ verbose__add -------------------------\n");
	sum = add_with_overflow_indicator(a, b, err);
	if (err->code == ERR_NONE)
		re_val = true;
	else
		re_val = false;
	printf("a:         %u\n", a);
	printf("b:         %u\n", b);
	printf("sum:       %u\n", sum);
	if (re_val == true)
		printf("re_val:    true\n");
	else
		printf("re_val:    false\n");
	fprintf(stderr, "err->code: %d\n", err->code);
	fprintf(stderr, "err->msg:  %s\n", err->msg);
	printf("The error checking and handling is left to main where lives err\n");
	printf("\n");
	return (re_val);
}

static	void	handle__error(t_err err)
{
	printf("------------------------ handle__error ------------------------\n");
	fprintf(stderr, "Error!\n");
	fprintf(stderr, "   Code:      %d\n", err.code);
	fprintf(stderr, "   Message:   %s\n", err.msg);
	fprintf(stderr, "Error handling,\n");
	fprintf(stderr, "   freeing,\n");
	fprintf(stderr, "   closing filedescriptors,\n");
	fprintf(stderr, "   ...\n");
}

static	void	print__numbers_and_their_max(int a, int b)
{
	printf("------------------------ print__numbers_and_their_max ---------\n");
	printf("a:             %d\n", a);
	printf("b:             %d\n", b);
	printf("The bigger is: %d\n", buggy_max(a, b));
	printf("\n");
}
