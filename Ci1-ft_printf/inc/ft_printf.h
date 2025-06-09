/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:34 by reciak            #+#    #+#             */
/*   Updated: 2025/06/09 20:38:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.h
 * @brief The header file for reciak's ft_printf project of the Common Core
 */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

enum e_ft_printf_errors
{
	E_WRITE = -10,
	E_NOT_AT_PERCENT = -11,
	E_BAD_ARG = -12
};

int	ft_printf(const char *str, ...);

#endif