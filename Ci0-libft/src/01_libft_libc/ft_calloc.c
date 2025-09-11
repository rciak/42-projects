/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:15 by reciak            #+#    #+#             */
/*   Updated: 2025/05/17 17:21:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @brief Stores the definition of ft_calloc
 */

#include "libft.h"

/**
 * @brief Memory allocation with subsequent zeroing, cf.
 *        [calloc](https://man7.org/linux/man-pages/man3/calloc.3.html).
 * @note It is specially tailored / convenient for allocation of arrays
 *       of \p nmemb units consiting of `size` bytes each.
 * @note The multiplication `nmemb * size` is checked for overflow and
 *       `NULL` is returned in case.
 * @note `errno` is at least not directly set by ft_calloc in case of an error,
 *       maybe though by the used `malloc`.
 * @param[in] nmemb the number of units (members)
 * @param[in] size the number of bytes occupied by a single unit
 * @return
 *          * NULL in case of error (or if malloc(0) returns NULL),
 *          * a pointer to the start of the allocated memory block.
 * @warning The man page of 
 *          [malloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
 *          indicates that `NULL` *might potentially* be returned 
 *          by a successful call `malloc(0)`.
 * @warning Consequently a return value `NULL` can only safely serve as
 *          an indicator of an error, 
 *          iff more than 0 bytes were requested.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = calloc_uninit(nmemb, size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

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
