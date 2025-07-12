/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/12 21:22:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_all
{
	void	*x_serv;
	void	*win;
	char	*dummy_c;
	int		dummy_i;
} t_all;

int draw_fractal(t_all all);
int react_on_mouse(int button, int k, int j, t_all *all);


int main (void)
{
	t_all all;

	all.dummy_c = "Message";
	all.dummy_i = 3;

	all.x_serv = mlx_init();
	//TODO NULL CHECK
	all.win = mlx_new_window(all.x_serv, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	//TODO NULL CHECK

	mlx_loop_hook(all.x_serv, &draw_fractal, &all);
	mlx_mouse_hook(all.win, &react_on_mouse, &all);
	mlx_loop(all.x_serv);

	mlx_destroy_display(all.x_serv);
	free(all.x_serv);
	
	return (0);
}

int draw_fractal(t_all all)
{
	if (all.dummy_i == 3)
	{
		ft_putstr_fd("Set i to 0\n", 1);
		all.dummy_i = 0;
	}
	return (MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL);
}

int react_on_mouse(int button, int k, int l, t_all *all)
{
	if (k < l)
		k = l;
	if (button == Button1)
	{
		ft_putstr_fd("\nButton1! ", 1);
		ft_putstr_fd(all->dummy_c, 1);
		all->dummy_i++;
	}
	if (button == Button2)
	{
		ft_putstr_fd("\nButton2! ", 1);
	}
	if (button == Button3)
		mlx_destroy_window(all->x_serv, all->win);
	return (0);
}