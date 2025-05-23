/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:51:52 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 21:51:57 by reciak           ###   ########.fr       */
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
	t_uchar	least_significant_byte_of_c;
	t_uchar	*uc_s;

	uc_s = (t_uchar *) s;
	least_significant_byte_of_c = (t_uchar) c;
	while (n > 0)
	{
		uc_s[n - 1] = least_significant_byte_of_c;
		n--;
	}
	return (s);
}
