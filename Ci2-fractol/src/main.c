/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/12 18:47:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

static bool	args__ok(int argc, char **argv, t_err *err);
static bool	init__non_mlx_vars(t_all *all);
static bool	provide__windows(t_all *all);
static bool setup__hooks(t_all *all);

int			waiting_for_godot(t_all *all);
int			react_on_mouse(int button, int k, int j, t_all *all);

int	main(int argc, char **argv)
{
	t_all	all;

	if (!args__ok(argc, argv, &all.err)
		|| !init__non_mlx_vars(&all)
		|| !provide__windows(&all)
		|| !setup__hooks(&all)
	)
		return (all.err.code);	
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

static bool	provide__windows(t_all *all)
{	
	char	*title[2];
	t_x		*x;

	title[0] = "Fractol - Connectedness locus";
	title[1] = "Fractol - Filled Julia set";
	x = &(all->x);

	x->win[MBROT] = NULL;
	x->win[JULIA] = NULL;
	x->disp = mlx_init();
	if (x->disp == NULL)
		return (all->err = error(ERR_MLX_INIT), false);
	x->win[MBROT] = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title[0]);
	if (x->win[MBROT] == NULL)
		return (all->err = error(ERR_MLX_NEW_WINDOW), free(x->disp), false);
	x->win[JULIA] = mlx_new_window(x->disp, WIN_WIDTH, WIN_HEIGHT, title[1]);
	if (x->win[JULIA] == NULL)
		return (
			all->err = error(ERR_MLX_NEW_WINDOW),
			mlx_destroy_window(x->disp, x->win[MBROT]),
			free(x->disp),
			false
		);
	return (true);
}
static bool	setup__hooks(t_all *all)
{
	mlx_loop_hook(all->x.disp, &waiting_for_godot, all);
	mlx_key_hook(all->x.win[MBROT], &key_mbrot, all);
	mlx_key_hook(all->x.win[JULIA], &key_julia, all);
	mlx_mouse_hook(all->x.win[MBROT], &mouse_mbrot, all);
	mlx_mouse_hook(all->x.win[JULIA], &mouse_julia, all);
	return (true);
}

//TODO: Replace  dummy content - maybe by essentiall nothing?
int waiting_for_godot(t_all *all)
{
	if (all->dummy_i == 3)
	{
		ft_putstr_fd("Set i to 0\n", 1);
		all->dummy_i = 0;
	}
	return (MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL);
}
