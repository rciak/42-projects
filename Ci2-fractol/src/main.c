/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/13 15:31:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	_args_ok(int argc, char **argv, t_err *err);
static bool	_init_non_mlx_vars(t_all *all);
static bool	_provide_windows(t_all *all);

int			draw_initial_fractal(t_all *all);
int			react_on_mouse(int button, int k, int j, t_all *all);

int	main(int argc, char **argv)
{
	t_all	all;

	if (!_args_ok(argc, argv, &all.err)
		|| !_init_non_mlx_vars(&all)
		|| !_provide_windows(&all)
	)
		return (all.err.code);
	mlx_loop_hook(all.x.disp, &draw_initial_fractal, &all);
	mlx_mouse_hook(all.x.win1, &react_on_mouse, &all);
	mlx_loop(all.x.disp);
	mlx_destroy_display(all.x.disp);
	free(all.x.disp);
	return (ERR_NONE);
}

//TODO: Implement helpers beyond dummy state
static bool	_args_ok(int argc, char **argv, t_err *err)
{
	(void) argc;
	(void) argv;
	*err = error(ERR_NONE);
	return (true);
}

static bool _init_non_mlx_vars(t_all *all)
{
	all->dummy_c = "Message";
	all->dummy_i = 3;
	all->err = error(ERR_NONE);
	return (true);
}

static bool	_provide_windows(t_all *all)
{	
	char	*title;
	t_x		*x;

	title = "Fractol - Dummy title";
	x = &(all->x);
	x->disp = NULL;
	x->win1 = NULL;
	x->win2 = NULL;
	x->disp = mlx_init();
	if (x->disp == NULL)
		return (all->err = error(ERR_MLX_INIT), false);
	x->win1 = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title);
	if (x->win1 == NULL)
		return (
			all->err = error(ERR_MLX_NEW_WINDOW),
			free(x->disp),
			false
		);
	// x->win2 = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title);
	// if (x->win2 == NULL)
	// 	return (
	// 		all->err = error(ERR_MLX_NEW_WINDOW),
	// 		mlx_destroy_window(x->disp, x->win1),
	// 		free(x->disp),
	// 		false
	// 	);
	return (true);
}

int draw_initial_fractal(t_all *all)
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
	if (button == Button3 && all->x.win1 != NULL)
		mlx_destroy_window(all->x.disp, all->x.win1);
	if (button == Button3 && all->x.win2 != NULL)
		mlx_destroy_window(all->x.disp, all->x.win2);
	return (0);
}
