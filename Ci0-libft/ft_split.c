/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:43:01 by reciak            #+#    #+#             */
/*   Updated: 2025/05/19 15:06:17 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @brief Stores the definition of ft_split
 */

#include "libft.h"

static void	st_free_allocs(char **strarr, size_t j_failed);

/**
 * @brief Allocates memory (using malloc(3)) and returns an
 *        array of strings obtained by splitting \p s using
 *        the character \p c as a delimiter. The array must
 *        end with a `NULL` pointer, cf. Libft Subject (Version 16.7).
 * @note 
 * @param[in] s: The string to be split.
 * @param[in] c: The delimiter character.
 * @return 
 *          * The array of new strings (terminated with a `NULL` pointer) 
 *            resulting from the split.
 *          * `NULL` on error.
 */
char	**ft_split(char const *s, char c)
{
	char separators[2];

	separators[0] = c;
	separators[1] = '\0';
	return(split_deli(s, separators));
}
/**
 * @brief An extension of ft_split():
 *        Allocates memory (using malloc(3)) and returns an
 *        array of strings obtained by splitting \p s using
 *        the characters in \p deli as delimiters. The array
 *        ends with a `NULL` pointer.
 * @param[in] s: The string to be split.
 * @param[in] deli: Contains the delimiting / word speparatorting characters.
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

	num_words = count_words(s, deli);  //<-- ft_x_strtools1.c
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
	size_t j;

	j = 0;
	while (j < j_failed)
		free (strarr[j]);
	free (strarr);
}