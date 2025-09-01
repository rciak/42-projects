/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_3_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:17:05 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 22:41:50 by reciak           ###   ########.fr       */
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

	zeta.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + w.re;
	zeta.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im + w.im;
	return (zeta);
}
