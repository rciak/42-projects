/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:41:40 by reciak            #+#    #+#             */
/*   Updated: 2025/07/12 21:01:44 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fractol.h
 * @brief The header file for reciak's fractol project of the Common Core
 */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <X11/X.h>
# include <X11/keysym.h>
//
// Wenn das so nicht funktioniert:
// # define XK_MISCELLANY
// # define XK_LATIN1
// # include <X11/keysymdef.h>
//
# include <mlx.h>
# include "libft.h"

/**
 * @note The window WIDTH and HEIGTH were chosen according to the heuristic
 *       that calculation will be faster when as much a possible is 
 *       built around factors $2^k$, $k\in\Z$.
 * @note To ensure good spliting into halves the constants
 *       \p WIN_WIDTH and \p WIN_HEIGHT should accoringly be chosen to be
 *       of form $2^n + 1$ with $n\in\N$. 
 */
enum e_geo_win
{
	WIN_WIDTH = 1025,
	WIN_HEIGHT = 1025
};

enum e_misc
{
	MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL = 314
};

#endif
