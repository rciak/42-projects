/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:42 by reciak            #+#    #+#             */
/*   Updated: 2025/08/26 20:47:32 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO:                                    Implement beyond these dummy versions!

int close_julia(t_all *all)
{
	all->x.close[JULIA]  = true;
	return (0);
}

int	key_julia(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		close_julia(all);
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
