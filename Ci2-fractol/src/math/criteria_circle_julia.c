/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criteria_circle_julia.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:33:15 by reciak            #+#    #+#             */
/*   Updated: 2025/08/25 16:10:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file criteria_circle_julia.c
 * @brief Stores the definition of criteria_circle_julia()
 */

#include "fractol.h"

/**
 * @brief Implements a circular escape criteria for Julia sets
 *        to the parameter `w`.
 * @param[in] \p z, \p w The pair of complex numbers to be checked.
 * @return
 *          * true, if the escape criteria is meet
 *          * false, else
 */
bool	criteria_circle_julia(t_cmplx z, t_cmplx w)
{
	if (z.re * z.re + z.im * z.im > 4 
		&& z.re * z.re + z.im * z.im > w.re * w.re + w.im * w.im)
		return (true);
	return (false);
}
