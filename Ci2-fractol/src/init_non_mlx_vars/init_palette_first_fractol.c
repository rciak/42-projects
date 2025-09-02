/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_palette_first_fractol.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:52:30 by rene              #+#    #+#             */
/*   Updated: 2025/09/02 16:51:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_palette.c
 * @brief Stores the definition of init_palette()
 */

#include "fractol.h"

void	set__first_cohort_colors(t_palette *palette);
void	set__second_cohort_colors(t_palette *palette);
void	set__third_cohort_colors(t_palette *palette);

/**
 * @brief This is a helper for init_non_mlx_vars()
 *        which takes care of initalising the color palette
 *        setting also the inital color shift to 0.
 */
void	init_palette(t_palette *palette)
{
	palette->shift = 0;
	palette->not_escaped_color = 0xFFFFA500;
	set__first_cohort_colors(palette);
	set__second_cohort_colors(palette);
	set__third_cohort_colors(palette);
}

void	set__first_cohort_colors(t_palette *palette)
{
	palette->color[0] = 0xFF0D47A1;
	palette->color[1] = 0xFF1565C0;
	palette->color[2] = 0xFF1976D2;
	palette->color[3] = 0xFF1E88E5;
	palette->color[4] = 0xFF2196F3;
	palette->color[5] = 0xFF42A5F5;
	palette->color[6] = 0xFF64B5F6;
	palette->color[7] = 0xFF90CAF9;
	palette->color[8] = 0xFFBBDEFB;
	palette->color[9] = 0xFFE3F2FD;
	palette->color[10] = 0xFFF8F9FA;
	palette->color[11] = 0xFFE9ECEF;
	palette->color[12] = 0xFFDEE2E6;
	palette->color[13] = 0xFFCED4DA;
	palette->color[14] = 0xFFADB5BD;
	palette->color[15] = 0xFF6C757D;
	palette->color[16] = 0xFF495057;
	palette->color[17] = 0xFF343A40;
	palette->color[18] = 0xFF212529;
	palette->color[19] = 0xFF172531;
}

void	set__second_cohort_colors(t_palette *palette)
{
	palette->color[20] = 0xFF081C15;
	palette->color[21] = 0xFF1B4332;
	palette->color[22] = 0xFF2D6A4F;
	palette->color[23] = 0xFF40916C;
	palette->color[24] = 0xFF52B788;
	palette->color[25] = 0xFF74C69D;
	palette->color[26] = 0xFF95D5B2;
	palette->color[27] = 0xFFB7E4C7;
	palette->color[28] = 0xFFD8F3DC;
	palette->color[29] = 0xFFEAFFE0;
	palette->color[30] = 0xFFF8F9FA;
	palette->color[31] = 0xFFE9ECEF;
	palette->color[32] = 0xFFDEE2E6;
	palette->color[33] = 0xFFCED4DA;
	palette->color[34] = 0xFFADB5BD;
	palette->color[35] = 0xFF6C757D;
	palette->color[36] = 0xFF495057;
	palette->color[37] = 0xFF343A40;
	palette->color[38] = 0xFF212529;
	palette->color[39] = 0xFF172531;
}

void	set__third_cohort_colors(t_palette *palette)
{
	palette->color[40] = 0xFF590D22;
	palette->color[41] = 0xFF800F2F;
	palette->color[42] = 0xFFA4133C;
	palette->color[43] = 0xFFC9184A;
	palette->color[44] = 0xFFFF4D6D;
	palette->color[45] = 0xFFFF758F;
	palette->color[46] = 0xFFFF8FA3;
	palette->color[47] = 0xFFFFB3C1;
	palette->color[48] = 0xFFFFCCD5;
	palette->color[49] = 0xFFFFF0F3;
	palette->color[50] = 0xFFF8F9FA;
	palette->color[51] = 0xFFE9ECEF;
	palette->color[52] = 0xFFDEE2E6;
	palette->color[53] = 0xFFCED4DA;
	palette->color[54] = 0xFFADB5BD;
	palette->color[55] = 0xFF6C757D;
	palette->color[56] = 0xFF495057;
	palette->color[57] = 0xFF343A40;
	palette->color[58] = 0xFF212529;
	palette->color[59] = 0xFF172531;
}
