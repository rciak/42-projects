/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_3_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:17:05 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 11:29:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_3_plus_w.c
 * @brief Stores the definition of z_pow_3_plus_w()
 */

#include "fractol.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^3 + w
 */
t_cmplx	z_pow_3_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx	zeta;
	double	x;
	double	y;
	double	u;
	double	v;

	x = z.re;
	y = z.im;
	u = w.re;
	v = w.im;
	zeta.re = x * x * x - 3 * x * y * y + u;
	zeta.im = 3 * x * x * y - y * y * y + v;
	return (zeta);
}
