/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:34 by reciak            #+#    #+#             */
/*   Updated: 2025/06/16 19:54:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.h
 * @brief The header file for reciak's ft_printf project of the Common Core
 */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>    // va_list, va_start, va_arg, va_end

/**
 * @note In order to have the same return value -1 that the original printf
 *       returns on error (at least on the 42 Vienna computers...)
 *       the core function ft_printf() will only return -1 on error.
 * @warning In order that ft_printf() works properly the errorcodes should all
 *          be < 0.
 */
enum e_ft_printf_errors
{
	E_VALUE_OF_ORI_PRINTF = -1,
	E_PERCENT_AT_STRING_END = -10,
	E_NOT_AT_PERCENT = -11,
	E_BAD_ARG = -12
};

int	ft_printf(const char *str, ...);

#endif