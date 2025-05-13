/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:50:18 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 16:19:10 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @brief Stores the definition of ft_strdup
 */

#include "libft.h"

/**
 * @brief Duplicates a given string, cf.
 *        [strdup](https://man7.org/linux/man-pages/man3/strdup.3.html).
 * @note `errno` is at least not directly set by ft_strdup in case of an error,
 *       maybe though by the used `malloc`.
 * @param[in] s the string to be duplicated.
 * @return 
 *          * `NULL` on error,
 *          * a pointer to the duplicated string else.
 */
char *ft_strdup(const char *s)
{
	size_t len;
	char	*ptr;

	len = ft_strlen(s);
	if (is_overflow(len, '+', 1))
		return (NULL);
	ptr = malloc (len + 1);
	return (ptr);
}