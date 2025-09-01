/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_iter_to_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:22:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 22:57:37 by reciak           ###   ########.fr       */
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
 * @param[in] max The maximum number of iterations
 * @param[in] pal Contains the colors and an index offset for color cycling.
 */
void	img_iter_to_color(t_image iter, t_image draw, int max, t_palette pal)
{
	int	k;
	int	l;
	int	num_iter;
	int	*dest;

	l = 0;
	while (l < HEIGHT)
	{
		k = 0;
		while (k < WIDTH)
		{
			num_iter = *(int *)(iter.buf
					+ l * iter.size_line + k * iter.bytes_per_pixel);
			dest = (int *)(draw.buf
					+ l * draw.size_line + k * draw.bytes_per_pixel);
			*dest = pal.color[(num_iter + pal.shift) % PALETTE_COLORS];
			if (num_iter == max)
				*dest = pal.not_escaped_color;
			k++;
		}
		l++;
	}
}
