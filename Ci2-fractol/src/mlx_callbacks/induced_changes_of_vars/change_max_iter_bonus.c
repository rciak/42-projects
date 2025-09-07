/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_max_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:10:30 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 20:02:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file change_max_iter.c
 * @brief Stores the definition of toggle_escape_criteria()
 */

#include "fractol_bonus.h"

/**
 * @brief Changes max_iter (within the defined limits in fractol_bonus.h)
 * @param[in] key The pressed key
 * @param[in,out] the number of iterations used for the calculations
 */
void	change_max_iter(int key, int *max_iter)
{
	if (key == XK_h || key == XK_a)
		*max_iter -= SMALL_STEP;
	else if (key == XK_l || key == XK_d)
		*max_iter += SMALL_STEP;
	else if (key == XK_j || key == XK_s)
		*max_iter -= BIG_STEP;
	else if (key == XK_k || key == XK_w)
		*max_iter += BIG_STEP;
	if (*max_iter < 0)
		*max_iter = 0;
	if (*max_iter > LIMIT_MAX_ITER)
		*max_iter = LIMIT_MAX_ITER;
}
