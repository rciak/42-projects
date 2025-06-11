/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:40:46 by reciak            #+#    #+#             */
/*   Updated: 2025/06/11 12:54:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
   @file ft_printf.c
   @brief Stores the definition of the core function ft_printf()
 */

#include "ft_printf.h"

static int	st_write_by_specifi(const char *str, va_list *parg);

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
int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			bytes_sent;
	int			bytes_total;

	va_start (arg, str);
	bytes_total = 0;
	while (*str)
	{
		if (*str != '%')
			bytes_sent = write(STDOUT_FD, str, 1);
		else
			bytes_sent = st_write_by_specifi(str, &arg);
		if (bytes_sent < 0)
		{
			va_end(arg);
			return (bytes_sent);
		}
		bytes_total += bytes_sent;
		str++;
	}
	va_end(arg);
	return (bytes_total);
}

/**
 * @note the caller relies on st_write_by_specifi() taking care itself
 *      of the edge case of the current '%' (== *str) being followed by '\0'.
 * @note va_arg returns only "fully promoted" types, like e.g. int or double.
 *       For the case `*str == 'c'`, thus a casting from int to (unsigned char)
 *       is done iside the called static helper function;
 * @note Note here that casting to (unsigned char) is prefered over casting
 *       to (char) since this seems to be what printf is doing, cf.
 *       the man page of printf (`man 3 printf`), sect.
 *       "Conversion specifiers", c. (Although the raw byte / bit pattern
 *       resulting from either casting to (unsigned char) or (signed char)
 *       is the same, so `write` will treat them in the same way.
 * @warning The result of `va_arg` is *not an lvalue*; in contrast to
 *          lvalues which have a valid address for their life time,
 *          the result of va_arg is just a value and might have only a
 *          very limited "temporary lifetime" (as perplexity put it nicely.)
 */
static int	st_write_by_specifi(const char *s, va_list *parg)
{
	if (*s != '%')
		return (E_NOT_AT_PERCENT);
	s++;
	if (! *s)
		return (0);
	if (is_in(*s, "di"))
		return (out_nbr(va_arg(*parg, int), "0123456789"));
	else if (*s == 'u')
		return (out_unbr(va_arg(*parg, unsigned int), "0123456789"));
	else if (*s == 'x')
		return (out_unbr(va_arg(*parg, unsigned int), "0123456789abcdef"));
	else if (*s == 'X')
		return (out_unbr(va_arg(*parg, unsigned int), "0123456789ABCDEF"));
	else if (*s == 'p')
		return (out_vptr(va_arg(*parg, void *)));
	else if (*s == 's')
		return (ft_putstr(va_arg(*parg, char *)));
	else if (*s == 'c')
		return (st_out_c(va_arg(*parg, int)));
	else if (*s == '%')
		return (write(STDOUT_FD, s, 1));
	else
		return (E_BAD_ARG);
}

static int	t_out_c(va_list *parg)
{
	unsigned char	uc;

	uc = (unsigned char) va_arg(*parg, int);
	return (write(STDOUT_FD, &uc, 1));
}
