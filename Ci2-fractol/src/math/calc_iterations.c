/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_iterations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:37:32 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 17:36:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file calc_iterations.c
 * @brief Stores the definition of calc_iterations()
 */

#include "fractol.h"

/**
 * @brief Iterates till an escape criteria is met
 *        or the maximum number of iteration is reached and return the counted
 *        iterations.
 * @note 
 * @param[in] k The horizontal grid coordinate of the clicked pixel
 * @param[in] l The vertical grid coordinate of the clicked pixel
 * @param[in] math Well everything need for iterating -
 *                 Initial values, view information (square),
 *                 the (currently) max. number of iterations,
 *                 a pointer to the function used for iterating 
 *                 (in its first variable) and a pointer to the escape criteria
 * @return The counted number of iterations
 */
int	calc_iterations(int k, int l, const t_math *math, int fractal_kind)
{
	int		count;
	t_cmplx	z;
	t_cmplx	w;

	if (fractal_kind == MBROT)
	{
		z = math->z_0;
		w = coord_transf(k, l, math->square);
	}
	else if (fractal_kind == JULIA)
	{
		z = coord_transf(k, l, math->square);
		w = math->w_0;
	}
	count = 0;
	while (count < math->max_iter && math->will_escape(z, w) == false)
	{
		z = math->iter_fun(z, w);
		count++;
	}
	return (count);
}
