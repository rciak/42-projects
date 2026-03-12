/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:05:35 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:09:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 * @brief Stores the definition of ft_bzero()
 */

#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s 
 *        with zeros, cf.
 *        [bzero](https://man7.org/linux/man-pages/man3/bzero.3.html)
 * @note 
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
