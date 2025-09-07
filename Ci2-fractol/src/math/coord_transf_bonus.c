/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_transf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:46:17 by reciak            #+#    #+#             */
/*   Updated: 2025/08/26 11:34:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file coord_transf.c
 * @brief Stores the definition of coord_transf()
 */

#include "fractol_bonus.h"

/**
 * @brief Transforms pixel coordinate (k, l) to the corresponding complex number
 *
 * @note Interpretating complex numbers as points in the real plane RxR
 *       this is just a linear coordinate transform determind by the images of
 *       the coordinates (0,0) of the top most and leftmost pixel, and 
 *       the coordinates (WIDTH, HEIGHT) of the bottom most and rightmost pixel,
 *       respectively:
 *       (0,0)           |--> square.up_left,
 *       (WIDTH, HEIGHT) |--> square.down_right
 * @note For convenience we chose the real axix and the imaginary axis to point
 *       in the same directions as the horizontal and vertical pixel axes.
 *       For e.g. the initial values this means
 *       (0,0)           |--> (-2.0, -2.0),
 *       (WIDTH, HEIGHT) |--> ( 2.0,  2.0)
 * @param[in] 
 * @return The complex number corresponding to the pixel coordinates
 */
t_cmplx	coord_transf(int k, int l, t_square range)
{
	t_cmplx	transformed;

	transformed.re = range.up_left.re + k * range.side_len / (WIDTH - 1);
	transformed.im = range.up_left.im + l * range.side_len / (HEIGHT - 1);
	return (transformed);
}
