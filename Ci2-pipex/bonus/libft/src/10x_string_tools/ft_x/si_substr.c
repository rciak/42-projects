/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:38:43 by reciak            #+#    #+#             */
/*   Updated: 2025/09/27 20:44:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file si_substr.c
 * @brief Stores the definition of si_substr()
 */

#include "libft.h"

/**
 * @brief The same as ft_substr(), with the only exception that 
 *        the variable \p start is declared as size_t instead of unsigned int
 * @note Cf. also the remark to ft_substr().
 * @note The expression `ori_len - start` is logically equivalent to the more 
 *       obvious expresion `ft_strlen(s + start)`. Still the first expression
 *       was chosen in order to avoid an 
 *       unnecessary second call call to ft_strlen
 *       (without the need to rely on compiler optimization).
 * @note One can argue if the two lines
 *       @code
 *       if (si_is_overflow(bytes_to_copy, '+', 1))
 *		  return (NULL);
 *       @endcode
 *       should be in the implementation or not. Recall for the following that
 *       a `size_t` variable can store 1+SIZE_MAX values, the value 
 *       0 being the first and smallest value, the value 1 being the second, ...
 *       the last value SIZE_MAX being the (SIZE_MAX + 1)-th and largest value.
 *       Therefore the *size* of a C string (i.e. its length + 1 byte for its
 *       nullterminator) can be at most SIZE_MAX bytes, since higher values
 *       can not any more be respresented by a size_t variable.
 * @note Assuming such a **regular** C string the check could be ommited,
 *       since then  
 *       `bytes_to_copy <= orilen <= SIZE_MAX - 1`, such that  
 *       `bytes_to_copy + 1 <= (SIZE_MAX - 1) + 1 <= SIZE_MAX`,  
 *       so that adding 1 to bytes_to_copy does not cause an overflow.
 *       (This come as no surprise: A regular C string
 *       (including its nullterminator) is "small" enough that it can
 *       - in principle -
 *       be allocated with malloc; then of course the same holds true
 *       for its substrings)
 * @note If though the Nullterminator is placed irregularly only
 *       one byte after the SIZE_MAX-th byte of the string then
 *       ft_strlen() would theoretically return the value `SIZE_MAX`,
 *       making the check meaningful.
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
	size_t	ori_len;
	size_t	bytes_to_copy;
	char	*substr;
	char	*writer;

	ori_len = ft_strlen(s);
	if (start >= ori_len)
		return (ft_strdup(""));
	bytes_to_copy = si_min(ori_len - start, len);
	if (si_is_overflow(bytes_to_copy, '+', 1))
		return (NULL);
	substr = malloc(bytes_to_copy + 1);
	if (substr == NULL)
		return (NULL);
	writer = substr;
	s += start;
	while (bytes_to_copy > 0)
	{
		*writer = *s;
		writer++;
		s++;
		bytes_to_copy--;
	}
	*writer = '\0';
	return (substr);
}
