/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_uninit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:55:06 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 12:55:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file calloc_uninit.c
 * @brief Stores the definition of calloc_uninit
 */

#include "libft.h"

/**
 * @brief Like ft_calloc() except that there is no initalizing with ft_bzero().
 * @note For more *details* and *warnings* see the docu of ft_calloc().
 * @param[in] nmemb the number of units (members)
 * @param[in] size the number of bytes occupied by a single unit
 * @return
 *          * NULL in case of error (or if malloc(0) returns NULL),
 *          * a pointer to the start of the allocated memory block.
 */
void	*calloc_uninit(size_t nmemb, size_t size)
{
	if (si_is_overflow(nmemb, '*', size))
		return (NULL);
	return (malloc(nmemb * size));
}
