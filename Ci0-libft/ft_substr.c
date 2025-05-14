/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:51:17 by reciak            #+#    #+#             */
/*   Updated: 2025/05/14 21:35:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 * @brief Stores the definition of ft_substr
 */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
 *        substring from the string ’s’.
 *        The substring starts at index ’start’ and has a
 *        maximum length of ’len’, cf. Libft Subject (Version 16.7).
 * @note The subject strange has different data types for start and len.
 * @param[in] s: The original string from which to create the substring.
 * @param[in] start: The starting index of the substring within ’s’.
 * @param[in] len: The maximum length of the substring.
 * @return 
 *          * A pointer to the start of the substring.
 *          * `NULL`, if the allocation fails or startindex goes beyond
 *            the nullterminator of \p s .
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (si_substr(s, (size_t)start, len));
}

/**
 * @brief The same as ft_substr(), with the only exception that 
 *        the variable \p start is declared as size_t instead of unsigned int
 * @param[in] s: The original string from which to create the substring.
 * @param[in] start: The starting index of the substring within ’s’.
 * @param[in] len: The maximum length of the substring.
 * @return
 *          * A pointer to the start of the substring.
 *          * `NULL`, if the allocation fails or startindex goes beyond
 *            the nullterminator of \p s .
 */
char	*si_substr(char const *s, size_t start, size_t len)
{
	size_t	bytes_to_copy;
	char	*substr;
	char	*walker;

	bytes_to_copy = si_min(ft_strlen(s + start), len);
	if (start > ft_strlen(s) || si_is_overflow(bytes_to_copy, '+', 1))
		return (NULL);
	substr = malloc(bytes_to_copy + 1);
	if (substr == NULL)
		return (NULL);
	walker = substr;
	s += start;
	while (bytes_to_copy > 0)
	{
		*walker = *s;
		walker++;
		s++;
		bytes_to_copy--;
	}
	*walker = '\0';
	return (substr);
}
