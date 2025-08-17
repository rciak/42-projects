/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_godot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:14:57 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 12:22:39 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file waiting_for_godot.c
 * @brief Stores the definition of waiting_for_godot()
 */

#include "fractol.h"

static void	react__mbrot(t_all *all);
static void	react__julia(t_all *all);
//                      static void	destroy___window_and_images(t_x	*x, int which);

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
		react__mbrot(all);
	if (all->x.win[MBROT] != NULL)
		react__julia(all);
	return (MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL);
}



static void	react__mbrot(t_all *all)
{
	if (all->x.close[MBROT] == true)
		mlx_destroy_window(all->x.disp, all->x.win[MBROT]);
	all->x.close[MBROT] = false;
}

static void	react__julia(t_all *all)
{
	if (all->x.close[JULIA] == true)
		mlx_destroy_window(all->x.disp, all->x.win[JULIA]);
	all->x.close[JULIA] = false;
}


// static void	react__mbrot(t_all *all)
// {
// 	if (all->x.close[MBROT] == true)
// 		destroy___window_and_images(&all->x, MBROT);
// }

// static void	react__julia(t_all *all)
// {
// 	if (all->x.close[JULIA] == true)
// 		destroy___window_and_images(&all->x, JULIA);
// }

// static void	destroy___window_and_images(t_x	*x, int which)
// {
// 	mlx_destroy_window(x->disp, x->win[which]);
// }

