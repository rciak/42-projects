/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:18:44 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 00:20:14 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @brief Stores the definition of ft_strchr
 */

#include "libft.h"

/**
 * @brief Finds the first occurence of a character in a string, cf.
 *        [strchr](https://man7.org/linux/man-pages/man3/strchr.3.html).
 * @param[in] s The string to investigate
 * @param[in] c The character to be found
 * @note \p c may be the null byte. In this case strchr
 *            returns the address of it (as nullterinator of s).
 * @return 
 *          * Address of the first occurence of \p c, if any.
 *          * `NULL` if \p s does not contain the character \p c.
 */
char	*ft_strchr(const char *s, int c)
{
	const char c_c = (char) c;

	while (*s != c_c && *s)
		s++;
	if (*s == c_c)
		return ((char *) s);
	return (NULL);
}
