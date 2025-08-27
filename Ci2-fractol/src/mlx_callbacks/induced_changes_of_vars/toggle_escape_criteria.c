/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_escape_criteria.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:10:37 by reciak            #+#    #+#             */
/*   Updated: 2025/08/27 19:28:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file toggle_escape_criteria.c
 * @brief Stores the definition of toggle_escape_criteria()
 */

#include "fractol.h"

/**
 * @brief Toggles the escape_criteria: A circular one is replaced by
 *        a quadratic one and the other way roung.
 * @param[in,out] esc_criteria The address of a pointer to a function that
 *        implements an escape criteria
 */
void	toggle_escape_criteria(bool (**esc_criteria)(t_cmplx, t_cmplx))
{
	if (*esc_criteria == &criteria_circle_mbrot)
		*esc_criteria = &criteria_square_mbrot;
	else if (*esc_criteria == &criteria_square_mbrot)
		*esc_criteria = &criteria_circle_mbrot;
	else if (*esc_criteria == &criteria_circle_julia)
		*esc_criteria = &criteria_square_julia;
	else if (*esc_criteria == &criteria_square_julia)
		*esc_criteria = &criteria_circle_julia;
}
