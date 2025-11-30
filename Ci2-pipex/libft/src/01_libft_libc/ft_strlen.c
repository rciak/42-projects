/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:24:05 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:04:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @brief Stores the definition of ft_strlen()
 */

#include "libft.h"

/**
 * @brief Counts the length of given string, cf.
 * [strlen](https://man7.org/linux/man-pages/man3/strlen.3.html)
 * @param[in] s pointer to a nullterminated string whose length shall be found.
 * @note If \p s is `NULL` then `ft_strlen` will segfault - this is intended.
 * @note A generalized version of ft_strlen() is strlen_deli() where
 *       counting can stop before the nullterminator if other addional
 *       delimiters are hit. (In
 *       commit f67e5c93ae1075d6a6dc969e8261e5d063186a4b
 *       it has been moved to the subfolder `side_products`)
 * @remark The number `ft_strlen(s)` can be viewed in different ways:
 *         * As *length* of the string s,
 *         * As *index of the Nullterminator* of s.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
	printf("abc:%zu",strlen("abc"));
	printf(":%zu",strlen(""));
	printf("Newline should trigger writting. Please comment this line out.\n");
	printf("NULL:%zu",strlen(NULL));
}
*/
