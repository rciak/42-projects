/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:34:47 by reciak            #+#    #+#             */
/*   Updated: 2025/05/23 13:31:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 * @brief Stores the definition of ft_memcmp
 */

#include "libft.h"

/**
 * @brief Comparison of two memory areas; at most n bytes are compared, cf.
 *        [memcmp](https://man7.org/linux/man-pages/man3/memcmp.3.html).
 * @param[in] s1 A void pointer to the starting byte of the first memory area,
 * @param[in] s2 A void pointer to the starting byte of the second memory area.
 * @param[in] n The max. number of bytes to compare
 * @return 
 *          * 0 if the memory areas differ in none of the corresponding bytes,
 *          * The difference of the values of the first non-identical bytes, cf.
 *            the documentation of ft_strncmp().
 * @note If `n == 0` then there are no bytes at all in which the memory areas
 *       can differ, so that the return value is 0 in that case.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc_s1 = (unsigned char *) s1;
	const unsigned char	*uc_s2 = (unsigned char *) s2;

	while (n > 0 && *uc_s1 == *uc_s2)
	{
		uc_s1++;
		uc_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*uc_s1 - *uc_s2);
}
