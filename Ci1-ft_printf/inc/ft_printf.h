/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:34 by reciak            #+#    #+#             */
/*   Updated: 2025/06/13 19:06:25 by reciak           ###   ########.fr       */
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

enum e_ft_printf_errors
{
	E_NOT_AT_PERCENT = -11,
	E_BAD_ARG = -12
};

int	ft_printf(const char *str, ...);

#endif