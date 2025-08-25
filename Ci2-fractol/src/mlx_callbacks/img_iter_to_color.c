/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_iter_to_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:22:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/25 18:56:49 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file iter_to_color.c
 * @brief Stores the definition of iter_to_color()
 */

#include "fractol.h"

/**
 * @brief Calculates the color image from the iterations "image"
 * @param[in] iter The "image" of iterations (calculated in each pixel)
 * @param[out] draw The image of colors
 * @param[in] palette Contains the colors and an index offset for color cycling.
 */
// TODO:                                                                 IMPLEMENT!
void img_iter_to_color(t_image iter, t_image draw, t_palette palette)
{
	int	k;
	int	l;
	int it;
	int *dest;

	l = 0;
	while (l < HEIGHT)
	{
		k = 0;
		while (k < WIDTH)
		{
			it = *(int*)(iter.buf + l * iter.size_line + k * iter.bytes_per_pixel);
			dest = (int *)(draw.buf + l * draw.size_line + k * draw.bytes_per_pixel);
			*dest = palette.color[(it + palette.shift) % PALETTE_COLORS];
			k++;
		}
		l++;
	}
}
