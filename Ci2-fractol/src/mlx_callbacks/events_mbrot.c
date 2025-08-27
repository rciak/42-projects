/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:35 by reciak            #+#    #+#             */
/*   Updated: 2025/08/26 20:47:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_mbrot(t_all *all)
{
	all->x.close[MBROT] = true;
	return (0);
}

int	key_mbrot(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		close_mbrot(all);
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

