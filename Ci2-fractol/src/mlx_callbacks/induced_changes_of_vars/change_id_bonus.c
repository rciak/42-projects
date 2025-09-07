/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:00:55 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 18:50:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file change_id.c
 * @brief Stores the definition of change_id()
 */

#include "fractol_bonus.h"

static void	set__them(char **id, char *str,
				t_math *math, t_cmplx (*fun)(t_cmplx, t_cmplx));

/**
 * @brief Changes the current type of fractal
 * @param[in] key The pressed key
 * @param[out] id A pointer to a string literal like "m2", "m3", ...
 * @param[out] fun The address of a pointer to one of the functions 
 *                 z_pow_2_plus_w, z_pow_2_plus_w, .. used for iterating
 */
void	change_id(int key, char **id, t_math *math)
{
	if (key == XK_2)
		set__them(id, "m2", math, &z_pow_2_plus_w);
	else if (key == XK_3)
		set__them(id, "m3", math, &z_pow_3_plus_w);
	else if (key == XK_4)
		set__them(id, "m4", math, &z_pow_4_plus_w);
	else if (key == XK_5)
		set__them(id, "m5", math, &z_pow_5_plus_w);
	else if (key == XK_6)
		set__them(id, "m6", math, &z_pow_6_plus_w);
	else if (key == XK_7)
		set__them(id, "m7", math, &z_pow_7_plus_w);
	else if (key == XK_8)
		set__them(id, "m8", math, &z_pow_8_plus_w);
	else if (key == XK_9)
		set__them(id, "m9", math, &z_pow_9_plus_w);
}

static void	set__them(char **id, char *str,
				t_math *math, t_cmplx (*fun)(t_cmplx, t_cmplx))
{
	*id = str;
	math[MBROT].iter_fun = fun;
	math[JULIA].iter_fun = fun;
}
