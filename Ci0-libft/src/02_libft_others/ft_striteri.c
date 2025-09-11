/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:48:46 by reciak            #+#    #+#             */
/*   Updated: 2025/05/19 19:12:56 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @brief Stores the definition of ft_striteri
 */

#include "libft.h"

/**
 * @brief Applies the function \p f to each character of the
 *        string passed as argument, passing its index as the first argument.
 *         Each character is passed by address to ’f’ so it can be
 *         modified if necessary., cf. Libft Subject (Version 16.7).
 * @note Similar to ft_substr() the question arises why unsigned int is used 
 *       instead of size_t ...
 * @warning Since `f` expects an unsigned int (and not an size_t) parameter
 *          theoretical problems arise if both UINT_MAX < SIZE_MAX and 
 *          the string s (including its nullterminator) consits of more than
 *          UINT_MAX bytes. In this case the function f will be applied
 *          only to the first UINT_MAX - 1 bytes.
 * @param[in, out] s: The string to iterate over.
 * @param[in] f: The function to apply to each character.
  */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] && i < UINT_MAX - 1)
	{
		f(i, s + i);
		i++;
	}
}
