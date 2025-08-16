/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:33:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/16 18:04:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atof_strict.c
 * @brief Stores the definition of atof_strict()
 */

#include "libft.h"

t_libft_err	atoll__err_to_atof_err(t_libft_err err_code);
double		atof__strict_normal_case(const char *nptr, t_libft_err *err_code);

/**
 * @brief Similar to atoi_strict() except that the return is not int 
 *        but a float of **double** precision, though with less range covering
 *        than theoretical possible.
 * @note A double (on a 64 bit system) usually uses 1 bit to represent the sign,
 *       52 bits to represent the mantisaa and 11 bits to represent the
 *       exponent.
 * @warning It is neither intended to deal with things like +infinity, -infinity
 *          or NaN.
 * @note The implementation of atof_strict()
 *       does not push things to the boundary of what is theoretically possible.
 *       E.g. "range panic" starts in this implementation not
 *       when operations would cross DBL_MAX,
 *       but already when they would cross DBL_MAX / 10.
 * @warning Nonsense input like writting 0 as 0.000000[..]0000.....00000
 *          with too many digits will exhaust the posibilites of atof_strict()
 *          and cause the error `E_ATOL_RANGE_PANIC` in the called
 *          atoll_strict() function.
 * @param[in]  nptr A char pointer to the input string
 * @param[out] err_code Feedbacking to caller if error happened and what kind.
 * @return
 *          * The converted number or
 *          * 0.0 on error
 */
double	atof_strict(const char *nptr, t_libft_err *err_code)
{
	double	sign;
	double	n;

	sign = 1;
	n = 0;
	skip((char **) &nptr, " \n\t\f\r\v");
	if (!is_in(*nptr, "+-0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	if (*nptr == '-')
		sign = -1;
	if (is_in(*nptr, "+-"))
		nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	while (is_in(*nptr, "0123456789"))
	{
		if (sign * n > DBL_MAX / 100)
			return (*err_code = E_ATOF_RANGE_PANIC, 0);
		n = 10 * n + sign * (*nptr - '0');
		nptr++;
	}
	if (*nptr == '\0')
		return (*err_code = E_ATOF_NO_ERR, n);
	if (*nptr != '.')
		return (*err_code = E_ATOF_BAD_STRING, 0);
	nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);

	double	magnitude;
	long long l_fract;
	double	fract;
	fract = 0;
	magnitude = 1;
	while (is_in(*nptr, "0"))
	{
		if (magnitude > DBL_MAX / 100)
			return (*err_code = E_ATOF_RANGE_PANIC, 0);
		magnitude *= 10;
		nptr++;
	}
	if (*nptr == '0')
		fract = 0;
	else if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	else
	{
		l_fract = atoll_strict(nptr, err_code);
		while (is_in(*nptr, "0123456789"))
		{
			if (magnitude > DBL_MAX / 100)
				return (*err_code = E_ATOF_RANGE_PANIC, 0);
			magnitude *= 10;
			nptr++;
		}
		fract = l_fract / magnitude;
		if (*err_code != E_ATOLL_NO_ERR)
			return (*err_code += (E_ATOF_NO_ERR - E_ATOLL_NO_ERR), 0);
	}
	return (*err_code = E_ATOF_NO_ERR, n + sign * fract);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_libft_err	err_code;
	double		result;

	if (argc != 1 +1)
		return (-1);
	printf("argv[1]:   %s\n", argv[1]);
	result = atof_strict(argv[1], &err_code);
	printf("result:    %.20f\n", result);
	printf("result:    %.20g\n", result);
	printf("err_code:%d\n", err_code);
	return (0);
}