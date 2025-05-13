/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_memtools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:39:15 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 16:18:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_memtools1.c
 * @brief Stores definitions of memory related stuff.
 */

#include "libft.h"

/**
 * @brief Checks if a multiplication of two size_t variables would
 *        result in an overflow.
 * @note The functionality is based on the following assumption on overflow
 *        behaviour of unsigned datatypes, which is backed up by a [gnu page]
 *       (https://www.gnu.org/software/autoconf/manual/autoconf-2.63/html_node
/Integer-Overflow-Basics.html).
 * @note **Assumption:**
 *       If the multiplication would cause an
 *       overflow the result of the multiplication is the mathematical result
 *       of the multiplication taken modulo SIZE_MAX + 1 (usually 2^64).
 * @remark In order to see that
 *         used condition `b == 0 || (a * b) / b == a` is true iff
 *         the multiplication `a * b` of two size_t variables `a` and `b` 
 *         would not overflow note the following:
 *         * The condition is equivalent to
 *           `a == 0 || b == 0 || a == 1 || b == 1 || (a * b) / b == a`
 *         * If `a * b` is not overflowing then that condition is for sure true.
 *         * Assume now to the contrary that `a * b` is overflowing.
 *           Then neccessarily `a >= 2` and `b >= 2`,
 *           so that it remains to show that `(a * b) / b != a`.
 *           We will do this by arguing that actually `(a * b) / b < a`.
 *           DETAILS to be filled in the train ...
 * @param[in] a the first unsigned number (size_t)
 * @param[in] action the desired action; currently expected: '+' or '*'.
 * @param[in] b the second unsigned number (size_t)
 * @return In the irregular case of @c action being neither @c `+` nor @c '*'
 *         ERRUNEXPECTEDVAL is returned, otherwise:
 *          * 0 if there would happen no overflow,
 *          * 1 if there would happen an overflow.
 */
int	si_is_overflow(size_t a, char action, size_t b)
{
	if (action == '+')
	{
		if (a + b >= a)
			return (0);
		return (1);
	}
	else if (action == '*')
	{
		if (b == 0 || (a * b) / b == a)
			return (0);
		return (1);
	}
	return (ERRUNEXPECTEDVAL);
}
