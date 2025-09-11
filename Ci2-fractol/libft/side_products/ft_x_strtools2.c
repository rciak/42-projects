/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_strtools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:34:37 by reciak            #+#    #+#             */
/*   Updated: 2025/05/24 18:01:10 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_strtools2.c
 * @brief Stores the definitions of some useful functions in the string context.
 * @warning All functions in this files should be thoughly tested before using
 *          them.
 */

#include "libft.h"

static void	st_free_allocs(char **strarr, size_t j_failed);

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
		while (is_in(*s, deli))
			s++;
		if (*s == '\0')
			return (num_words);
		num_words += 1;
		while (!is_in(*s, deli) && *s)
			s++;
	}
	return (num_words);
}

/**
 * @brief An extension of ft_split():
 *        Allocates memory (using malloc(3)) and returns an
 *        array of strings obtained by splitting \p s using
 *        the characters in \p deli as delimiters. The array
 *        ends with a `NULL` pointer.
 * @note Given  split_deli()  the following should be a way to implement
 *       the function  ft_split().
 * @code
	char	**ft_split(char const *s, char c)
	{
		char	separators[2];

		separators[0] = c;
		separators[1] = '\0';
		return (split_deli(s, separators));
	}
   @endcode
 * @param[in] s: The string to be split.
 * @param[in] deli: Contains the delimiting / word speparating characters.
 * @return 
 *          * The array of new strings (terminated with a `NULL` pointer) 
 *            resulting from the split.
 *          * `NULL` on error.
 */
char	**split_deli(char const *s, const char *deli)
{
	size_t	j;
	size_t	num_words;
	size_t	word_len;
	char	**strarr;

	num_words = count_words(s, deli);
	strarr = calloc_uninit(num_words + 1, sizeof(char *));
	if (strarr == NULL)
		return (NULL);
	j = 0;
	while (j < num_words)
	{
		while (is_in(*s, deli))
			s++;
		word_len = strlen_deli(s, deli);
		strarr[j] = calloc_uninit(word_len + 1, sizeof(char));
		if (strarr[j] == NULL)
			return (st_free_allocs(strarr, j), NULL);
		ft_memcpy(strarr[j], s, word_len);
		strarr[j][word_len] = '\0';
		s += word_len;
		j++;
	}
	strarr[num_words] = NULL;
	return (strarr);
}

static void	st_free_allocs(char **strarr, size_t j_failed)
{
	size_t	i;

	i = 0;
	while (i < j_failed)
	{
		free (strarr[i]);
		i++;
	}
	free (strarr);
}
