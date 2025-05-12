/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_memtools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:39:15 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 00:23:54 by reciak           ###   ########.fr       */
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
 * @param[in] a the first unsigned number (size_t)
 * @param[in] action the desired action, currently only '*' is feasible.
 * @param[in] b the second unsigned number (size_t)
 * @return In the irregular case of @c action @c != @c '*' 
 *         ERRUNEXPECTEDVAL is returned, otherwise:
 *          * 0 if there would happen no overflow,
 *          * 1 if there would happen an overflow.
 */
int	si_is_overflow(size_t a, char action, size_t b)
{
	if (action == '*')
	{
		if (a == 0 || b == 0 || a == 1 || b == 1 || (a * b)/ b == a)
			return (0);
		else
			return (1);
	}
	return (ERRUNEXPECTEDVAL);
}