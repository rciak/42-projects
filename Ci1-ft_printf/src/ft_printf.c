/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:40:46 by reciak            #+#    #+#             */
/*   Updated: 2025/06/09 20:40:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
   @file ft_printf.c
   @brief Stores the definition of the core function ft_printf()
 */

#include "ft_printf.h"

static int	st_write_by_spec(const char *str);

/**
 * @brief Mimicks the orignal ft_printf, but only for the following conversion
 *        specifiers (that should follow a `%` character)  
 *        `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%` (e.g. `%c`, `%%`).
 * @note On github there should be a version containing a `makefile` extending
 *       `Makefile` by useful rules like `unit-tests` to be called like e.g.
 *     * `make unit-tests`
 *     * `make DEV=1 unit-tests`
 *     * `make DEV=1 unit-tests > /dev/null`
 * @param [in] str Format string
 * @param [in] ... Arguments according to the conversion specifiers in the
 *             format string.
 * @return
 *     * The number of bytes written in total, if no (write) error happened,
 *     * E_WRITE (== -10, cf. inc/ft_printf.h), on (write) error.
 * @warning ft_printf() expects a valid combination of a format string and
 *          a conversion specifiers; otherwise undefined behaviour is lurking,
 *          cf. also the C Standart in the draft version
 *          WG14/N1256 Septermber 7, 2007 (for ISO/IEC 9899:TC3),
 *          *Section 7.19.6.1 The fprintf function*, item 2 and 9:
 * @verbatim If there are insufficient arguments for the format,
   the behavior is undefined. If the format is exhausted
   while arguments remain, the excess arguments are
   evaluated (as always) but are otherwise ignored.
   @endverbatim
   @verbatim If a conversion specification is invalid,
   the behavior is undefined. If any argument is not the correct type
   for the corresponding conversion specification, the behavior is
   undefined.
   @endverbatim
 */

//TODO: INCORPORATE va_ stuff...
int	ft_printf(const char *str, ...)
{
	const char	*specifiers = "cspdiuxX%";
	int			bytes_sent;
	int			bytes_total;

	bytes_sent = 0;
	bytes_total = 0;
	while (*str)
	{
		if (*str != '%')
			bytes_sent = write(STDOUT_FD, str, 1);
		else
			bytes_sent = st_write_by_spec(str, );
		if (bytes_sent < 0)
			return (bytes_sent);
		bytes_total += bytes_sent;
		str++;
	}
	return (bytes_total);
}

/**
   @note the caller relies on st_write_by_spec() taking care itself 
        of the edge case of the current '%' (== *str) being followed by '\0'.
 */
static int	st_write_by_spec(const char *str)
{
	if (!(*str == '%'))
		return (E_NOT_AT_PERCENT);
	str++;
	if (! *str)
		return (0);
	if (*str == 'c')
		return (put_c(str));
	else if (*str == 's')
		return (put_s(str));
	else if (*str == 'p')
		return (put_p(str));
	else if (*str == 'd' && *str == 'i')
		return (put_d(str));
	else if (*str == 'u')
		return (put_u(str));
	else if (*str == 'x')
		return (put_x(str));
	else if (*str == 'X')
		return (put_captial_x(str));
	else if (*str == '%')
		return (write(STDOUT_FD, str, 1));
	else
		return (E_BAD_ARG);
}
