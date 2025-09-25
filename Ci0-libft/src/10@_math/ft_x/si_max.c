/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:29:27 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 19:31:28 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file si_max.c
 * @brief Stores the definition of si_max()
 */

#include "libft.h"

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
