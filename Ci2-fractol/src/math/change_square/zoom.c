/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:56 by reciak            #+#    #+#             */
/*   Updated: 2025/08/26 17:57:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file zoom.c
 * @brief Stores the definition of zoom()
 */

#include "fractol.h"

/**
 * @brief "Zooming:"
 *        Changes the description of the square (that will be rendered).
 *
 * @note This function is related to the mathematical "zoom" function
 *         f(z) := c + factor * (z - c)
 *       where
 *       * c is the fix point / center of zoom (--> f(c) = c)
 *       * and factor is the zoom factor
 * @param[in] factor The zoom factor
 * @param[in] k The horizontal pixel coordinate
 * @param[in] l The vertical pixel coordinate
 * @param[in,out] square * on in: the current description of the square
 *                       * on out: the new description of the square
 */
void	zoom(double factor, int k, int l, t_square *square)
{
	t_cmplx	c;
	t_cmplx	*u;
	double	*s;
	t_cmplx *d;
	
	c = coord_transf(k, l, *square);
	u = &square->up_left;
	s = &square->side_len;
	d = &square->down_right;
	u->re = c.re + factor * (u->re - c.re);
	u->im = c.im + factor * (u->im - c.im);
	*s = *s * factor;
	d->re = u->re + *s;
	d->im = u->im + *s;
}
