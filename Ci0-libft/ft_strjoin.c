/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:59:54 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 18:24:20 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @brief Stores the definition of ft_strjoin
 */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
 *        new string, which is the result of concatenating
 *        ’s1’ and ’s2’, cf. Libft Subject (Version 16.7).
 * @note 
 * @param[in] s1: The prefix string.
 * @param[in] s2: The suffix string.
 * @return 
 *          * NULL on error,
 *          * the new string else.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*catenated;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (is_overflow(len1, '+', len2) || is_overflow(len1 + len2, '+', 1))
		return (NULL);
	catenated = malloc (len1 + len2 + 1);
	if (catenated == NULL)
		return (NULL);
	ft_memcpy(catenated, s1, len1);
	ft_memcpy(catenated + len1, s2, len2);
	catenated[len1 + len2] = '\0';
	return (catenated);
}
