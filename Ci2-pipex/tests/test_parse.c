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
void free_parse_data(t_data *data) {
    if (data->cmd) {
        for (size_t i = 0; i < data->n_cmds; i++) {
            free(data->cmd[i].infile);
            free(data->cmd[i].outfile);
            if (data->cmd[i].av) {
                for (size_t j = 0; j < data->cmd[i].ac; j++) {
                    free(data->cmd[i].av[j]);
                }
                free(data->cmd[i].av);
            }
        }
        free(data->cmd);
    }
}

Test(parse, valid_args_pipex_example)
{
    int argc = 6;
    char *argv[] = {"./pipex", "Makefile", "ls", "wc", "outfile", NULL};
    t_data data = {0};
    t_x_err x_err = {0};

cr_log_info("Info -- Arrived in test");

    bool ret = parse(argc, argv, &data, &x_err);

    cr_assert(ret, "parse() should succeed for valid input");
    cr_assert_eq(data.n_cmds, 3, "Expected 3 commands parsed");

cr_log_info("A Info ");

    cr_assert_str_eq(data.cmd[0].infile, "Makefile");
    cr_assert_null(data.cmd[0].outfile);

cr_log_warn("B warn"), cr_log_error("C error");

    cr_assert_null(data.cmd[1].infile);
    cr_assert_null(data.cmd[1].outfile);

cr_log_warn("B warn"), cr_log_error("C error");

    cr_assert_null(data.cmd[2].infile);
    cr_assert_str_eq(data.cmd[2].outfile, "outfile");

    cr_assert_eq(data.cmd[0].ac, 1, "First command argument count");
    cr_assert_str_eq(data.cmd[0].av[0], "ls", "First cmd argument");
    
    cr_assert_eq(data.cmd[1].ac, 1, "Second command argument count");
    cr_assert_str_eq(data.cmd[1].av[0], "wc", "Second cmd argument");

    // Clean up allocated memory to avoid leaks
    free_parse_data(&data);
}


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
