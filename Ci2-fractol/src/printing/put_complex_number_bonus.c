/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_complex_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:23:23 by reciak            #+#    #+#             */
/*   Updated: 2025/09/03 16:33:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file put_complex_number.c
 * @brief Stores the definition of put_complex_number()
 */

#include "fractol_bonus.h"

/**
 * @brief Basic printing of a complex number in base 10.
 *
 * @note For a complex number z = x + iy (with doubles x and y)
 *       for simplicity  x +yi is printed.
 * @param[in] z The complex number to print
 */
void	put_complex_number(t_cmplx z)
{
	put_double(z.re);
	ft_putstr_fd(" ", STDOUT_FILENO);
	if (z.im >= 0.0)
		ft_putstr_fd("+", STDOUT_FILENO);
	put_double(z.im);
	ft_putstr_fd("i", STDOUT_FILENO);
}
