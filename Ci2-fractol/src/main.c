/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/16 22:14:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

static void welcome__traveler(void);
static bool	provide__windows(t_all *all);
static bool	provide__buffers(t_all *all);
static void	setup__hooks(t_all *all);

int			waiting_for_godot(t_all *all);

int	main(int argc, char **argv)
{
	t_all	all;

	welcome__traveler();
	if (!init_non_mlx_vars(argc, argv, &all))
		return (print_error(all.err), all.err.code);
	all.x.disp = mlx_init();
	if (all.x.disp == NULL)
		return (ERR_MLX_INIT);
	if (!provide__windows(&all) || !provide__buffers(&all))
		return (all.err.code);
	setup__hooks(&all);
	mlx_loop(all.x.disp);
	mlx_destroy_display(all.x.disp);
	free(all.x.disp);
	return (ERR_NONE);
}
// TODO: Improve current (dummy like) greeting by adding Use instructions and call examples
static void welcome__traveler(void)
{
	ft_putstr_fd("\nWelcome to fractol!", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static bool	provide__windows(t_all *all)
{	
	t_x		*x;

	x = &(all->x);
	x->win[MBROT] = mlx_new_window(x->disp, WIDTH, HEIGHT, all->title[MBROT]);
	if (x->win[MBROT] == NULL)
		return (all->err = error(ERR_MLX_NEW_WINDOW), free(x->disp), false);
	x->win[JULIA] = mlx_new_window(x->disp, WIDTH, HEIGHT, all->title[JULIA]);
	if (x->win[JULIA] == NULL)
		return (
			all->err = error(ERR_MLX_NEW_WINDOW),
			mlx_destroy_window(x->disp, x->win[MBROT]),
			free(x->disp),
			false
		);
	return (true);
}

//TODO: Implement beyond current dummy state..........................................
// Also REMEMBER TODO after that: Delete images on quit
static bool	provide__buffers(t_all *all)
{
	(void) all;
	return (true);
}

static void	setup__hooks(t_all *all)
{
	mlx_key_hook(all->x.win[MBROT], &key_mbrot, all);
	mlx_key_hook(all->x.win[JULIA], &key_julia, all);
	mlx_mouse_hook(all->x.win[MBROT], &mouse_mbrot, all);
	mlx_mouse_hook(all->x.win[JULIA], &mouse_julia, all);
	mlx_hook(all->x.win[MBROT], DestroyNotify, 0, &close_mbrot, all);
	mlx_hook(all->x.win[JULIA], DestroyNotify, 0, &close_julia, all);
	mlx_loop_hook(all->x.disp, &waiting_for_godot, all);
}
