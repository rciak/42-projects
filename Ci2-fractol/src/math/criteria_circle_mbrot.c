/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criteria_circle_mbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:51:28 by reciak            #+#    #+#             */
/*   Updated: 2025/08/25 16:17:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file criteria_circle_mbrot.c
 * @brief Stores the definition of criteria_circle_mbrot()
 */

#include "fractol.h"

/**
 * @brief Implements the circular escape criteria |z| > 2
 *        (or rather the mathematical equivalent |z|^2 > 4)
 *        for the Mandelbrot / Multibrot sets.
 * @note For the mbrot criteria the complex number `w` is not needed,
 *       but since the criteria are used as a kind of plugin in,
 *       cf. fractol.h, where the function pointer refers to a function
 *       of both `z` and `w`.
 * @param[in] \p z, \p w The pair of complex numbers to be checked.
 * @return
 *          * true, if the escape criteria is meet
 *          * false, else
 */
bool	criteria_circle_mbrot(t_cmplx z, t_cmplx w)
{
	(void) w;
	if (z.re * z.re + z.im * z.im > 4.0)
		return (true);
	return (false);
}
