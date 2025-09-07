/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:56:42 by reciak            #+#    #+#             */
/*   Updated: 2025/09/06 21:01:16 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file shift.c
 * @brief Stores the definition of shift()
 */

#include "fractol_bonus.h"

static void	translate__square(t_square *square, double diff_re, double diff_im);
static void	info___limits(void);

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
 * @param[in] key The direction in which the Mandelbrot set should move 
 *                (encoded by a keysym)
 * @param[in,out] square * on in: the current description of the square
 *                       * on out: the new description of the square
 */
void	shift(int key, t_square *square)
{
	double	dist;

	dist = square->side_len * SHIFT_FACTOR;
	if (key == XK_Left)
		translate__square(square, +dist, 0.0);
	else if (key == XK_Right)
		translate__square(square, -dist, 0.0);
	else if (key == XK_Up)
		translate__square(square, 0.0, +dist);
	else if (key == XK_Down)
		translate__square(square, 0.0, -dist);
}

static void	translate__square(t_square *square, double diff_re, double diff_im)
{
	t_cmplx	*u;
	t_cmplx	*d;

	u = &square->up_left;
	d = &square->down_right;
	u->re = u->re + diff_re;
	u->im = u->im + diff_im;
	d->re = u->re + square->side_len;
	d->im = u->im + square->side_len;
	if (square_in_allowed_region(square) == false)
	{
		info___limits();
		reset_square(square);
	}
}

static void	info___limits(void)
{
	ft_putstr_fd("\nInfo: Approaching a translation limit.", STDOUT_FILENO);
	ft_putstr_fd("\n  UP_LEFT_LIMIT_RE:     ", STDOUT_FILENO);
	put_double(UP_LEFT_LIMIT_RE);
	ft_putstr_fd("\n  UP_LEFT_LIMIT_IM:     ", STDOUT_FILENO);
	put_double(UP_LEFT_LIMIT_IM);
	ft_putstr_fd("\n  DOWN_RIGHT_LIMIT_RE:  ", STDOUT_FILENO);
	put_double(DOWN_RIGHT_LIMIT_RE);
	ft_putstr_fd("\n  DOWN_RIGHT_LIMIT_IM:  ", STDOUT_FILENO);
	put_double(DOWN_RIGHT_LIMIT_IM);
	ft_putstr_fd("\n--> Resetting view", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
