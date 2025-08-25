/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:03:03 by rene              #+#    #+#             */
/*   Updated: 2025/08/25 16:21:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_math.c
 * @brief Stores the definition of init_math()
 */

#include "fractol.h"

static void init__square(t_square *square);
static void	set__iter_fun(t_cmplx (**fun)(t_cmplx z, t_cmplx w), char *formula);

/**
 * @brief This is a helper for init_non_mlx_vars()
 *        which takes care of initalising the math variables.
 * @note E.g. for `MBROT` it does make only sense to initialise `z_0 = 0` here
 *       (which will never change),
 *       but not `w_0` (which will change from pixel to pixel later on!) 
 *       whereas for for `JULIA` it is just the other way round: 
 *       `z_0` will change from pixel to pixel, while `w_0` does not
 *       (as long as one does not switch to another Julia set of course 
 *        by changing the Julia parameters, which would change w_0 to the
 *        corresponding complex number).
 */
bool	init_math(t_math *math, char **argv, char *id, t_err *err)
{
	t_libft_err err_atof[2];

	math[MBROT].z_0.re = 0.0;
	math[MBROT].z_0.im = 0.0;
	math[JULIA].w_0.re = 0.0;
	math[JULIA].w_0.im = 0.0;
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		err_atof[0] = E_ATOF_NO_ERR;
		err_atof[1] = E_ATOF_NO_ERR;
		math[JULIA].w_0.re = atof_strict(argv[2], &err_atof[0]);
		math[JULIA].w_0.im = atof_strict(argv[2], &err_atof[1]);
		if (err_atof[0] != E_ATOF_NO_ERR || err_atof[1] != E_ATOF_NO_ERR)
			return (*err = error(ERR_ATOF_STRICT), false);
	}
	init__square(&math[MBROT].square);
	init__square(&math[JULIA].square);
	math[MBROT].max_iter = INIT_MAX_ITER;
	math[JULIA].max_iter = INIT_MAX_ITER;
	set__iter_fun(&math[MBROT].iter_fun, id);
	set__iter_fun(&math[JULIA].iter_fun, id);
	math[MBROT].will_escape = &criteria_square_mbrot;
	math[JULIA].will_escape = &criteria_circle_julia;
	return (true);
}

static void init__square(t_square *square)
{
	square->up_left.re = -2.0;
	square->up_left.im = -2.0;
	square->side_len = 4.0;
	square->down_right.re = 2.0;
	square->down_right.im = 2.0;
}

//                                                   EXTEND FUNCTION after the other math functions are implmented
static void	set__iter_fun(t_cmplx (**fun)(t_cmplx z, t_cmplx w), char *formula)
{
	if (ft_strcmp(formula, "m2") == 0)
		*fun = &fun_m2;
}