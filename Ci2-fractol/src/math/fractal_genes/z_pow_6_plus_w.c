/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_6_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:51:29 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 12:31:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_6_plus_w.c
 * @brief Stores the definition of z_pow_6_plus_w()
 */

#include "fractol.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^6 + w
 */
t_cmplx	z_pow_6_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx			zeta;
	const double	x = z.re;
	const double	y = z.im;
	const double	u = w.re;
	const double	v = w.im;

	zeta.re = x * x * x * x * x * x - 15 * x * x * x * x * y * y;
	zeta.re += 15 * x * x * y * y * y * y - y * y * y * y * y * y;
	zeta.re += u;
	zeta.im = 6 * x * x * x * x * x * y - 20 * x * x * x * y * y * y;
	zeta.im += 6 * x * y * y * y * y * y;
	zeta.im += v;
	return (zeta);
}
