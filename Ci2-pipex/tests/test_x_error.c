/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:24:12 by reciak            #+#    #+#             */
/*   Updated: 2025/10/16 23:42:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool eq_x_error(const t_x_err *x_err1, const t_x_err *x_err2)
{
	return (x_err1->code == x_err2->code
		&& ft_strcmp(x_err1->msg, x_err2->msg) == 0
		&& x_err1->saved_errno == x_err2->saved_errno
		&& ft_strcmp(x_err1->origin, x_err2->origin) == 0);
}

Test(x_error, errno_test)
{
	t_x_err x_err;

	int i = 0;
	while (i < 133)
	{
		errno = i;
		x_err = x_error(ERR_NONE, errno, "Test x_error...");
		cr_assert(eq(int, x_err.saved_errno, errno));
		i++;
	}
}

Test(x_error, ERRNONE_test)
{
	t_x_err x_err;
	t_x_err expected = {ERR_NONE, errno, "pipex: Success - no error detected",
		"Sample Message"};

cr_log_info("Info -- Arrived in test");
cr_log_warn("Warn -- Arrived in test");
cr_log_error("Error -- Arrived in test");

	x_err = x_error(ERR_NONE, errno, "Sample Message");
	cr_assert(eq_x_error(&x_err , &expected));

	int i = 0;
	while (i < 133)
	{
		errno = i;
		x_err = x_error(ERR_NONE, errno, "Test x_error...");
		cr_assert(eq(int, x_err.saved_errno, errno));
		i++;
	}
}