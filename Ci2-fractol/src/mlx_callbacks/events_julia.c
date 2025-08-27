/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:42 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 15:07:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO:                                    Implement beyond these dummy versions!

int close_julia(t_all *all)
{
	all->x.close[JULIA]  = true;
	return (0);
}

int	key_julia(int key, t_all *all)
{
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		shift(key, &all->math[JULIA].square);
	else if (key == XK_Escape)
		close_julia(all);
	else
	{
		if (key == XK_P)
			;//print info                                                          ;
		return (0);
	}
	all->x.recalc[JULIA] = true;
	return (0);
}

int	mouse_julia(int button, int k, int l, t_all *all)
{
	if (button == Button4)
		zoom(ZOOM_IN_FACTOR, k, l, &all->math[JULIA].square);
	else if (button == Button5)
		zoom(ZOOM_OUT_FACTOR, k, l, &all->math[JULIA].square);
	else
		return (0);
	all->x.recalc[JULIA] = true;
	return (0);
}
