/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:35 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 19:29:56 by reciak           ###   ########.fr       */
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
	else if (key == XK_t)
		toggle_escape_criteria(&all->math[MBROT].will_escape);
	else
	{
		if (key == XK_P)
			;//print info                                                          ;
		return (0);
	}
	all->x.recalc[MBROT] = true;
	return (0);
}

