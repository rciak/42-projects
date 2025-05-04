/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:43:09 by reciak            #+#    #+#             */
/*   Updated: 2025/05/04 21:09:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @brief Stores the definition of isascii
 */

 #include "libft.h"
 #include <stdio.h>  // EOF

/**
 * @brief Checks if the given input is an ASCII character, cf.
 * [isascii](https://man7.org/linux/man-pages/man3/isascii.html).
 * @note Since the input is (according to that man page) expected to be either
 *       in the (ASCII) range 0...123 or equal to `EOF`
 *       one has an alternative to the straightforward check
 *       `0 <= c && c <= 127`, namely: One could also do the (faster)
 *       check `c != EOF` . This would choose of course a different way of
 *       "undefined behaviour" if c neither is in the
 *       ASCII range 0...127 nor equal to `EOF` than the straightforward check:
 *       In this case the alternative implementation of ft_isascii would
 *       return 1 (true) for almos all input values of c that violate the
 *       value assumptions if being ASCII range 0...127 and `EOF`.
 *       Though in accordance to the man page this feels weird, given the
 *       function's name `ft_isascii`.
 * @param[in] c The character to be checked; value 0-127 or `EOF` is assumed.
 * @return 
 *          * 1 if \p c is an ASCII character,
 *          * 0 otherwise.
 */
int ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}