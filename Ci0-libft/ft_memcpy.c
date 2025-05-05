/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:50:31 by reciak            #+#    #+#             */
/*   Updated: 2025/05/05 18:50:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @brief Stores the definition of ft_memcpy
 */

#include "libft.h"

/**
 * @brief Copies n bytes, cf.
 *        [memcpy](https://man7.org/linux/man-pages/man3/memcpy.html)
 * @warning The memory areas may not overlap! Further both memory areas
 *          should have a length of at least n bytes.
 * @param[in] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @return dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const uchar	*uc_dest;
	const uchar	*uc_src;

	uc_dest = (uchar *) dest;
	uc_src = (uchar *) src;
	while (n > 0)
	{
		*uc_dest = *uc_src;
		uc_dest++;
		uc_src++;
		n--;
	}
	return (dest);
}