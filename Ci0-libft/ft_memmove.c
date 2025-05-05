/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:57 by reciak            #+#    #+#             */
/*   Updated: 2025/05/05 19:04:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @brief Stores the definition of ft_memmove
 */

#include "libft.h"

/**
 * @brief , cf.
 *        [](https://man7.org/linux/man-pages/man3/ .html)
 * @note In contrast to memcpy() the copying over still work when the
 *       memory areas do overlap.
 * @warning Still both memory areas should have a length of at least n bytes.
 * @param[in] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @return dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// const uchar	*uc_dest;
	// const uchar	*uc_src;

	
	// uc_dest = (uchar *) dest;
	// uc_src = (uchar *) src;
	// while (n > 0)
	// {
	// 	*uc_dest = *uc_src;
	// 	uc_dest++;
	// 	uc_src++;
	// 	n--;
	// }
	// return (dest);
}