/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_9_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:52:05 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 12:32:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_9_plus_w.c
 * @brief Stores the definition of z_pow_9_plus_w()
 */

#include "fractol_bonus.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^9 + w
 */
t_cmplx	z_pow_9_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx			zeta;
	const double	x = z.re;
	const double	y = z.im;
	const double	u = w.re;
	const double	v = w.im;

	zeta.re = x * x * x * x * x * x * x * x * x;
	zeta.re += -36 * x * x * x * x * x * x * x * y * y;
	zeta.re += 126 * x * x * x * x * x * y * y * y * y;
	zeta.re += -84 * x * x * x * y * y * y * y * y * y;
	zeta.re += 9 * x * y * y * y * y * y * y * y * y;
	zeta.re += u;
	zeta.im = 9 * x * x * x * x * x * x * x * x * y;
	zeta.im += -84 * x * x * x * x * x * x * y * y * y;
	zeta.im += 126 * x * x * x * x * y * y * y * y * y;
	zeta.im += -36 * x * x * y * y * y * y * y * y * y;
	zeta.im += y * y * y * y * y * y * y * y * y;
	zeta.im += v;
	return (zeta);
}
