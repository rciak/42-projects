/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:56 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 14:35:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file zoom.c
 * @brief Stores the definition of zoom()
 */

#include "fractol.h"

static void	info__limits(void);

/**
 * @brief "Zooming:"
 *        Changes the description of the square (that will be rendered).
 * @note This function is related to the mathematical "zoom" function
 *         f(z) := c + factor * (z - c)
 *       where
 *       * c is the fix point / center of zoom (--> f(c) = c)
 *       * and factor is the zoom factor
 * @note Due to (rounding) errors with doubles the mathematical LIMIT checks
 *       are a bit modified, e.g. instead
 *         @code *s * factor < ZOOM_OUT_LIMIT @endcode
 *       the check 
 *         @code *s * factor < 1.125 * ZOOM_OUT_LIMIT @endcode
 *       is done. Since zooming is based on multiplication with 2 and 0.5, 
 *       respectively, this seem fine within the fractol project.
 * @note It has no deeper meaning that the factors differ both by the same
 *       absolute value 125 from 1.
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
	if (*s * factor < 1.125 * ZOOM_OUT_LIMIT 
		&& *s * factor > 0.875 * ZOOM_IN_LIMIT)
	{
		u->re = c.re + factor * (u->re - c.re);
		u->im = c.im + factor * (u->im - c.im);
		*s = *s * factor;
		d->re = u->re + *s;
		d->im = u->im + *s;
	}
	else
		info__limits();
}

static void	info__limits(void)
{
	ft_putstr_fd("\nInfo: Approaching a zoomlimit.", STDOUT_FILENO);
	ft_putstr_fd("\n  ZOOM_OUT_LIMIT: ", STDOUT_FILENO);
	put_double(ZOOM_OUT_LIMIT);
	ft_putstr_fd("\n  ZOOM_IN_LIMIT:  ", STDOUT_FILENO);
	put_double(ZOOM_IN_LIMIT);
	ft_putstr_fd("\n", STDOUT_FILENO);
}