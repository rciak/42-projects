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
bool eq_parse_unit(const t_parse_unit *p1, const t_parse_unit *p2)
{
fprintf(stderr, "A\n");
fprintf(stderr, "p1->ac\n");

    if (p1->ac != p2->ac) {
        fprintf(stderr, "ac mismatch: %zu vs %zu\n", p1->ac, p2->ac);
        return false;
    }
fprintf(stderr, "B\n");
    for (size_t i = 0; i < 2; i++) {
fprintf(stderr, "i: %zu\n", i);
        if ((p1->redir[i] == NULL) != (p2->redir[i] == NULL)) {
            fprintf(stderr, "redir[%zu] null mismatch: %p vs %p\n",
                    i, (void*)p1->redir[i], (void*)p2->redir[i]);
            return false;
        }
        if (p1->redir[i] && p2->redir[i] && ft_strcmp(p1->redir[i], p2->redir[i]) != 0) {
            fprintf(stderr, "redir[%zu] mismatch: '%s' vs '%s'\n",
                    i, p1->redir[i], p2->redir[i]);
            return false;
        }
    }

    if (p1->ac > 0) {
        if (p1->av == NULL || p2->av == NULL) {
            fprintf(stderr, "av pointer null mismatch: %p vs %p\n",
                    (void*)p1->av, (void*)p2->av);
            return false;
        }
        for (size_t i = 0; i < p1->ac; i++) {
            if ((p1->av[i] == NULL) != (p2->av[i] == NULL)) {
                fprintf(stderr, "av[%zu] null mismatch: %p vs %p\n",
                        i, (void*)p1->av[i], (void*)p2->av[i]);
                return false;
            }
            if (p1->av[i] && p2->av[i] && ft_strcmp(p1->av[i], p2->av[i]) != 0) {
                fprintf(stderr, "av[%zu] mismatch: '%s' vs '%s'\n",
                        i, p1->av[i], p2->av[i]);
                return false;
            }
        }
    }
    return true;
}

bool eq_data(const t_data *data1, const t_data *data2)
{
    if (data1->ac_cmd != data2->ac_cmd) {
        fprintf(stderr, "ac_cmd mismatch: %zu vs %zu\n", data1->ac_cmd, data2->ac_cmd);
        return false;
    }
    for (size_t i = 0; i < data1->ac_cmd; i++) {
        if (!eq_parse_unit(&data1->cmd[i], &data2->cmd[i])) {
            fprintf(stderr, "cmd[%zu] mismatch detected\n", i);
            return false;
        }
    }
    return true;
}
Test(parse, two_cmds_no_params)
{
    int     argc = 5;
    char    *argv[] = {"./pipex", "Makefile", "ls", "wc", "outfile"};
    t_data  data = {0};
    t_x_err x_err = x_error(ERR_NONE, 0, "main");

    static char *cmd1_av[] = { "ls", NULL };
    static char *cmd2_av[] = { "wc", NULL };
    t_parse_unit expected_cmds[] = {
        {
            .redir = {"Makefile", NULL},
            .av = cmd1_av,
            .ac = 1,
        },
        {
            .redir = {NULL, "outfile"},
            .av = cmd2_av,
            .ac = 1,
        }
    };
    t_data data_expected = {
        .ac_cmd = 2,
        .cmd = expected_cmds
    };
	fprintf(stderr, "Before calling parse\n");
    bool parse_result = parse(argc, argv, &data, &x_err);
	fprintf(stderr, "After calling parse\n");
    cr_assert(eq_data(&data, &data_expected), "Parsed data does not match expected");
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
