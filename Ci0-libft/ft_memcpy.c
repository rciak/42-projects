/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:50:31 by reciak            #+#    #+#             */
/*   Updated: 2025/05/30 16:18:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @brief Stores the definition of ft_memcpy
 */

#include "libft.h"

/**
 * @brief Copies n bytes assuming that the memory areas do not overlap, cf.
 *        [memcpy](https://man7.org/linux/man-pages/man3/memcpy.3.html)
 * @warning If the ammsumption of memory areas do overlap is violated the 
 *          copying process is can totally go wrong. Consider using ft_memmove()
 *          in this case.
 * @warning Further both memory areas should have a length of at least n bytes.
 * @param[in] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @param[in] n number of bytes to be copied
 * @return dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*uc_dest;
	const unsigned char		*uc_src = (unsigned char *) src;

	uc_dest = (unsigned char *) dest;
	while (n > 0)
	{
		*uc_dest = *uc_src;
		uc_dest++;
		uc_src++;
		n--;
	}
	return (dest);
}
