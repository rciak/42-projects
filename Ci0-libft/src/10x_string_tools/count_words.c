/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:23:31 by reciak            #+#    #+#             */
/*   Updated: 2025/09/27 21:26:49 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file count_words.c
 * @brief Stores the definition of count_words()
 */

#include "libft.h"

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
