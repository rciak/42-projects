/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:42 by reciak            #+#    #+#             */
/*   Updated: 2025/09/06 21:50:04 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check__keys_that_trigger_no_recalculation(int key, t_all *all);

int	close_julia(t_all *all)
{
	all->x.close[JULIA] = true;
	return (0);
}

int	mouse_julia(int button, int k, int l, t_all *all)
{
	if (button == Button2)
	{
		all->x.color_shift_requires_redraw[JULIA] = true;
		all->palette.shift
			= (all->palette.shift + 1 + PALETTE_COLORS) % PALETTE_COLORS;
		return (0);
	}
	else if (button == Button3)
		print_info(k, l, all->title[JULIA], &all->math[JULIA]);
	else if (button == Button4)
		zoom(ZOOM_IN_FACTOR, k, l, &all->math[JULIA].square);
	else if (button == Button5)
		zoom(ZOOM_OUT_FACTOR, k, l, &all->math[JULIA].square);
	if (button == Button4 || button == Button5)
		all->x.recalc[JULIA] = true;
	return (0);
}

int	key_julia(int key, t_all *all)
{
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		shift(key, &all->math[JULIA].square);
	else if (key == XK_Escape)
		close_julia(all);
	else if (key == XK_2 || key == XK_3 || key == XK_4 || key == XK_5
		|| key == XK_6 || key == XK_7 || key == XK_8 || key == XK_9)
	{
		change_id(key, &all->id, all->math);
		all->x.recalc[MBROT] = true;
	}
	else if (key == XK_t)
		toggle_escape_criteria(&all->math[JULIA].will_escape);
	else if (key == XK_h || key == XK_l || key == XK_j || key == XK_k
		|| key == XK_a || key == XK_d || key == XK_s || key == XK_w)
		change_max_iter(key, &all->math[JULIA].max_iter);
	else if (key == XK_BackSpace)
		reset_square(&all->math[JULIA].square);
	else
	{
		check__keys_that_trigger_no_recalculation(key, all);
		return (0);
	}
	all->x.recalc[JULIA] = true;
	return (0);
}

static void	check__keys_that_trigger_no_recalculation(int key, t_all *all)
{
	if (key == XK_space)
	{
		all->palette.shift
			= (all->palette.shift - 1 + PALETTE_COLORS) % PALETTE_COLORS;
		all->x.color_shift_requires_redraw[JULIA] = true;
	}
	if (key == XK_b)
	{
		all->palette.shift
			= (all->palette.shift + 1 + PALETTE_COLORS) % PALETTE_COLORS;
		all->x.color_shift_requires_redraw[JULIA] = true;
	}
}
