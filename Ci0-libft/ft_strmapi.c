/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:44:52 by reciak            #+#    #+#             */
/*   Updated: 2025/05/19 15:03:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 * @brief Stores the definition of ft_strmapi
 */

#include "libft.h"

/**
 * @brief Applies the function f to each character of the string s,
 * passing its index as the first argument and the character itself 
 * as the second. A new string is created (using malloc(3)) to store the results
 * from the successive applications of f, cf. Libft Subject (Version 16.7).
 * @note Similar to ft_substr() the question arises why unsigned int is used 
 *       instead of size_t ...
 * @warning Since `f` expects an unsigned int (and not an size_t) parameter
 *          theoretical problems arise if both UINT_MAX < SIZE_MAX and 
 *          the string s (including its nullterminator) consits of more than
 *          UINT_MAX bytes. In this case the function f will be applied
 *          only to the first UINT_MAX - 1 bytes. 
 * @param[in] s: The string to iterate over.
 * @param[in] f: The function to apply to each character.
 * @return 
 *          * The string created from the successive applications of ’f’.
 *          * `NULL` if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*p;
	unsigned int	i;

	len = ft_strlen(s);
	if (si_is_overflow(len, '+', 1))
		return (NULL);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < UINT_MAX - 1)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
