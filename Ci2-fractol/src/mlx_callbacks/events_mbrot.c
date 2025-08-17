/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:32:35 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 13:07:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

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
	(void) all;
	(void) k; (void) l;
	if (button == Button1)
		ft_putstr_fd("\nmbrot: Button1! ", 1);
	if (button == Button2)
		ft_putstr_fd("\nmbrot: Button2! ", 1);
	return (0);
}
