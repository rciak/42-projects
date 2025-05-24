/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:43:01 by reciak            #+#    #+#             */
/*   Updated: 2025/05/24 12:42:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @brief Stores the definition of ft_split
 */

#include "libft.h"

static void		st_free_allocs(char **strarr, size_t j_failed);
static size_t	st_count_words(const char *s, char c);
static size_t	st_strlen_till(const char *s, char c);

/**
 * @brief Allocates memory (using malloc(3)) and returns an
 *        array of strings obtained by splitting \p s using
 *        the character \p c as a delimiter. The array must
 *        end with a `NULL` pointer, cf. Libft Subject (Version 16.7).
 * @note Consider the theoretical case of a string consisiting of \f$b\f$ bytes
 *       (including the nullterminator). Imaging this string should 
 *       consist of as many words a possible, e.g. looking like  
 *       `a a a a a a a a a a ... a a\0`,  
 *       `a a a a a a a a a a ... a a \0`, or  
 *       ` a a a a a a a a a a ... a a\0`. 
 *       Clearly at most
 *       \f[
 *       \tfrac{b}{2} =: w
 *       \f]
 *       words are possible. Thus the array of words (including
 *       a terminating `NULL` pointer)
 *       might need up to
 *       \f[
 *       \t w \mathtt{sizeof(char *)} = \tfrac{b}{2}\mathtt{sizeof(char *)} =: B
 *       \f]
 *       bytes.
 *       \f$B\f$ should consist of not more than \f$\mathtt{SIZE_MAX + 1}\f$
 *       bytes. Reformulating the desired \f$B \leq \mathtt{SIZE_MAX + 1}\f$
 *       leads to the following restricting demand on \f$b\f$.
 * @note **Theoretical assumption:** 
 *       The to be splitted string (including its nullterminator)
 *       shall consist of
 *       \f[
 *       b \leq \tfrac{2}{\mathtt{sizeof(char *)}} \mathtt{SIZE_MAX + 1}
 *       \f]
 *       bytes.
 * @note Provided \f$\mathtt{sizeof(char *)} \geq 2\f$ this assumption
 *       also ensures \f$b \leq \mathtt{SIZE_MAX + 1}\f$. That inequality
 *       is additionally assumed in the unlikely case of a system with
 *       additionally assumed in the unlikely case of a system with
 *       \f$\mathtt{sizeof(char *)} = 1\f$.
 * @param[in] s: The string to be split.
 * @param[in] c: The delimiter character.
 * @return 
 *          * The array of new strings (terminated with a `NULL` pointer) 
 *            resulting from the split.
 *          * `NULL` on error.
 */
char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	size_t	k;
	size_t	word_len;
	char	**word;

	num_words = st_count_words(s, c);
	word = malloc(num_words + 1);
	if (word == NULL)
		return (NULL);
	k = 0;
	while (k < num_words)
	{
		while (*s == c)
			s++;
		word_len = st_strlen_till(s, c);
		word[k] = malloc(word_len + 1);
		if (word[k] == NULL)
			return (st_free_allocs(word, k), NULL);
		ft_memcpy(word[k], s, word_len);
		word[k][word_len] = '\0';
		s += word_len;
		k++;
	}
	return (word);
}

static size_t	st_count_words(const char *s, char c)
{
	size_t	counted;

	counted = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (counted);
		counted++;
		while (*s != c && *s)
			s++;
	}
	return (counted);
}

static size_t	st_strlen_till(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != c)
		l++;
	return (l);
}


static void	st_free_allocs(char **strarr, size_t k_failed)
{
	size_t	i;

	i = 0;
	while (i < k_failed)
		free (strarr[i]);
	free (strarr);
}


// FIRST TRY: If evaluator wants to investigate: 
// Where is the cause of one tester failing it?
// --> git checkout a7c86da
//
// char	**ft_split(char const *s, char c)
// {
// 	char	separators[2];

// 	separators[0] = c;
// 	separators[1] = '\0';
// 	return (split_deli(s, separators));
// }

// /**
//  * @brief An extension of ft_split():
//  *        Allocates memory (using malloc(3)) and returns an
//  *        array of strings obtained by splitting \p s using
//  *        the characters in \p deli as delimiters. The array
//  *        ends with a `NULL` pointer.
//  * @param[in] s: The string to be split.
//  * @param[in] deli: Contains the delimiting / word speparating characters.
//  * @return 
//  *          * The array of new strings (terminated with a `NULL` pointer) 
//  *            resulting from the split.
//  *          * `NULL` on error.
//  */
// char	**split_deli(char const *s, const char *deli)
// {
// 	size_t	j;
// 	size_t	num_words;
// 	size_t	word_len;
// 	char	**strarr;

// 	num_words = count_words(s, deli);
// 	strarr = calloc_uninit(num_words + 1, sizeof(char *));
// 	if (strarr == NULL)
// 		return (NULL);
// 	j = 0;
// 	while (j < num_words)
// 	{
// 		while (is_in(*s, deli))
// 			s++;
// 		word_len = strlen_deli(s, deli);
// 		strarr[j] = calloc_uninit(word_len + 1, sizeof(char));
// 		if (strarr[j] == NULL)
// 			return (st_free_allocs(strarr, j), NULL);
// 		ft_memcpy(strarr[j], s, word_len);
// 		strarr[j][word_len] = '\0';
// 		s += word_len;
// 		j++;
// 	}
// 	strarr[num_words] = NULL;
// 	return (strarr);
// }

// static void	st_free_allocs(char **strarr, size_t j_failed)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < j_failed)
// 		free (strarr[i]);
// 	free (strarr);
// }
// /*
// #include <stdio.h>
// int main (void)
// {
// 	char	**arr;
// 	size_t	i;

// 	arr = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	if (arr == NULL)
// 		return (-1);
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("i: %zu, arr[i]: %s\n", i, arr[i]);
// 		free (arr[i]);
// 		i++;
// 	}
// 	free (arr);
// 	return (0);
// }
// */
