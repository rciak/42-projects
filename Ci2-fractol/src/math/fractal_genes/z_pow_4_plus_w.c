/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_4_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:37:33 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 11:43:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_4_plus_w.c
 * @brief Stores the definition of z_pow_4_plus_w()
 */

#include "fractol.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^4 + w
 */
t_cmplx	z_pow_4_plus_w(t_cmplx z, t_cmplx w)
{
	t_cmplx			zeta;
	const double	x = z.re;
	const double	y = z.im;
	const double	u = w.re;
	const double	v = w.im;

	zeta.re = x * x * x * x - 6 * x * x * y * y + y * y * y * y + u;
	zeta.im = 4 * x * x * x * y - 4 * x * y * y * y + v;
	return (zeta);
}

