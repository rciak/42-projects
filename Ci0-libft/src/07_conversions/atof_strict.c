/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:33:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/16 20:02:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atof_strict.c
 * @brief Stores the definition of atof_strict()
 */

#include "libft.h"

static double	get__integer_part(const char **nptr, t_libft_err *err_code);
static double	get__fract_part(const char **p_nptr, t_libft_err *err_code);

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

	skip((char **) &nptr, " \n\t\f\r\v");
	if (!is_in(*nptr, "+-0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (is_in(*nptr, "+-"))
		nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	n = sign * get__integer_part(&nptr, err_code);
	if (*nptr == '\0')
		return (*err_code = E_ATOF_NO_ERR, n);
	if (*nptr != '.')
		return (*err_code = E_ATOF_BAD_STRING, 0);
	nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOF_BAD_STRING, 0);
	n = n + sign * get__fract_part(&nptr, err_code);
	if (*err_code != E_ATOF_NO_ERR)
		return (0);
	return (*err_code = E_ATOF_NO_ERR, n);
}

static double	get__fract_part(const char **p_nptr, t_libft_err *err_code)
{
	double		magnitude;
	long long	l_fract;

	magnitude = 1;
	while (is_in(**p_nptr, "0"))
	{
		if (magnitude > DBL_MAX / 100)
			return (*err_code = E_ATOF_RANGE_PANIC, 0);
		magnitude *= 10;
		(*p_nptr)++;
	}
	if (**p_nptr == '\0')
		return (*err_code = E_ATOF_NO_ERR, 0);
	l_fract = atoll_strict(*p_nptr, err_code);
	if (*err_code != E_ATOLL_NO_ERR)
		return (*err_code += (E_ATOF_NO_ERR - E_ATOLL_NO_ERR), 0);
	while (is_in(**p_nptr, "0123456789"))
	{
		if (magnitude > DBL_MAX / 100)
			return (*err_code = E_ATOF_RANGE_PANIC, 0);
		magnitude *= 10;
		(*p_nptr)++;
	}
	return (*err_code = E_ATOF_NO_ERR, l_fract / magnitude);
}

static double	get__integer_part(const char **p_nptr, t_libft_err *err_code)
{
	double	n;

	n = 0;
	while (is_in(**p_nptr, "0123456789"))
	{
		if (n > DBL_MAX / 100)
			return (*err_code = E_ATOF_RANGE_PANIC, 0);
		n = 10 * n + (**p_nptr - '0');
		(*p_nptr)++;
	}
	return (n);
}

/*
// After compiling with
//    make DEBUG_VALGRIND=1 re; echo "2"; cc -g3 atof_strict.c libft.a
// the following are some possible tests:
// ./a.out +0.1123;
// ./a.out -0.1123;
// ./a.out -654.000011230000000;
// ./a.out -654.0a00;
// ./a.out -654c.000;
// ./a.out -654.00000001234567890123456789;
// ./a.out -654.000000012345678901234567890
// [Test for very big numbers is inconvenient to put here, but it seems
//  to work till being close to DBL_MAX ]
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_libft_err	err_code;
	double		result;

	if (argc != 1 +1)
		return (-1);
	printf("\n");
	printf("argv[1]:   %s\n", argv[1]);
	result = atof_strict(argv[1], &err_code);
	printf("result:    %.20f\n", result);
	printf("result:    %.20g\n", result);
	printf("err_code:%d\n", err_code);
	return (0);
}
*/
