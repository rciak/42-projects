/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:26:58 by reciak            #+#    #+#             */
/*   Updated: 2025/05/15 10:06:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 * @brief Stores the definition of ft_strtrim
 */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
          copy of ’s1’ with characters from ’set’ removed
          from the beginning and the end, cf. Libft Subject (Version 16.7).
 * @param[in] s1: The string to be trimmed.
 * @param[in] set: The string containing the set of characters to be removed.
 * @return 
 *          * `NULL` on error,
 *          * A pointer to the trimmed string
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (is_in(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (is_in(s1[end], set))
		end--;
	return (si_substr(s1, start, end + 1 - start));
}
