/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:00:55 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 12:41:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file change_id.c
 * @brief Stores the definition of change_id()
 */

#include "fractol.h"

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
	{
		*id = "m2";
		math[MBROT].iter_fun = &z_pow_2_plus_w;
		math[JULIA].iter_fun = &z_pow_2_plus_w;
	}
	else if (key == XK_3)
	{
		*id = "m3";
		math[MBROT].iter_fun = &z_pow_3_plus_w;
		math[JULIA].iter_fun = &z_pow_3_plus_w;
	}
}
