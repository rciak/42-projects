/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:31:35 by reciak            #+#    #+#             */
/*   Updated: 2025/05/05 12:04:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @brief Stores the definition of ft_isprint
 */

#include "libft.h"

/**
 * @brief Checks if a character is a printable asci character, cf.
 * [isprint](https://man7.org/linux/man-pages/man3/isprint.html)
 * @note Cf. also ft_isalpha()
 * @param[in] c The character to be checked; value 0...127 or `EOF` is assumed.
 * @return 
 *          * 1 if \p c does represent a printable ASCII letter
 *          * 0 otherwise.
 */
int ft_isprint(int c)
{
	return(' ' <= c && c <= '~');
}