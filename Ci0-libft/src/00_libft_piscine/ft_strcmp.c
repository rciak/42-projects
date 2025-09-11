/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:40:17 by reciak            #+#    #+#             */
/*   Updated: 2025/08/14 16:24:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcmp.c
 * @brief Stores the definition of ft_strcmp, implemented during Piscine
 *        and copied here and slightly adopted an commented on 14.08.2025.
 */

#include "libft.h"

/**
 * @brief Comparison of two strings, cf.
 *        [strcmp](https://man7.org/linux/man-pages/man3/strcmp.3.html).
 * @note Cf. also strncmp()
 * @param[in] s1 The first string
 * @param[in] s2 The second string
 * @return 
 *          * 0 if the strings are equal
 *          * s1[k] - s2[k] (interpreted as unsigned chars) else.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}
