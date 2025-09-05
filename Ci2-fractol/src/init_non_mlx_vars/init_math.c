/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:03:03 by rene              #+#    #+#             */
/*   Updated: 2025/09/05 12:34:52 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_math.c
 * @brief Stores the definition of init_math()
 */

#include "fractol.h"

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
	t_libft_err	err_atof[2];

	math[MBROT].z_0.re = 0.0;
	math[MBROT].z_0.im = 0.0;
	math[JULIA].w_0.re = 0.0;
	math[JULIA].w_0.im = 0.0;
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		err_atof[0] = E_ATOF_NO_ERR;
		err_atof[1] = E_ATOF_NO_ERR;
		math[JULIA].w_0.re = atof_strict(argv[2], &err_atof[0]);
		math[JULIA].w_0.im = atof_strict(argv[3], &err_atof[1]);
		if (err_atof[0] != E_ATOF_NO_ERR || err_atof[1] != E_ATOF_NO_ERR)
			return (*err = error(ERR_ATOF_STRICT), false);
	}
	reset_square(&math[MBROT].square);
	reset_square(&math[JULIA].square);
	math[MBROT].max_iter = INIT_MAX_ITER;
	math[JULIA].max_iter = INIT_MAX_ITER;
	set__iter_fun(&math[MBROT].iter_fun, id);
	set__iter_fun(&math[JULIA].iter_fun, id);
	math[MBROT].will_escape = &criteria_square_mbrot;
	math[JULIA].will_escape = &criteria_circle_julia;
	return (true);
}

static void	set__iter_fun(t_cmplx (**fun)(t_cmplx z, t_cmplx w), char *formula)
{
	if (ft_strcmp(formula, "m2") == 0)
		*fun = &z_pow_2_plus_w;
	else if (ft_strcmp(formula, "m3") == 0)
		*fun = &z_pow_3_plus_w;
	else if (ft_strcmp(formula, "m4") == 0)
		*fun = &z_pow_4_plus_w;
	else if (ft_strcmp(formula, "m5") == 0)
		*fun = &z_pow_5_plus_w;
	else if (ft_strcmp(formula, "m6") == 0)
		*fun = &z_pow_6_plus_w;
	else if (ft_strcmp(formula, "m7") == 0)
		*fun = &z_pow_7_plus_w;
	else if (ft_strcmp(formula, "m8") == 0)
		*fun = &z_pow_8_plus_w;
	else if (ft_strcmp(formula, "m9") == 0)
		*fun = &z_pow_9_plus_w;
}
