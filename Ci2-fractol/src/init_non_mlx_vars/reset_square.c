/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:42:03 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 22:00:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file reset_square.c
 * @brief Stores the definition of reset_square()
 */

#include "fractol.h"

/**
 * @brief Resets (or inits) a square to the default values
 *
 * @param[out] square Will receive the default values..
 */
void reset_square(t_square *square)
{
	square->up_left.re = -2.0;
	square->up_left.im = -2.0;
	square->side_len = 4.0;
	square->down_right.re = 2.0;
	square->down_right.im = 2.0;
}
