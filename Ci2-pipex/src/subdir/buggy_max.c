/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buggy_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:47:12 by reciak            #+#    #+#             */
/*   Updated: 2025/10/11 09:59:53 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file buggy_max.c
 * @brief Stores the definition of buggy_max()
 */

#include "pipex.h"

/**
 * @brief Just to demonstrate the  make tests  rule...  
 * @note Easily a bug like  'a <= b'  (instead of the correct 'a >= b') 
 *       can come in by a typing error...
 * @param a The first integer
 * @param b The second integer
 * @return The maximum of \p a and \p b 
 *         (if they are different this is the bigger one).
 */
int	buggy_max(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
