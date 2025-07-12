/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/12 16:43:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int main (void)
{
	void	*x_serv;
	void	*win;

	x_serv = mlx_init();
	//TODO NULL CHECK
	win = mlx_new_window(x_serv, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx_destroy_window(x_serv, win);
	//free (win);
	mlx_destroy_display(x_serv);
	free(x_serv);


	ft_putstr_fd("Hello World!", 1);
}

