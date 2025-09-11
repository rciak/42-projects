/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:13:05 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 17:32:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 * @brief Stores the definition of ft_memchr
 */

#include "libft.h"

/**
 * @brief Given a starting point in memory and a max. number of bytes to scan,
 *        ft_memchr finds the first occurence of a character, if any, cf.
 *        [memchr](https://man7.org/linux/man-pages/man3/memchr.3.html).
 * @param[in] s A void pointer to the starting byte of the search,
 * @param[in] c The character to look for,
 * @param[in] n The number of bytes that shall be scaned at most.
 * @return 
 *          * A pointer to the matching byte, if any in the given search range,
 *          * NULL if in that range there is no such character.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s = (unsigned char *) s;
	const unsigned char	uc_c = (unsigned char) c;

	while (n > 0)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		uc_s++;
		n--;
	}
	return (NULL);
}
