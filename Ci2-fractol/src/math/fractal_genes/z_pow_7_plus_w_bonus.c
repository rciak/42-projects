/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_7_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:51:42 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 12:32:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_7_plus_w.c
 * @brief Stores the definition of z_pow_7_plus_w()
 */

#include "fractol_bonus.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^7 + w
 */
t_cmplx	z_pow_7_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx			zeta;
	const double	x = z.re;
	const double	y = z.im;
	const double	u = w.re;
	const double	v = w.im;

	zeta.re = x * x * x * x * x * x * x - 21 * x * x * x * x * x * y * y;
	zeta.re += 35 * x * x * x * y * y * y * y - 7 * x * y * y * y * y * y * y;
	zeta.re += u;
	zeta.im = 7 * x * x * x * x * x * x * y - 35 * x * x * x * x * y * y * y;
	zeta.im += 21 * x * x * y * y * y * y * y - y * y * y * y * y * y * y;
	zeta.im += v;
	return (zeta);
}
