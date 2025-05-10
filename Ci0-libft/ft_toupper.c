/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:05:02 by reciak            #+#    #+#             */
/*   Updated: 2025/05/10 22:05:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @brief Stores the definition of ft_toupper
 */

#include "libft.h"

/**
 * @brief Converts lowercase letters to uppercase, cf.
 *        [toupper](https://man7.org/linux/man-pages/man3/toupper.3.html).
 * @note Cf. also ft_isalpha()
 * @param[in] c The character to be converted;
 *              value 0...127 or `EOF` is assumed.
 * @return
 *          * the corresponding uppercase letter,
 *            if it the input is a lowercase letter,
 *          * the unchanged input if it is not a lowercase letter.
 */
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}