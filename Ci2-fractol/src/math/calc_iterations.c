/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_iterations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:37:32 by reciak            #+#    #+#             */
/*   Updated: 2025/08/25 19:13:16 by reciak           ###   ########.fr       */
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
 * @param[in]  ....
 * @param[out] ...
 * @param[in,out]
 * @return The counted number of iterations
 */
// TODO:                                                               Document better
// TODO:                                                                 IMPLEMENT!
int	calc_iterations(int k, int l, t_math math, int fractal_kind)
{
(void) math;
	if (fractal_kind == MBROT)
		return ((k + l) % 120);
		// STartvalues z = 0 and w = transf(k, l, math)
	if (fractal_kind == JULIA)
		return ((k) % PALETTE_COLORS);
		// STartvalues z = transf(k, l, math) and w = Julia_params
return (0);
	
}