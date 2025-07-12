/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:51:52 by reciak            #+#    #+#             */
/*   Updated: 2025/05/30 16:39:20 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 * @brief Stores the definition of ft_memset
 */

#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s 
 *        with the constant byte c, cf.
 *        [memset](https://man7.org/linux/man-pages/man3/memset.3.html).
 * @param[in] s pointer to the memory area to be filled.
 * @param[in] c the byte that shall be copied over the memory area.
 * @param[in] n the number of bytes to be filled.
 * @return s
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c_rightmost_byte;
	unsigned char	*uc_s;

	uc_s = (unsigned char *) s;
	c_rightmost_byte = (unsigned char) c;
	while (n > 0)
	{
		uc_s[n - 1] = c_rightmost_byte;
		n--;
	}
	return (s);
}
