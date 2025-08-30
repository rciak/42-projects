/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:48:52 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 13:54:32 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file put_double.c
 * @brief Stores the definition of put_double()
 */

#include "fractol.h"

/**
 * @brief Basic printing of a double in base 10.
 *
 * @note There are always printed 17 fractional digits.	
 * @note This is a rather ad hoc implemention not thoroughly thought through
 *       but for the purpose of fractol it should be sufficient.
 * @param[in] d The double to print
 */

void	put_double(double d)
{
	long long	integer_part;
	int			fractional_digits;

	integer_part = (long long) d;
	// if (d < 0)
	// 	ft_putstr_fd("-", STDOUT_FILENO);
	ft_putllnbr_fd(integer_part, STDOUT_FILENO);
	ft_putstr_fd(".", STDOUT_FILENO);
	d = d - (double) integer_part;
	if (d < 0)
		d *= -1;
	fractional_digits = 17;
	while (fractional_digits > 0)
	{
		d = d * 10;
		integer_part = (long long) d;
		d = d - (double) integer_part;
		ft_putllnbr_fd(integer_part, STDOUT_FILENO);
		fractional_digits--;
	}
}

