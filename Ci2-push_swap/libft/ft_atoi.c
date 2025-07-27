/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:49 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 10:12:31 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief Stores the definition of ft_atoi
 */

#include "libft.h"

/**
 * @brief Convert a sequence of ASCII characters to an int, resembling
 *        the original atoi (ASCII to integer), cf.
 *        [atoi](https://man7.org/linux/man-pages/man3/atoi.3.html).
 *        See also
 *        [strtol](https://man7.org/linux/man-pages/man3/strtol.3.html).
 * @note The C locale is assumed, so that exactly the following characters
 *       are considered to be white spaces, according to
 *       [isspace](https://man7.org/linux/man-pages/man3/isspace.3p.html):
 *       * ' ' (space), '\\n' (newline), '\\t' (horizontal  tab),
 *       * '\\f' (form-feed), '\\r' (carriage return), 
 *         and '\\v' (vertical tab),
 * @warning A *return value of 0 is* ***ambigious***:
 *          It can both be caused by an error or as a regular return 
 *          value to a given string like "0" that respresents the number 0.
 * @warning The [atoi](https://man7.org/linux/man-pages/man3/atoi.3.html)
 *          man page recommends using the `strtol` or `strtoul` family of
 *          functions instead. (These functions set errno to `ERANGE`
 *          on error - in contrast to `atoi` which does not set errno.)
 * @param[in] nptr A char pointer to the input string
 * @return 
 *          * 0 on error
 *          * the converted number (potential 0 as well)
 */
int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (is_in(*nptr, " \n\t\f\r\v"))
		nptr++;
	if (!is_in(*nptr, "+-0123456789"))
		return (0);
	if (*nptr == '-')
		sign = -1;
	if (is_in(*nptr, "+-"))
		nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (0);
	while (is_in(*nptr, "0123456789"))
	{
		nbr = 10 * nbr + (*nptr - '0');
		nptr++;
	}
	return ((int)(sign * nbr));
}

/**
 * @brief Similar to ft_atoi() but with feedbacking of error to the caller.
 * @note [27.07.2025] the code is almost the same as in ft_atoi and should
 *       produce the same return value in case of regular input but not if
 *       irregular input is handed over: In contrast to ft_atoi()
 *       out of range happenings -- including overflows in the iterative
 *       built up of \p nbr -- are regarded as errors. These are indicated by
 *       E_ATOI_RANGE and 0 is returned.
 * @param[in] nptr A char pointer to the input string
 * @param[out] err_code Feedbacking to caller if error happened and what kind.
 * @return 
 *          * 0 on error
 *          * the converted number (potential 0 as well)
 * @warning **Test Status:** functionality (but not err_codes) indirectly
 *          tested by Tripouille's libftTester via the wrapper
   @code
   int	ft_atoi(const char *nptr)
   {
      t_libft_err	err_code;

      return (atoi_proper(nptr, &err_code));
   }
   @endcode
 */
int	atoi_proper(const char *nptr, t_libft_err *err_code)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (is_in(*nptr, " \n\t\f\r\v"))
		nptr++;
	if (!is_in(*nptr, "+-0123456789"))
		return (*err_code = E_ATOI_BAD_STRING, 0);
	if (*nptr == '-')
		sign = -1;
	if (is_in(*nptr, "+-"))
		nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOI_BAD_STRING, 0);
	while (is_in(*nptr, "0123456789"))
	{
		if ((10 * nbr) / 10 != nbr || 10 * nbr + (*nptr - '0') < 10 * nbr)
			return (*err_code = E_ATOI_RANGE, 0);
		nbr = 10 * nbr + (*nptr - '0');
		nptr++;
	}
	if (sign * nbr < INT_MIN || sign * nbr > INT_MAX)
		return (*err_code = E_ATOI_RANGE, 0);
	return (*err_code = E_ATOI_NOERR, (int)(sign * nbr));
}
