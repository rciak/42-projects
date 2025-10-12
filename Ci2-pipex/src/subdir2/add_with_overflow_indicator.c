/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_with_overflow_indicator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:17:43 by reciak            #+#    #+#             */
/*   Updated: 2025/10/05 17:44:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file add_with_overflow_indicator.c
 * @brief Stores the definition of add_with_overflow_indicator()
 */

#include "pipex.h"

/**
 * @brief Adds two unsigned integers (setting a flag on overflow)
 * @param[in] a The first number
 * @param[in] b The second number
 * @param[out] err: A pointer to a caller's variable for error indication
 * @return The (potentially overflown) sum of \p a and \p b
 */
unsigned int	add_with_overflow_indicator(
	unsigned int a,
	unsigned int b,
	t_err *err)
{
	unsigned int	sum;

	sum = a + b;
	if (sum < a)
		*err = error(ERR_OVERFLOW);
	else
		*err = error(ERR_NONE);
	return (sum);
}
