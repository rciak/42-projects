/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_math01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:02 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 00:23:29 by reciak        ###   ########.fr       */
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
