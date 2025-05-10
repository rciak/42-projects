/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:07:06 by reciak            #+#    #+#             */
/*   Updated: 2025/05/10 22:11:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Stores the definition of ft_tolower
 */

#include "libft.h"

/**
 * @brief Converts uppercase letters to lowercase, cf.
 *        [tolower](https://man7.org/linux/man-pages/man3/tolower.3.html).
 * @note Cf. also ft_isalpha()
 * @param[in] c The character to be converted;
 *              value 0...127 or `EOF` is assumed.
 * @param[out]
 * @param[in,out]
 * @return 
 *          * the corresponding lowercase letter,
 *            if \p c is an uppercase letter,
 *          * \p c if it is not an uppercase letter.
 */
 int	ft_tolower(int c)
 {
	 if ('A' <= c && c <= 'Z')
		 return (c - 'A' + 'a');
	 return (c);
 }