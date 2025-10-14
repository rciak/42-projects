/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:24:12 by reciak            #+#    #+#             */
/*   Updated: 2025/10/14 20:27:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

Test(ft_strlcpy, enough_space) {
	char dest[] = "--------";
	unsigned int ret = ft_strlcpy(dest, "1234", 6);
	cr_assert(eq(str, dest, "1234\0---\0"));
	cr_assert(eq(int, ret, 4));
}


Test(x_error, errno)
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