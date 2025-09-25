/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:49 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 12:30:42 by reciak           ###   ########.fr       */
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
 *          Workaround within libft: Use the error feedbacking
 *          atoi_proper() or atoi_strict() instead.
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
