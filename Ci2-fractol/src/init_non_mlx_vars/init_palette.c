/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:52:30 by rene              #+#    #+#             */
/*   Updated: 2025/08/19 02:03:19 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_palette.c
 * @brief Stores the definition of init_palette()
 */

#include "fractol.h"

/**
 * @brief This is a helper for init_non_mlx_vars()
 *        which takes care of initalising the color palette
 *        setting also the inital color shift to 0.
 */
void	init_palette(t_palette *palette)
{
	palette->shift = 0;
	palette->color[0] = 0x00FF0000;
	palette->color[1] = 0x0000FF00;
	palette->color[2] = 0x000000FF;
	palette->color[3] = 0xdad2abba;
}