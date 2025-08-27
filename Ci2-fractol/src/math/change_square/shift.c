/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:56:42 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 14:26:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file shift.c
 * @brief Stores the definition of shift()
 */

#include "fractol.h"

void	translate__square(t_square *square, double diff_re, double diff_im);

/**
 * @brief "Shifting:"
 *        Changes the description of the square (that will be rendered).
 * @note This function is realted to the mathematical "translation" function
 *         f(z) := z + a
 *       where the complex number `a` - interpreted as Vector in the real plane
 *       R^2 depends on 
 *       * the direction of the shift
 *       * and the current length of the square (inspected area of the
 *         Mandelbrot set)
 * @param[in] dir The direction in which the Mandelbrot set should move 
 * @param[in,out] square * on in: the current description of the square
 *                       * on out: the new description of the square
 */
void	shift(int dir, t_square *square)
{
	double	dist;

	dist = square->side_len * SHIFT_FACTOR;
	if (dir == LEFT_DIR)
		translate__square(square, +dist, 0.0);
	else if (dir == RIGHT_DIR)
		translate__square(square, -dist, 0.0);
	else if (dir == UP_DIR)
		translate__square(square, 0.0, +dist);
	else if (dir == DOWN_DIR)
		translate__square(square, 0.0, -dist);
}

void	translate__square(t_square *square, double diff_re, double diff_im)
{
	t_cmplx	*u;
	t_cmplx *d;
	
	u = &square->up_left;
	d = &square->down_right;
	u->re += diff_re;
	u->im += diff_im;
	d->re += diff_re;
	d->im += diff_im;
}
