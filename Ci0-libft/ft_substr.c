/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:51:17 by reciak            #+#    #+#             */
/*   Updated: 2025/05/24 21:53:58 by reciak           ###   ########.fr       */
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
 * @note The subject strangely has different data types for start and len.
 * @remark It felt somewhat undefined what should happen / be returned 
 *         in the case `start > ft_strlen(s)`.
 *         The resulting substring would be the empty string, provided
 *         one would agree to the following notion forming.
 * @remark **Definition:** 
 *         Let `s` be a C-string of length n (0 <= n <= SIZE_MAX - 1), i.e.
 *         a sequence 
 *         `s[0], s[1], ..., s[n - 1]`, @c '\0'
 *         of ASCII characters such that  
 *         `s[i] !=` @c '\0' for all indices i with  `0 <= i <= n - 1`.
 *         Define the *substring* `s_k` of `s` with *starting index*
 *         `k`, `0 <= k <= SIZE_MAX - 1`, to be the sequence
 *         @code s[k], s[k + 1], ..., s[n - 1], '\0'. @endcode
 * @remark Accepting this definition yields that s_k is the empty string '\0'
 *         whenever k >= n.
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
