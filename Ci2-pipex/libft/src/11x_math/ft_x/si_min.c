/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:29:36 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 19:30:59 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file si_min.c
 * @brief Stores the definition of si_min()
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
