/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_math01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:02 by reciak            #+#    #+#             */
/*   Updated: 2025/05/24 17:59:53 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_math01.c
 * @brief Stores some usefull math functions
 */

#include "libft.h"

/**
 * @brief Returns the minimum of two values
 * @param[in] a The first value
 * @param[in] b The second value
 * @return `min(a,b)`
 */
size_t	si_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

/**
 * @brief Returns the maximum of two values
 * @param[in] a The first value
 * @param[in] b The second value
 * @return `max(a,b)`
 */
size_t	si_max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

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
