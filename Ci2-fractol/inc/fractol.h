/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:41:40 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 22:15:03 by reciak           ###   ########.fr       */
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
// Wenn das so nicht funktioniert:///////////////////////////////////////////////////
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
	WIDTH = 513,
	HEIGHT = 513,
};

/**
 * @brief For distinguishing between the window / fractoltype of kind
 *        Mandelbrot / Multibrot  or (one of the corresponding) Julia sets
 * @warning The names below must be  0 and 1
 *          since they are **used as index** !
 */
enum e_which
{
	MBROT,
	JULIA,
};

enum e_calc_mode
{
	START_ANEW,
	CONTINUE,
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
	ERR_ARG,
	ERR_ATOF_STRICT,
	ERR_MLX_INIT,
	ERR_MLX_NEW_WINDOW,
	ERR_MLX_NEW_IMAGE,
};

enum e_max_num_digits_previous_and_after_decimalpoint_in_parsing
{
	PARSE_MAX_DIGITS_PRE = 2,
	PARSE_MAX_DIGITS_AFTER = 7,
};

enum e_misc
{
	MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL = 314,
	PALETTE_COLORS = 4,                                           // TODO: ADOPT!
};

/**
 * @brief Collects mlx related variables
 * @param disp pointer from mlx_init
 * @param win pointers from mlx_new_window
 * @param img_meta_iter pointers from mlx_new_image 
 *                      (!= pointer to the pixel data!!)
 * @param img_meta_draw pointers from mlx_new_image 
 *                      (!= pointer to the pixel data!!)
 * @param recalculate Bools which indicate if recalculation is necessary,
 *                    e.g. after zooming in further before the current calc
 *                    has finished.
 * @param close Bools which indicate if a window and its corresponding images
 *              should be destroyed.
 */
typedef struct s_x
{
	void	*disp;
	void	*win[2];
	void	*img_meta_iter[2];
	void	*img_meta_draw[2];
	bool	recalc[2];
	bool	redraw[2];
	bool	close[2];
}	t_x;

typedef struct s_image
{
	int		*buf;
	int		bits_per_pixel;
	int		bytes_pp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_cmplx
{
	double	re;
	double	im;
}	t_cmplx;

typedef struct s_square
{
	t_cmplx		up_left;
	double		side_len;
}	t_square;

typedef struct s_view
{
	t_cmplx	up_left;
	t_cmplx	down_right;
}	t_view;

typedef struct s_math
{
	t_square	square;
	t_view		view;
	int			max_iter;
	t_cmplx		z_0;
	t_cmplx		w_0;
	t_cmplx		(*iter_fun)(t_cmplx z, t_cmplx w);
	bool		(*will_escape)(t_cmplx z);
}	t_math;

typedef struct s_palette
{
	int	color[PALETTE_COLORS];
	int	shift;
} t_palette;

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

typedef struct s_all
{
	char		*title[2];
	t_math		math[2];
	t_image		img_iter[2];
	t_palette	palette;
	t_image		img_draw[2];
	t_x			x;
	t_err		err;
} t_all;

//./*.c
int		main(int argc, char **argv);
bool	init_non_mlx_vars(int argc, char **argv, t_all *all);
t_err	error(int error_code);

//mlx_callbacks/*.c
int		close_mbrot(t_all *all);
int		key_mbrot(int keysym, t_all *all);
int		mouse_mbrot(int button, int k, int l, t_all *all);
//
int		close_julia(t_all *all);
int		key_julia(int keysym, t_all *all);
int		mouse_julia(int button, int k, int l, t_all *all);
//
int		waiting_for_godot(t_all *all);

//math/*.c
int		calc_iterations(int k, int l, t_math math, int fractal_kind);

//color/*.c
void iter_to_color(t_image iter, t_image draw, t_palette palette);

//printing/*.c
void	welcome_traveler(void);
void	print_error(t_err err);

#endif
