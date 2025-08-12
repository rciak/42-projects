/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:41:40 by reciak            #+#    #+#             */
/*   Updated: 2025/08/12 17:10:29 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fractol.h
 * @brief The header file for reciak's fractol project of the Common Core
 */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdbool.h>
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
 *       `WIN_WIDTH` and `WIN_HEIGHT` should accoringly be chosen to be
 *       of form $2^n + 1$ with $n\in\N$. 
 */
enum e_geo_win
{
	WIN_WIDTH = 513,
	WIN_HEIGHT = 513
};

/**
 * @warning The enumaration of the below error codes **must** be 0, 1, 2, ...
 *          since they are **used as index** in error() !
 * @warning Also the value 0 must be named by `ERR_NONE`, since ERR_NONE
 *          is used to return from main in case of no error!
 */
enum e_fractol_errors
{
	ERR_NONE,
	ERR_ARG_NUM,
	ERR_ARGV,
	ERR_MLX_INIT,
	ERR_MLX_NEW_WINDOW,
	ERR_MLX_NEW_IMAGE,
};

enum e_misc
{
	MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL = 314
};

typedef struct s_x
{
	void	*disp;
	void	*win0;
	void	*win1;
}	t_x;

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

typedef struct s_all
{
	char	*dummy_c;
	int		dummy_i;
	t_x		x;
	t_err	err;
} t_all;

//events_mbrot.c
int key_mbrot(int keysym, t_all *all);
int	mouse_mbrot(int button, int k, int l, t_all *all);

//events_julia.c
int	key_julia(int keysym, t_all *all);
int	mouse_julia(int button, int k, int l, t_all *all);

//error.c
t_err	error(int error_code);
void	print_error(t_err err);

#endif
