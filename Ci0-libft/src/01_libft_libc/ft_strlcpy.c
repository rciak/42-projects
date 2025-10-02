/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:40:31 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:04:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcpy.c
 * @brief Stores the definition of ft_strlcpy()
 */

#include "libft.h"

/**
 * @brief String copying that respects the available space in the destination,
 *        cf.
 *        [string_copying]
 *          (https://man7.org/linux/man-pages/man7/string_copying.7.html)
 *        and
 *        [strlcpy](https://man.netbsd.org/strlcpy.3).
 *
 * ft_strlcpy() copies a string from src to dest adding a nullterminator,
 * provided that the string plus the nullterminator fits in,
 * i.e. the string is of length < `size`. If though its length is
 * >= `size` then
 * copying will be done as far as possible.
 *        
 * @note 
 *       1. In the boring case `size` == 0 nothing will be done at all;
 *          in particular the string pointed to by dest will not be changed.
 *       2. In the **interesting case `size` > 0** the original string 
 *          will be fully copied and a nullterminator 
 *          added provided that they fit in the destination, 
 *          i.e. the string to be copied is of
 *          length < `size`. Otherwise, i.e. if 
 *          length >= `size` > 0 then `size-1 >= 0` bytes will be copied
 *          and a nullterminator added.
 *
 *          * In particular: If `size == 1` then 0 bytes will be copied and just
 *            a nullterminator set, resulting in an *empty string*.
 * @remark ft_strlcpy is less error prone than `ft_strncpy` (cf. piscine...),
 *       e.g. 
 *       * ft_strlcpy guarantes that the result is nullterminated
 *         (as long as `size > 0`)
 *       * it returns not a pointer but a number that can be used to 
 *         detect if there was not enough space in dest for copying, e.g.
           @verbatim
           if (ft_strlcpy(dest, src, 10) >= 10)
             //react to that unexpected happening.
           @endverbatim
 * @remark According to the [string_copying]
 *          (https://man7.org/linux/man-pages/man7/string_copying.7.html)
 *         man page there are issues with strlcpy and strlcat
 *         @verbatim
             strlcpy(3) and strlcat(3) need to read the entire src string, even
             if the destination buffer is small.  This makes them vulnerable to
             Denial of Service (DoS) attacks if an attacker can control the
             length of the src string.  And if not, they're still unnecessarily
             slow.
           @endverbatim
 * @param[in, out] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @param[in] size Number of bytes that the buffer, pointed to by dest,
 *                 can store - including the terminating null byte!
 * @return The length of the original string pointed to by `src`, i.e. the 
 *         length of the string that was intended to be created.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	bytes_to_copy;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	bytes_to_copy = si_min(src_len, size - 1);
	while (bytes_to_copy > 0)
	{
		*dst = *src;
		dst++;
		src++;
		bytes_to_copy--;
	}
	*dst = '\0';
	return (src_len);
}
