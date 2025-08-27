/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_godot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:14:57 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 10:52:51 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file waiting_for_godot.c
 * @brief Stores the definition of waiting_for_godot()
 */

#include "fractol.h"

static void	react__on(int there, t_all *all);
static void	destroy___window_and_images(int there, t_x *x);
static bool	calc___next_row(int there, int mode, t_all *all);
static void	set__pixel(int k, int l, int iter, t_image *img_iter);

/**
 * @brief The function that will be called back over and over by the mlx_loop
 *
 * @note Essentially this function is responsible for calculating the 
 *       Images in a way that leaves space to react on new events
 *       even if the current reaction is not yet complete.
 * @param[in,out] all the name is program ...
 * @return `MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL` arbitrary value
 */
int	waiting_for_godot(t_all *all)
{
	if (all->x.win[MBROT] != NULL)
		react__on(MBROT, all);
	if (all->x.win[JULIA] != NULL)
		react__on(JULIA, all);
	return (MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL);
}

static void	react__on(int there, t_all *all)
{
	bool		last_row_just_treated;
	t_x			*x;

	x = &all->x;
	if (x->close[there] == true)
	{
		destroy___window_and_images(there, x);
		x->close[there] = false;
		x->recalc[there] = false;
		return ;
	}
	if (x->recalc[there] == true)
	{
		last_row_just_treated = calc___next_row(there, START_ANEW, all);
		x->recalc[there] = false;
	}
	else
		last_row_just_treated = calc___next_row(there, CONTINUE, all);
	if (last_row_just_treated == false)
		return ;
	x->recalc[there] = false;
	img_iter_to_color(all->img_iter[there], all->img_draw[there], 
		all->math[there].max_iter, all->palette);
	mlx_put_image_to_window(x->disp, x->win[there], x->meta_draw[there], 0, 0);
}

static void	destroy___window_and_images(int there, t_x *x)
{
	if (x->meta_iter[there] != NULL)
		mlx_destroy_image(x->disp, x->meta_iter[there]);
	if (x->meta_draw[there] != NULL)
		mlx_destroy_image(x->disp, x->meta_draw[there]);
	mlx_destroy_window(x->disp, x->win[there]);
	x->meta_iter[there] = NULL;
	x->meta_draw[there] = NULL;
	x->win[there] = NULL;
}
/**
 * @brief Calculates the next row for "image" img_iter
 * @note In each "pixel" is stored the number of iterations until
 *       an escape criteria was fulfilled or the maximal number of iterations
 *       was reached.
 * @param[in] there Either `MBROT` or `JULIA`
 * @param[in] mode Either `START_ANEW` or `CONTINUE`. In case of `START_ANEW`
 *                 the calculation starts all over from the first line
 *                 (with new math parameters that might have changed due to
 *                 event handlers). In case of `CONTINUE` the next uncalculated
 *                 row is treated.
 * @return
 *         * true, if the just calculated row was the last one
 *         * false, else
 * @note 
 */
static bool	calc___next_row(int there, int mode, t_all *all)
{
	int			k;
	static int	l[2] = {0, 0};
	int			iter;

	if (mode == START_ANEW)
		l[there] = 0;
	if (l[there] >= HEIGHT)
		return (false);
	k = 0;
	while (k < WIDTH)
	{
		iter = calc_iterations(k, l[there], &all->math[there], there);
		set__pixel(k, l[there], iter, &all->img_iter[there]);
		k++;
	}
	l[there]++;
	if (l[there] == HEIGHT)
			return (true);
	return (false);
}

static void	set__pixel(int k, int l, int iter, t_image *img)
{
	*(int *)(img->buf
			+ l * img->size_line
			+ k * img->bytes_per_pixel) = iter;
}
