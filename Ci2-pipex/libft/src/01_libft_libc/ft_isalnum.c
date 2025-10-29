/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:42:46 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:17:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 * @brief Stores the definition of ft_isalnum()
 */

#include "libft.h"

/**
 * @brief Checks if a character is a letter or a digit, cf.
 * [isalnum](https://man7.org/linux/man-pages/man3/isalnum.3.html)
 * @note Cf. also ft_isalpha()
 * @param[in] c The character to be checked; value 0...127 or `EOF` is assumed.
 * @return 
 *          * 1 if \p c does represent an (ASCII) letter or a digit,
 *          * 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
