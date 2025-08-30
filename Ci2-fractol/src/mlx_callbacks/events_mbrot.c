/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:35 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 12:40:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_mbrot(t_all *all)
{
	all->x.close[MBROT] = true;
	return (0);
}

int	mouse_mbrot(int button, int k, int l, t_all *all)
{
	if (button == Button4)
		zoom(ZOOM_IN_FACTOR, k, l, &all->math[MBROT].square);
	else if (button == Button5)
		zoom(ZOOM_OUT_FACTOR, k, l, &all->math[MBROT].square);
	else if (button == Button1)
	{
		change_julia_param(k, l, &all->math[JULIA].w_0, all->math[MBROT].square);
		all->x.recalc[JULIA] = true;
		return (0);
	}
	else if (button == Button2)
	{
		all->palette.shift = (all->palette.shift + 1 + PALETTE_COLORS) % PALETTE_COLORS;
		all->x.color_shift_requires_redraw[MBROT] = true;
		return (0);
	}
	else if (button == Button3)
	{
		print_info(k, l, all->title[MBROT], &all->math[MBROT]);
		return (0);
	}
	else
		return (0);
	all->x.recalc[MBROT] = true;
	return (0);
}

int	key_mbrot(int key, t_all *all)
{
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		shift(key, &all->math[MBROT].square);
	else if (key == XK_Escape)
		close_mbrot(all);
	else if (key == XK_2 || key == XK_3)
	{
		change_id(key, &all->id, all->math);
		all->x.recalc[JULIA] = true;
	}
	else if (key == XK_t)
		toggle_escape_criteria(&all->math[MBROT].will_escape);
	else if (key == XK_h || key == XK_l || key == XK_j || key == XK_k
		|| key == XK_a || key == XK_d || key == XK_s || key == XK_w)
		change_max_iter(key, &all->math[MBROT].max_iter);
	else
	{
		if (key == XK_space)
		{
			all->palette.shift = (all->palette.shift - 1 + PALETTE_COLORS) % PALETTE_COLORS;
			all->x.color_shift_requires_redraw[MBROT] = true;
		}
		return (0);
	}
	all->x.recalc[MBROT] = true;
	return (0);
}

