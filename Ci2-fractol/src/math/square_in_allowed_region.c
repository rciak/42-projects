/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_in_allowed_region.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:03:29 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 22:11:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file square_in_allowed_region.c
 * @brief Stores the definition of square_in_allowed_region()
 */

#include "fractol.h"

/**
 * @brief Checks if a square is in the allowed region.
 *
 * @note This essential prevents overflow of @code square->up_left @endcode
 *       and @code square->down_right @endcode,
 *       avoiding the double values /states "+infinity" or "-infinity".
 * @param[in] square a pointer to the square to test
 * @return 
 *          * true if square is in the allowed region
 *          * false, else
 */
bool	square_in_allowed_region(const t_square *square)
{
	t_cmplx	u;
	t_cmplx	d;

	u = square->up_left;
	d = square->down_right;
	if (UP_LEFT_LIMIT_RE <= u.re
		&& UP_LEFT_LIMIT_IM <= u.im
		&& d.re <= DOWN_RIGHT_LIMIT_RE
		&& d.im <= DOWN_RIGHT_LIMIT_IM)
		return (true);
	return (false);
}
