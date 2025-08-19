/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/19 02:14:50 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	provide__windows(t_all *all);
static bool	provide__image_buffers(int there, t_all *all);
static void	destroy___all_allocated_images(t_x	*x);
static void	setup__hooks(t_all *all);

int	main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(all));
	welcome_traveler();
	if (!init_non_mlx_vars(argc, argv, &all))
		return (print_error(all.err), all.err.code);
	all.x.disp = mlx_init();
	if (all.x.disp == NULL)
		return (ERR_MLX_INIT);
	if (!provide__windows(&all) 
		|| !provide__image_buffers(MBROT, &all)
		|| !provide__image_buffers(JULIA, &all)
		|| !init_image_struct(&all.img_iter[MBROT], all.x.meta_iter[MBROT], &all.err)
		|| !init_image_struct(&all.img_draw[MBROT], all.x.meta_draw[MBROT], &all.err)
		|| !init_image_struct(&all.img_iter[JULIA], all.x.meta_iter[JULIA], &all.err)
		|| !init_image_struct(&all.img_draw[JULIA], all.x.meta_draw[JULIA], &all.err)
	)
		return (print_error(all.err), all.err.code);
	setup__hooks(&all);
	mlx_loop(all.x.disp);
	mlx_destroy_display(all.x.disp);
	free(all.x.disp);
	return (ERR_NONE);
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

static bool	provide__image_buffers(int there, t_all *all)
{
	t_x		*x;

	x = &(all->x);
	x->meta_iter[there] = mlx_new_image(x->disp, WIDTH, HEIGHT);
	if (x->meta_iter[there] == NULL)
	{
		destroy___all_allocated_images(x);
		all->err = error(ERR_MLX_NEW_IMAGE);
		return (false);
	}
	x->meta_draw[there] = mlx_new_image(x->disp, WIDTH, HEIGHT);
	if (x->meta_draw[there] == NULL)
	{
		destroy___all_allocated_images(x);
		all->err = error(ERR_MLX_NEW_IMAGE);
		return (false);
	}
	return (true);
}

static void	destroy___all_allocated_images(t_x	*x)
{
	if (x->meta_iter[MBROT] != NULL)
		mlx_destroy_image(x->disp, x->meta_iter[MBROT]);
	if (x->meta_draw[MBROT] != NULL)
		mlx_destroy_image(x->disp, x->meta_draw[MBROT]);
	if (x->meta_iter[JULIA] != NULL)
		mlx_destroy_image(x->disp, x->meta_iter[JULIA]);
	if (x->meta_draw[JULIA] != NULL)
		mlx_destroy_image(x->disp, x->meta_draw[JULIA]);
	x->meta_iter[MBROT] = NULL;
	x->meta_draw[MBROT] = NULL;
	x->meta_iter[JULIA] = NULL;
	x->meta_draw[JULIA] = NULL;
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
