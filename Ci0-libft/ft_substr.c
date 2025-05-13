/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:51:17 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 22:20:27 by reciak           ###   ########.fr       */
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
 *          * `NULL`, if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	si_start;
	char	*substr;
	char	*walker;

	si_start = (size_t) start;
	if (si_is_overflow(len, '+', 1))
		return (NULL);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	walker = substr;
	while (*s && len > 0)
	{
		*walker = *s;
		walker++;
		s++;
		len--;
	}
	*walker = '\0';
	return (substr);
}
