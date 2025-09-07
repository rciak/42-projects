/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:52:30 by rene              #+#    #+#             */
/*   Updated: 2025/09/02 12:55:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_palette.c
 * @brief Stores the definition of init_palette()
 */

#include "fractol_bonus.h"

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
	palette->color[12] = 0x00E600E6;
	palette->color[13] = 0x00E60000;
	palette->color[14] = 0x00BA9DAA;
	palette->color[15] = 0x0000E600;
	palette->color[16] = 0x00E1E1E1;
	palette->color[17] = 0x00999999;
	palette->color[18] = 0x00000000;
	palette->color[19] = 0x000000E6;
	palette->color[20] = 0x00000099;
	palette->color[21] = 0x001A200F;
	palette->color[22] = 0x009AB8D7;
	palette->color[23] = 0x00BD9AA7;
	palette->color[24] = 0x00CF00CF;
	palette->color[25] = 0x00CF0000;
	palette->color[26] = 0x00A88D99;
	palette->color[27] = 0x0000CF00;
	palette->color[28] = 0x00CACACA;
	palette->color[29] = 0x008A8A8A;
	palette->color[30] = 0x00000000;
	palette->color[31] = 0x000000CF;
	palette->color[32] = 0x0000008A;
	palette->color[33] = 0x00171C0E;
	palette->color[34] = 0x008BA6C2;
	palette->color[35] = 0x00AA8B97;
}

void	set__fifth_cohort_colors(t_palette *palette)
{
	palette->color[36] = 0x00B800B8;
	palette->color[37] = 0x00B80000;
	palette->color[38] = 0x00957D88;
	palette->color[39] = 0x0000B700;
	palette->color[40] = 0x00B4B4B4;
	palette->color[41] = 0x007A7A7A;
	palette->color[42] = 0x00000000;
	palette->color[43] = 0x000000B7;
	palette->color[44] = 0x0000007A;
	palette->color[45] = 0x0015190C;
	palette->color[46] = 0x007B94AC;
	palette->color[47] = 0x00977B86;
	palette->color[48] = 0x00A800A8;
	palette->color[49] = 0x00A80000;
	palette->color[50] = 0x0089737D;
	palette->color[51] = 0x0000A700;
	palette->color[52] = 0x00A5A5A5;
	palette->color[53] = 0x00707070;
	palette->color[54] = 0x00000000;
	palette->color[55] = 0x000000A7;
	palette->color[56] = 0x00000070;
	palette->color[57] = 0x0013170B;
	palette->color[58] = 0x0071878E;
	palette->color[59] = 0x008A707A;
}
