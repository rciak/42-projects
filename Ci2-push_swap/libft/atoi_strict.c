/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:29:50 by reciak            #+#    #+#             */
/*   Updated: 2025/08/09 12:24:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoi_strict.c
 * @brief Stores the definition of atoi_strict()
 */

#include "libft.h"

static bool	only__whitespace(const char *nptr, t_libft_err *err_code);
static bool	out__of_range(int sign, long long nbr, t_libft_err *err_code);

/**
 * @brief Similar to atoi_proper() but in what is regarded  valid input
 *        it is more strict than atoi_proper(), resp. ft_atoi(), resp. the
 *        orignal atoi (at least in its implementation on 42 machines)
 * @note In contrast to atoi_proper() (and hence ft_atoi()) weird input like
 *       "123abc" will not be converted into the number `123`, but atoi_strict()
 *       will return "0" instead and set \p error_code to `E_ATOI_BAD_STRING`,
 *       seeing more inputs as invalid strings than atoi_strict() does.
 *       Additional white space after the digits part is though considered ok.
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
int	atoi_strict(const char *nptr, t_libft_err *err_code)
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
	if (!only__whitespace(nptr, err_code) || out__of_range(sign, nbr, err_code))
		return (0);
	return (*err_code = E_ATOI_NOERR, (int)(sign * nbr));
}

static bool	only__whitespace(const char *nptr, t_libft_err *err_code)
{
	while (is_in(*nptr, " \n\t\f\r\v"))
		nptr++;
	if (*nptr != '\0')
	{
		*err_code = E_ATOI_BAD_STRING;
		return (false);
	}
	return (true);
}

static bool	out__of_range(int sign, long long nbr, t_libft_err *err_code)
{
	if (sign * nbr < INT_MIN || sign * nbr > INT_MAX)
	{
		*err_code = E_ATOI_RANGE;
		return (true);
	}
	return (false);
}