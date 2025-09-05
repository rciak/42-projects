/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_8_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:51:53 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 12:32:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_8_plus_w.c
 * @brief Stores the definition of z_pow_8_plus_w()
 */

#include "fractol.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^8 + w
 */
t_cmplx	z_pow_8_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx			zeta;
	const double	x = z.re;
	const double	y = z.im;
	const double	u = w.re;
	const double	v = w.im;

	zeta.re = x * x * x * x * x * x * x * x;
	zeta.re += -28 * x * x * x * x * x * x * y * y;
	zeta.re += 70 * x * x * x * x * y * y * y * y;
	zeta.re += -28 * x * x * y * y * y * y * y * y;
	zeta.re += y * y * y * y * y * y * y * y;
	zeta.re += u;
	zeta.im = 8 * x * x * x * x * x * x * x * y;
	zeta.im += -56 * x * x * x * x * x * y * y * y;
	zeta.im += 56 * x * x * x * y * y * y * y * y;
	zeta.im += -8 * x * y * y * y * y * y * y * y;
	zeta.im += v;
	return (zeta);
}
