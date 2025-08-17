/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_godot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:14:57 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 12:59:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file waiting_for_godot.c
 * @brief Stores the definition of waiting_for_godot()
 */

#include "fractol.h"

static void	react__on(int there, t_all *all);
static void	destroy___window_and_images(int there, t_x *x);

/**
 * @brief The function that will be called back over and over by the mlx_loop
 *
 * @note Essentially this function is responsible for calculating the 
 *       Images in a way that leaves space to react on new events
 *       even if the current reaction is not yet complete.
 * @param[in,out] all the name is program ...
 * @return `MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL` arbitrary value
 */
int waiting_for_godot(t_all *all)
{
	if (all->x.win[MBROT] != NULL)
		react__on(MBROT, all);
	if (all->x.win[JULIA] != NULL)
		react__on(JULIA, all);
	return (MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL);
}

static void	react__on(int there, t_all *all)
{
	if (all->x.close[there] == true)
		destroy___window_and_images(there, &all->x);
}

static void	destroy___window_and_images(int there, t_x *x)
{
	/////////////////////////////////////// Implement also destruction of images later
	mlx_destroy_window(x->disp, x->win[there]);
	x->win[there] = NULL;
	x->close[there] = false;
}
