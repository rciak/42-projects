/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:55:03 by reciak            #+#    #+#             */
/*   Updated: 2025/07/02 15:27:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_utils.c
 * @brief Stores the definition of utilities for get_next_line
 */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t  i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;
	char	*writer;

	len = ft_strlen(s);
	ptr = malloc (len + 1);
	if (ptr == NULL)
		return (NULL);
	writer = ptr;
	while (*s)
	{
		*writer = *s;
		writer++;
		s++;
	}
	*writer = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*catenated;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 + len2 < len1 || len1 + len2 + 1 < 1)
		return (NULL);
	catenated = malloc (len1 + len2 + 1);
	if (catenated == NULL)
		return (NULL);
	ft_memcpy(catenated, s1, len1);
	ft_memcpy(catenated + len1, s2, len2);
	catenated[len1 + len2] = '\0';
	return (catenated);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char           *uc_dest;
	const unsigned char     *uc_src = (unsigned char *) src;

	uc_dest = (unsigned char *) dest;
	while (n > 0)
	{
	    *uc_dest = *uc_src;
	    uc_dest++;
	    uc_src++;
	    n--;
	}
	return (dest);
}