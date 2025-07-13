/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/13 22:44:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	args__ok(int argc, char **argv, t_err *err);
static bool	init__non_mlx_vars(t_all *all);
static bool	provide__windows(t_all *all);

int			waiting_for_godot(t_all *all);
int			react_on_mouse(int button, int k, int j, t_all *all);

int	main(int argc, char **argv)
{
	t_all	all;

	if (!args__ok(argc, argv, &all.err)
		|| !init__non_mlx_vars(&all)
		|| !provide__windows(&all)
	)
		return (all.err.code);
	mlx_loop_hook(all.x.disp, &draw_initial_fractal, &all);
	mlx_mouse_hook(all.x.win0, &react_on_mouse, &all);
	mlx_loop(all.x.disp);
	mlx_destroy_display(all.x.disp);
	free(all.x.disp);
	return (ERR_NONE);
}

//TODO: Implement helper beyond dummy state
static bool	args__ok(int argc, char **argv, t_err *err)
{
	(void) argc;
	(void) argv;
	*err = error(ERR_NONE);
	return (true);
}

//TODO: Implement helper beyond dummy state
static bool init__non_mlx_vars(t_all *all)
{
	all->dummy_c = "Message";
	all->dummy_i = 3;
	all->err = error(ERR_NONE);
	return (true);
}

//TODO: Implement helper beyond this half dummy state
static bool	provide__windows(t_all *all)
{	
	char	*title[2];
	t_x		*x;

	title[0] = "Fractol - Connectedness locus";
	title[1] = "Fractol - Filled Julia set";
	x = &(all->x);

	x->win0 = NULL;
	x->win1 = NULL;
	x->disp = mlx_init();
	if (x->disp == NULL)
		return (all->err = error(ERR_MLX_INIT), false);
	x->win0 = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title[0]);
	if (x->win0 == NULL)
		return (all->err = error(ERR_MLX_NEW_WINDOW), free(x->disp), false);
	x->win1 = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title[1]);
	if (x->win1 == NULL)
		return (
			all->err = error(ERR_MLX_NEW_WINDOW),
			mlx_destroy_window(x->disp, x->win0),
			free(x->disp),
			false
		);
	return (true);
}

int waiting_for_godot(t_all *all)
{
	if (all->dummy_i == 3)
	{
		ft_putstr_fd("Set i to 0\n", 1);
		all->dummy_i = 0;
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
	if (button == Button3 && all->x.win0 != NULL)
		mlx_destroy_window(all->x.disp, all->x.win0);
	if (button == Button3 && all->x.win1 != NULL)
		mlx_destroy_window(all->x.disp, all->x.win1);
	return (0);
}
