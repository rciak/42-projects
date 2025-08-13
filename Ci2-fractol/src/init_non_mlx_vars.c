/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_non_mlx_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:52:14 by reciak            #+#    #+#             */
/*   Updated: 2025/08/13 19:42:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_non_mlx_vars.c
 * @brief Stores the definition of init_non_mlx_vars()
 */

#include "fractol.h"

static bool	args__ok(int ac, char **av);

//TODO: Implement     this function and its
//                    helper beyond current incomplete  state.........................

/**
 * @brief Parses the input from the command line and inits the non mlx vars.
 *
 * @param[in] ac Number of arguments from the command line
 * @param[in] av The arguments `av[0]`, ..., `av[ac - 1]`
 * @param[out] all The accordingly set variables
 *                 (except the mlx stuff in all->x)
 * @return 
 *          * true, if parsing worked
 *          * false, on error
 */
bool	init_non_mlx_vars(int argc, char **argv, t_all *all)
{
	if (!args__ok(argc, argv))
		return (all->err = error(ERR_ARG), false);
	return (all->err = error(ERR_NONE), true);
	ft_bzero(all, sizeof(*all));
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		all->julia_param.re = fx_atold(argv[2]);
		all->julia_param.im = fx_atold(argv[2]);
	}
	else
	{
		all->julia_param.re = 0.0;
		all->julia_param.im = 0.0;
	}
	all->title[MBROT] = "Fractol - Connectedness locus";
	all->title[JULIA] = "Fractol - Filled Julia set";
}

static bool	args__ok(int ac, char **av)
{
	if (ac < 1 + 1
		|| (ft_strcmp(av[1], "Julia") != 0 && ac != 1 + 1)
		|| (ft_strcmp(av[1], "Julia") == 0 && ac != 1 + 3)
		|| (ft_strcmp(av[1], "Julia") == 0 && !julia__params_ok(av[2], av[3]))
		|| !(fractal__is_implemented(av[1]))
	)
		return (false);
	return (true);
}

