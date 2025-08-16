/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_non_mlx_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:52:14 by reciak            #+#    #+#             */
/*   Updated: 2025/08/15 17:20:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_non_mlx_vars.c
 * @brief Stores the definition of init_non_mlx_vars()
 */

#include "fractol.h"

static bool	args__ok(int ac, char **av);
static bool	julia___param_ok(char *s);
static bool	fractal___is_implemented(char *str);

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
	t_libft_err err_atof[2];
	
	if (!args__ok(argc, argv))
		return (all->err = error(ERR_ARG), false);
	ft_bzero(all, sizeof(*all));
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		all->julia_param.re = atof_strict(argv[2], &err_atof[0]);
		all->julia_param.im = atof_strict(argv[2], &err_atof[1]);
		if (err_atof[0] != E_ATOF_NO_ERR || err_atof[1] != E_ATOF_NO_ERR)
			return (all->err = error(ERR_ATOF_STRICT), false);
	}
	else
	{
		all->julia_param.re = 0.0;
		all->julia_param.im = 0.0;
	}
	all->title[MBROT] = "Fractol - Connectedness locus";
	all->title[JULIA] = "Fractol - Filled Julia set";
	return (all->err = error(ERR_NONE), true);
}

static bool	args__ok(int ac, char **av)
{
	if (ac < 1 + 1
		|| (ft_strcmp(av[1], "Julia") != 0 && ac != 1 + 1)
		|| (ft_strcmp(av[1], "Julia") == 0 && ac != 1 + 3)
		|| (ft_strcmp(av[1], "Julia") == 0 && !julia___param_ok(av[2]))
		|| (ft_strcmp(av[1], "Julia") == 0 && !julia___param_ok(av[3]))
		|| !(fractal___is_implemented(av[1]))
	)
		return (false);
	return (true);
}

static bool	julia___param_ok(char *s)
{
	size_t	count;

	if (!is_in(*s, "+-0123456789"))
		return (false);
	if (is_in(*s, "+-"))
		s++;
	count = skip(&s, "0123456789");
	if (count == 0 || count > PARSE_MAX_DIGITS_PRE || (*s != '\0' && *s != '.'))
		return (false);
	if (*s == '\0')
		return (true);
	if (*s == '.')
		s++;
	count = skip(&s, "0123456789");
	if (count == 0 || count > PARSE_MAX_DIGITS_AFTER || *s != '\0')
		return (false);
	return (true);
}

static bool	fractal___is_implemented(char *str)
{
	const char	*allowed[] = {"Julia", "Mandelbrot", "m2",
		"m3", "m4", "m5", "m6", "m7", "m8", NULL};

	if (is_listed(str, allowed))
		return (true);
	return (false);
}

