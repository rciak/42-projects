/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:51:52 by reciak            #+#    #+#             */
/*   Updated: 2025/05/05 16:27:29 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 * @brief Stores the definition of 
 */

#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s 
 *        with the constant byte c, cf.
 *        [memset](https://man7.org/linux/man-pages/man3/memset.html)
 * @param[in, out] s pointer to the memory area to be filled.
 * @param[in] c the byte that shall be copied over the memory area.
 * @param[in] n the number of bytes to be filled.
 * @return s
 */
void	*memset(void *s, int c, size_t n)
{
	uchar	least_significant_byte;
	uchar	*uc_s;

	least_significant_byte = (uchar) c;
	while(n > 0)
	{
		
		n--;
	}
	return (s);
}