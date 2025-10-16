/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:24:12 by reciak            #+#    #+#             */
/*   Updated: 2025/10/15 10:11:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

// With big contribution of perplexity for saving time



// Test(parse, two_cmds_no_params)
// {
// 	int		argc = 5;
// 	char	*argv[] = {"./pipex", "Makefile", "ls", "wc", "outfile", NULL};
// 	t_data	data, data_expeted;
// 	t_x_err	x_err;

// 	x_err = x_error(ERR_NONE, 0, "main");
// 	parse(argc, argv, &data, &x_err);

// 	static char *cmd1_av[] = { "ls", NULL };
// 	static char *cmd2_av[] = { "wc", NULL };
// 	t_parse_unit expected_cmds[] = {
// 		{
// 			.redir = {"Makefile", NULL},
// 			.av = cmd1_av,
// 			.ac = 1,
// 		},
// 		{
// 			.redir = {NULL, "outfile"},
// 			.av = cmd2_av,
// 			.ac = 1,
// 		}
// 	};
// 	t_data data_expected = {
// 		.ac_cmd = 2,
// 		.cmd = expected_cmds
// 	};
// 	cr_assert(eq_data(&data, &data_expected));
// }
