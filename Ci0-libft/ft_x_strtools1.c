/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_strtools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:15:36 by reciak            #+#    #+#             */
/*   Updated: 2025/05/17 18:56:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_strtools1.c
 * @brief Stores the definitions of some useful functions in the string context.
 */

#include "libft.h"

/**
 * @brief Tell whether a character is in a string or not.
 * @note `is_in(c, str)` can in general not be replaced by the condition
 *       `ft_strchr(str, (int) c) != NULL` as setting \p c to the
 *       *nullterminator* illustrates:
 * @note Consider this particular choice for `c` e.g. for `str = "0123456789"`.
 *       Then
 *       `is_in(c, "01234567889")` returns *false*,
 *       whereas the condition `ft_strchr(str, (int) c) != NULL` would be
 *       *true*, since `ft_strchr((int) c, "01234566789")`
 *       would return the address of the 
 *       nullterminator of "0123456789", being different from `NULL`!
 * @param[in] c A character of interest
 * @param[in] str A pointer to string that should be scanned for \p c.
 * @return 
 *          * true, if \p str contains \p c *before* the terminating  nullbyte.
 *          * false, if \p str does not contain \p c *before*
 *            the terminating nullbyte.
 */
bool	is_in(char c, const char *str)
{
	if (c == '\0')
		return (false);
	return (ft_strchr(str, (int) c) != NULL);
}

/**
 * @brief Counts the length of given string till the nullterminator is hit
 *        or any of the additional defined delimiters.
 * @param[in] s pointer to a nullterminated string whose quasi-length
 *              shall be found.
 * @param[in] deli pointer to a nullterminated string which
 *                 contains the additional delimiting characters.
 * @note If \p s is `NULL` then `strlen_deli` will segfault - this is intended.
 * @note ft_strlen() corresponds to strlen_deli() with an empty string
 *       as delimiter set.
 * @remark The number `strlen_deli(s)` can be viewed in different ways:
 *         * As *quasi-length* of the string s,
 *         * As *index of the Nullterminator* of s or of the first occurence
 *           of one of the additional defined delimiters.
 * @return The quasi-length of the string.
 */
size_t	strlen_deli(const char *s, const char *deli)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_in(s[i], deli))
		i++;
	return (i);
}

/**
 * @brief Counts the number of words in a given string
 * @param[in] s pointer to a nullterminated string.
 * @param[in] deli pointer to a nullterminated string which
 *                 contains the characters that act as delimiters
 *                 (in addition to the nullterminator).
 * @note If \p s is `NULL` then `count_words` will segfault - this is intended.
 * @return The number of counted words.
 */
size_t	count_words(const char *s, const char *deli)
{
	size_t	num_words;

	num_words = 0;
	while (*s)
	{
		while(is_in(*s, deli))
			s++;
		if (*s == '\0')
			return (num_words);
		num_words += 1;
		while (!is_in(*s, deli) && *s)
			s++;
	}
	return (num_words);
}