/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:42 by reciak            #+#    #+#             */
/*   Updated: 2025/08/16 22:16:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Implement beyond these dummy versions!

int close_julia(t_all *all)
{
	mlx_destroy_window(all->x.disp, all->x.win[JULIA]);
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
	(void) all;
	if (k < l)
		k = l;
	if (button == Button1)
		ft_putstr_fd("\njulia: Button1! ", 1);
	if (button == Button2)
		ft_putstr_fd("\njulia: Button2! ", 1);
	return (0);
}
