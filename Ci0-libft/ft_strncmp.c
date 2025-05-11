/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:27:37 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 16:04:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 * @brief Stores the definition of ft_strncmp
 */

#include "libft.h"

/**
 * @brief Comparison of two strings, up to (max.) their first n bytes, cf.
 *        [strncmp](https://man7.org/linux/man-pages/man3/strncmp.3.html).
 * @note More precise this means the following: Let `l1 = strlen(s1)`,
 *         `l2 = strlen(s2)` and `I := min (l1, l2, n)`.
 *         If
 * ```math
 *    s1[i] == s2[i] for all i in 0, 1, ..., I - 1    (*)
 * ```
 *         then strncmp regards the s1 and s2 to be equal.
 *         If otherwise there is a smallest i0 in 0, 1, ..., I - 1 such that
 * ```math
 *    s1[i0] != s2[i0] 
 *      and                                           (**)
 *    s1[i] == s2[i] for all i in 0, 1, ..., i0 - 1 
 * ```
 *          then the sign of s1[i0] - s2[i0] determines whether
 *          strncmp regards s1 as smaller or bigger than s2.
 * @remark When two **unsigned chars** a and b are substracted C 
 *         seems to do the following:
 *       * a and b are casted first into ints (provided that data type int
 *         is large enough to store all unsigned chars values,
 *         which should usually be the case)
 *       * these ints are substracted and the result is again interpreted
 *         as an int
 * @remark Bytes are interpreted as unsigned chars.
 * @param[in] s1 The first string
 * @param[in] s2 The second string
 * @param[in] n The maximal number of bytes / characters to be compared
 * @return 
 *          * 0 if the strings are equal in their (at most) first n bytes,
 *            i.e. (\*) holds true.
 *          * s1[i0] - s2[i0] else, i.e. (\*\*) holds true
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
