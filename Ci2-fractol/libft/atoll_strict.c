/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll_strict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:52:28 by reciak            #+#    #+#             */
/*   Updated: 2025/08/15 13:18:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoll_strict.c
 * @brief Stores the definition of atoll_strict()
 */

#include "libft.h"

static bool	only__whitespace(const char *nptr, t_libft_err *err_code);

/**
 * @brief Similar to atoi_strict() except that the return is not int 
 *        but long long.
 * @note Note in particular that "123abc" would be regarded as invalid input.
 * @note The logic ft_atoi(), ft_atoi_proper() and ft_atoi_strict()
 *       relies on doing the operations on a bigger datatype.
 *       For atooll_strict() the logic was thus slightly modified
 *       so that operating within long long should work.
 * @param[in] nptr A char pointer to the input string
 * @param[out] err_code Feedbacking to caller if error happened and what kind.
 * @return 
 *          * 
 *          * 
 */
long long	atoll_strict(const char *nptr, t_libft_err *err_code)
{
	long long	sign;
	long long	n;

	sign = 1;
	n = 0;
	skip((char **) &nptr, " \n\t\f\r\v");
	if (!is_in(*nptr, "+-0123456789"))
		return (*err_code = E_ATOLL_BAD_STRING, 0);
	if (*nptr == '-')
		sign = -1;
	if (is_in(*nptr, "+-"))
		nptr++;
	if (!is_in(*nptr, "0123456789"))
		return (*err_code = E_ATOLL_BAD_STRING, 0);
	while (is_in(*nptr, "0123456789"))
	{
		if ((10 * n) / 10 != n || (10 * n) > LLONG_MAX - (*nptr - '0')
			|| (10 * n) < LLONG_MIN + (*nptr - '0'))
			return (*err_code = E_ATOLL_RANGE, 0);
		n = 10 * n + (sign) * (*nptr - '0');
		nptr++;
	}
	if (!only__whitespace(nptr, err_code))
		return (0);
	return (*err_code = E_ATOLL_NO_ERR, n);
}

static bool	only__whitespace(const char *nptr, t_libft_err *err_code)
{
	while (is_in(*nptr, " \n\t\f\r\v"))
		nptr++;
	if (*nptr != '\0')
	{
		*err_code = E_ATOLL_BAD_STRING;
		return (false);
	}
	return (true);
}

/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	t_libft_err err;
	long long res;

	res = atoll_strict("-9223372036854775808", &err);
	printf("\n");
	printf("LLONG_MIN:    %lld\n", LLONG_MIN);
	printf("atoll_strict: %lld\n", res);
	printf("err_code:%d\n", err);

	printf("\n");
	res = atoll_strict("9223372036854775807", &err);
	printf("LLONG_MAX:    %lld\n", LLONG_MAX);
	printf("atoll_strict: %lld\n", res);
	printf("err_code:%d\n", err);

	//1 above LLONG_MAX
	printf("\n");
	res = atoll_strict("9223372036854775808", &err);
	printf("Input:        9223372036854775808\n");
	printf("atoll_strict: %lld\n", res);
	printf("err_code:%d\n", err);

	//1 below LLONG_MIN
	printf("\n");
	res = atoll_strict("-9223372036854775809", &err);
	printf("Input:        -9223372036854775809\n");
	printf("atoll_strict: %lld\n", res);
	printf("err_code:%d\n", err);
	
	//Bad format
	printf("\n");
	res = atoll_strict("9223372036854775807a", &err);
	printf("Input:        9223372036854775807a\n");
	printf("atoll_strict: %lld\n", res);
	printf("err_code:%d\n", err);
	return (0);
}
*/
