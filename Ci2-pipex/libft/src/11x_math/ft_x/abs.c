/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:29:21 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 19:31:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file abs.c
 * @brief Stores the definition of abs()
 */

#include "libft.h"

/**
 * @brief Returns the absolute value
 * @param[in] n The number whose absolute value is requested.
 * @warning \p n is expected to fulfill
 *          @code INT_MIN + 1 (= -INT_MAX) <= \p n <= INT_MAX @endcode.
 *          If \p n is `INT_MIN` the function was called wrong
 *          and a segfault shall be triggered as warning / to point out that
 *          the call was wrong.
 * @return
 *         * The absolute value of \p n, if \p n is not `INT_MIN`.
 */
int	abs(int n)
{
	char	*i_store_null;

	i_store_null = NULL;
	if (n == INT_MIN)
		i_store_null[0] = *i_store_null;
	if (n < 0)
		return (-n);
	return (n);
}
