/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_proper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:22:02 by reciak            #+#    #+#             */
/*   Updated: 2025/09/25 12:28:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoi_proper.c
 * @brief Stores the definition of atoi_proper()
 */

#include "libft.h"

/**
 * @brief Similar to ft_atoi() but with feedbacking of error to the caller.
 * @note [27.07.2025] the code is almost the same as in ft_atoi and should
 *       produce the same return value in case of regular input but not if
 *       irregular input is handed over: In contrast to ft_atoi()
 *       out of range happenings -- including overflows in the iterative
 *       built up of \p nbr -- are regarded as errors. These are indicated by
 *       E_ATOI_RANGE and 0 is returned.
 * @note Like `atoi` it will convert weird input like "123abc" into the number
 *       `123` (so that ft_atoi() behaves the same as the original atoi).
 *       See atoi_strict() for a variant where this is regarded as
 *       an error.
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
	return (*err_code = E_ATOI_NO_ERR, (int)(sign * nbr));
}
