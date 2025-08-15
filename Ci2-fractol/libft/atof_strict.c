/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:33:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/15 17:57:59 by reciak           ###   ########.fr       */
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
 *        but a float of **double** precision.
 * @note Note in particular that "123abc" would be regarded as invalid input.
 * @note It is unsure if this straight forward approach loses more
 *       more precision than neccessary.
 * @param[in] nptr A char pointer to the input string
 * @param[out] err_code Feedbacking to caller if error happened and what kind.
 * @return
 *          * The converted number or
 *          * 0.0 on error
 */
double	atof_strict(const char *nptr, t_libft_err *err_code)
{
	size_t	num_parts;
	double	number;
	
	num_parts = count_words(nptr, ".");
	if (num_parts == 0 || num_parts > 2)
		return (*err_code = E_ATOF_BAD_STRING, 0.0);
	else if (num_parts == 1)
	{
		number = (double) atoll_strict(nptr, err_code);
		*err_code = atoll__err_to_atof_err(*err_code);
	}
	else
		number = atof__strict_normal_case(nptr, err_code);
	if (*err_code != E_ATOF_NO_ERR)
		return (0.0);
	return (number);
}

t_libft_err	atoll__err_to_atof_err(t_libft_err err_code)
{
	return(err_code + (E_ATOF_NO_ERR - E_ATOLL_NO_ERR));
}

double	atof__strict_normal_case(const char *nptr, t_libft_err *err_code)
{
	char		**part;
	double		sign;
	double		nbr;
	double		fract_part;
	t_libft_err	atoll_err[2];
	
	part = ft_split(nptr, '.');
	if (part == NULL)
		return (*err_code = E_ATOF_MALLOC, 0.0);
	nbr = (double) atoll_strict(part[0], &atoll_err[0]);
	fract_part = get___fract_part(part[1], &atoll_err[1]);
	if 
	sign = 1;
	if (nbr < 0)
		sign = -1;
	
	
	
	free_array(part); 
	return (*err_code = E_ATOF_NO_ERR, nbr + (sign) * fract_part);
}
