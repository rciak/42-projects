/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pow_2_plus_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:28:49 by rene              #+#    #+#             */
/*   Updated: 2025/08/19 01:33:56 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file z_pow_2_plus_w.c
 * @brief Stores the definition of z_pow_2_plus_w()
 */

#include "fractol.h"

/**
 * @brief A computer version of the holomorphic function 
 *          C x C   --> C
 *          (z, w) |--> z^2 + w
 */

t_cmplx fun_m2(t_cmplx z, t_cmplx w)
{
	t_cmplx zeta;

	zeta.re = z.re * z.re - z.im * z.im + w.re;
	zeta.im = 2 * z.re * z.im + w.im;
	return (zeta);
}