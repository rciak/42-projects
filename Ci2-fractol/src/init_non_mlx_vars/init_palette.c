/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:52:30 by rene              #+#    #+#             */
/*   Updated: 2025/09/02 12:30:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_palette.c
 * @brief Stores the definition of init_palette()
 */

#include "fractol.h"

void	set__second_cohort_colors(t_palette *palette);
void	set__fifth_cohort_colors(t_palette *palette);

/**
 * @brief This is a helper for init_non_mlx_vars()
 *        which takes care of initalising the color palette
 *        setting also the inital color shift to 0.
 */
void	init_palette(t_palette *palette)
{
	palette->shift = 0;
	palette->not_escaped_color = 0x00faded1;
	palette->color[0] = 0x00FF00FF;
	palette->color[1] = 0x00FF0000;
	palette->color[2] = 0x00CFAEBD;
	palette->color[3] = 0x0000FF00;
	palette->color[4] = 0x00FAFAFA;
	palette->color[5] = 0x00AAAAAA;
	palette->color[6] = 0x00000000;
	palette->color[7] = 0x000000FF;
	palette->color[8] = 0x000000AA;
	palette->color[9] = 0x001D2311;
	palette->color[10] = 0x00abcdef;
	palette->color[11] = 0xdad2abba;
	set__second_cohort_colors(palette);
	set__fifth_cohort_colors(palette);
}

void	set__second_cohort_colors(t_palette *palette)
{
	palette->color[12] = 0x00FF00FF * 9 / 10;
	palette->color[13] = 0x00FF0000 * 9 / 10;
	palette->color[14] = 0x00CFAEBD * 9 / 10;
	palette->color[15] = 0x0000FF00 * 9 / 10;
	palette->color[16] = 0x00FAFAFA * 9 / 10;
	palette->color[17] = 0x00AAAAAA * 9 / 10;
	palette->color[18] = 0x00000000 * 9 / 10;
	palette->color[19] = 0x000000FF * 9 / 10;
	palette->color[20] = 0x000000AA * 9 / 10;
	palette->color[21] = 0x001D2311 * 9 / 10;
	palette->color[22] = 0x00abcdef * 9 / 10;
	palette->color[23] = 0xdad2abba * 9 / 10;
	palette->color[24] = 0x00FF00FF * 81 / 100;
	palette->color[25] = 0x00FF0000 * 81 / 100;
	palette->color[26] = 0x00CFAEBD * 81 / 100;
	palette->color[27] = 0x0000FF00 * 81 / 100;
	palette->color[28] = 0x00FAFAFA * 81 / 100;
	palette->color[29] = 0x00AAAAAA * 81 / 100;
	palette->color[30] = 0x00000000 * 81 / 100;
	palette->color[31] = 0x000000FF * 81 / 100;
	palette->color[32] = 0x000000AA * 81 / 100;
	palette->color[33] = 0x001D2311 * 81 / 100;
	palette->color[34] = 0x00abcdef * 81 / 100;
	palette->color[35] = 0xdad2abba * 81 / 100;
}

void	set__fifth_cohort_colors(t_palette *palette)
{
	palette->color[36] = 0x00FF00FF * 72 / 100;
	palette->color[37] = 0x00FF0000 * 72 / 100;
	palette->color[38] = 0x00CFAEBD * 72 / 100;
	palette->color[39] = 0x0000FF00 * 719 / 1000;
	palette->color[40] = 0x00FAFAFA * 72 / 100;
	palette->color[41] = 0x00AAAAAA * 72 / 100;
	palette->color[42] = 0x00000000 * 719 / 1000;
	palette->color[43] = 0x000000FF * 719 / 1000;
	palette->color[44] = 0x000000AA * 719 / 1000;
	palette->color[45] = 0x001D2311 * 719 / 1000;
	palette->color[46] = 0x00abcdef * 72 / 100;
	palette->color[47] = 0xdad2abba * 719 / 1000;
	palette->color[48] = 0x00FF00FF * 66 / 100;
	palette->color[49] = 0x00FF0000 * 66 / 100;
	palette->color[50] = 0x00CFAEBD * 66 / 100;
	palette->color[51] = 0x0000FF00 * 6561 / 10000;
	palette->color[52] = 0x00FAFAFA * 66 / 100;
	palette->color[53] = 0x00AAAAAA * 66 / 100;
	palette->color[54] = 0x00000000 * 6561 / 10000;
	palette->color[55] = 0x000000FF * 6561 / 10000;
	palette->color[56] = 0x000000AA * 6561 / 10000;
	palette->color[57] = 0x001D2311 * 66 / 100;
	palette->color[58] = 0x00abcdef * 66 / 100;
	palette->color[59] = 0xdad2abba * 6561 / 10000;
}
