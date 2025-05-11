/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:51:53 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 02:38:49 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @brief Stores the definition of strrchr
 */

#include "libft.h"

/**
 * @brief Finds the last occurence of a character in a string, cf.
 *        [strrchr](https://man7.org/linux/man-pages/man3/strrchr.3.html).
 * @param[in] s The string to investigate
 * @param[in] c The character to be found
 * @note \p c may be the null byte. In this case strchr
 *            returns the address of it (as nullterinator of s).
 *            For this particular case it is neccessary to check the condition
 *            `*s == c` once more before returning.
 * @return 
 *          * Address of the last occurence of \p c, if any.
 *          * `NULL` if \p s does not contain the character \p c.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*candidate;

	candidate = NULL;
	while (*s)
	{
		if (*s == c)
			candidate = s;
		s++;
	}
	if (*s == c)
		candidate = s;
	return ((char *) candidate);
}
