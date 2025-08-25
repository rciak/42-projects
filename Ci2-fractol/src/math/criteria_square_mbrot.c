/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criteria_square_mbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:10:08 by reciak            #+#    #+#             */
/*   Updated: 2025/08/25 16:10:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file criteria_square_mbrot.c
 * @brief Stores the definition of criteria_square_mbrot()
 */

#include "fractol.h"

/**
 * @brief Implements the square escape criteria |z|_\infty > 2
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
bool	criteria_square_mbrot(t_cmplx z, t_cmplx w)
{
	(void) w;
	if (z.re < -2.0 || z.re > 2.0 || z.im < -2.0 || z.im > 2.0)
		return (true);
	return (false);
}

