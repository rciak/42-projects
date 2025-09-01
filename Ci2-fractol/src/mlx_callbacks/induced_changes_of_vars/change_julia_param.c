/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_julia_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:49:52 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 22:52:59 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file change_julia_param.c
 * @brief Stores the definition of change_julia_param()
 */

#include "fractol.h"

/**
 * @brief Changes the Julia parameter according to complex number corresponding
 *        to the clicked pixel in the mandelbrot window.
 * @param[in] k The horizontal pixel coordinate
 * @param[in] l The vertical pixel coordinate
 * @param[out] w_0 The complex number used as Julia parameter
 */

void	change_julia_param(int k, int l, t_cmplx *w_0, t_square square)
{
	*w_0 = coord_transf(k, l, square);
}
