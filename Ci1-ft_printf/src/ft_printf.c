/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:40:46 by reciak            #+#    #+#             */
/*   Updated: 2025/06/09 13:52:32 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
   @file ft_printf.c
   @brief Stores the definition of the core function ft_printf()
 */

#include "ft_printf.h"

/**
 * @brief Mimicks the orignal ft_printf, but only for the following converstion
 *        specifiers that should follow a `%`  
 *        `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%` (e.g. `%c`, `%%`).
 * @note On github there should be a version containing a `makefile` extending
 *       `Makefile` by useful rules like `unit-tests` to be called like e.g.
 *     * `make unit-tests`
 *     * `make DEV=1 unit-tests`
 *     * `make DEV=1 unit-tests > /dev/null`
 */
int	ft_printf(const char *str, ...)
{
	

	while (*str)
	{

		str++;
	}

}
