/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:41:40 by reciak            #+#    #+#             */
/*   Updated: 2025/09/05 09:49:18 by reciak           ###   ########.fr       */
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
# include <math.h>         // fabs
# include <mlx.h>
# include "libft.h"

# define ZOOM_IN_FACTOR 0.5
# define ZOOM_OUT_FACTOR 2.0
# define SHIFT_FACTOR 0.25
# define ZOOM_IN_LIMIT 0x1.p-46
# define ZOOM_OUT_LIMIT 0x1p12
// Note that increasing the  ZOOM_OUT_LIMIT  may require adopting the following:
# define UP_LEFT_LIMIT_RE -0x1p15
# define UP_LEFT_LIMIT_IM -0x1p15
# define DOWN_RIGHT_LIMIT_RE 0x1p15
# define DOWN_RIGHT_LIMIT_IM 0x1p15
# define WELCOME_MESSAGE "\n\
******************************\n\
* Welcome voyager to fractol *                                  For my friend\n\
*    the next generation!    *                                  Елене / Lena\n\
******************************\n\
\n\
EXAMPLES for STARTING fractol\n\
  ./fractol m2\n\
  ./fractol m3\n\
  ./fractol Mandelbrot                    (same as ./fractol m2)\n\
  ./fractol Julia -0.7751894 +0.124\n\
  ./fractol Julia -1.4764854 -0.0025581\n\
  ./fractol Julia -1.7577354 +0.0140434\n\
Best put the two windows side by side and then click somewhere\n\
in the window titled 'Fractol - Connectedness locus' ...\n\
\n\
INTERACTING with fractol via MOUSE\n\
  Wheel Up / Down:  Zoom in / out\n\
  Wheel-click:      Shift colors 'outwards'\n\
  Right-click:      Print infos to terminal\n\
  Left-click:       Set Julia Parameter to clicked complex number\n\
                    in the window 'Fractol - Connectedness locus'\n\
\n\
INTERACTING with fractol via KEYBOARD\n\
  Arrow keys:       Move fractal\n\
  Fake arrow keys*: Increase / decrease number of iterations as follows\n\
               W       +50\n\
             A S D  -1 -50 +1\n\
  T:                Toggle escape criteria\n\
  B:                Shift colors 'outwards'\n\
  Space Bar:        Shift colors 'inwards'\n\
  Backspace:        Reset view (e.g. if one has lost the view)\n\
  2 3               Change fractal type (Multibrot based on z |--> z^n + c)\n\
  ESC:              Quits the program\n\
  \n\
Annotation to (*) - vim friends may also use HJKL instead of ASWS keys ;-)\n\
  \n\
HINT:\n\
  If you like what you see here consider googeling xaos.app ... ;-)\n\
  Live long and prosper! 🖖\n\
\n\
ACKNOWLEDGMENTS:\n\
  Like its predecessor this fractal zoomer was strongly inspired by XaoS -\n\
  Many thanks to the many persons involved with that magnificent program!\n\
  (Cf. https://github.com/xaos-project/XaoS/blob/master/CREDITS.md)\n\
  A very big thank also to my university teachers\n\
    Stephan Ruscheweyh († 26. Juli 2019)  and  Oliver Roth\n\
  for giving wonderful lectures in 'Funktionentheorie' and in particular on\n\
  'Komplexe Chaotische Systeme'. :-)\n\
"

enum e_shift_directions
{
	LEFT_DIR,
	RIGHT_DIR,
	UP_DIR,
	DOWN_DIR,
};

enum e_iter_change_steps
{
	SMALL_STEP = 1,
	BIG_STEP = 50,
};

enum e_misc
{
	INIT_MAX_ITER = 57,
	LIMIT_MAX_ITER = 7000,
	PALETTE_COLORS = 60,                                           // TODO: ADOPT!
};

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

enum e_calc_status
{
	READY_TO_DRAW,
	ROWS_LEFT_TO_CALCULATE,
	CALCULATION_ALREADY_FINISHED_BEFORE,
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
	ERR_MLX_GET_DATA_ADDR_NULL,
	ERR_UNEXP_BITS_PER_PIXEL,
	ERR_INT_NOT_FOUR_BYTES,
	ERR_UNEXP_BIG_ENDIAN,
};

enum e_max_num_digits_previous_and_after_decimalpoint_in_parsing
{
	PARSE_MAX_DIGITS_PRE = 2,
	PARSE_MAX_DIGITS_AFTER = 7,
};

enum e_endian
{
	MLX_LITTLE_ENDIAN = 0,
	MLX_BIG_ENDIAN = 1,
};

enum e_at_least_one_complain_about_mlx_hinting_to_a_transcendent_number
{
	MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL = 314,
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
	void	*meta_iter[2];
	void	*meta_draw[2];
	bool	close[2];
	bool	recalc[2];
	bool	color_shift_requires_redraw[2];
}	t_x;

typedef struct s_image
{
	char	*buf;
	///////////////////////////////////////////////////////////////////int		bits_per_pixel;
	int		bytes_per_pixel;
	int		size_line;
	///////////////////////////////////////////////////////////////////int		endian;
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
	t_cmplx		down_right;
}	t_square;

typedef struct s_math
{
	t_cmplx		z_0;
	t_cmplx		w_0;
	t_square	square;
	int			max_iter;
	t_cmplx		(*iter_fun)(t_cmplx z, t_cmplx w);
	bool		(*will_escape)(t_cmplx z, t_cmplx w);
}	t_math;

typedef struct s_palette
{
	int		color[PALETTE_COLORS];
	int		shift;
	int		not_escaped_color;
}	t_palette;

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

typedef struct s_all
{
	char		*id;
	char		*title[2];
	t_math		math[2];
	t_image		img_iter[2];
	t_palette	palette;
	t_image		img_draw[2];
	t_x			x;
	t_err		err;
}	t_all;

////////////////////////////////////////////////////////////////////////////////
//./*.c
int		main(int argc, char **argv);
bool	init_image_struct(t_image *img, void *img_meta, t_err *err);
t_err	error(int error_code);

////////////////////////////////////////////////////////////////////////////////
//init_non_mlx_vars/*
bool	init_non_mlx_vars(int argc, char **argv, t_all *all);
bool	init_math(t_math *math, char **argv, char *id, t_err *err);
void	init_palette(t_palette *palette);
void	reset_square(t_square *square);

////////////////////////////////////////////////////////////////////////////////
//mlx_callbacks/*.c
int		close_mbrot(t_all *all);
int		key_mbrot(int key, t_all *all);
int		mouse_mbrot(int button, int k, int l, t_all *all);
//
int		close_julia(t_all *all);
int		key_julia(int key, t_all *all);
int		mouse_julia(int button, int k, int l, t_all *all);
//
int		waiting_for_godot(t_all *all);
void	img_iter_to_color(t_image iter, t_image draw, int max, t_palette pal);
//
//mlx_callbacks/induced_changes_of_vars
void	change_id(int key, char **id, t_math *math);
void	change_max_iter(int key, int *max_iter);
void	change_julia_param(int k, int l, t_cmplx *w_0, t_square square);
void	toggle_escape_criteria(bool (**esc_criteria)(t_cmplx, t_cmplx));

////////////////////////////////////////////////////////////////////////////////
//math/*.c
t_cmplx	coord_transf(int k, int l, t_square range);
int		calc_iterations(int k, int l, const t_math *math, int fractal_kind);
bool	criteria_circle_mbrot(t_cmplx z, t_cmplx w);
bool	criteria_square_mbrot(t_cmplx z, t_cmplx w);
bool	criteria_circle_julia(t_cmplx z, t_cmplx w);
bool	criteria_square_julia(t_cmplx z, t_cmplx w);
bool	square_in_allowed_region(const t_square *square);
//math/fractal_genes/*.c
t_cmplx	z_pow_2_plus_w(t_cmplx z, t_cmplx w);
t_cmplx	z_pow_3_plus_w(t_cmplx z, t_cmplx w);
//
//math/change_square/*.c
void	zoom(double factor, int k, int l, t_square *square);
void	shift(int direction, t_square *square);

////////////////////////////////////////////////////////////////////////////////
//printing/*.c
void	welcome_traveler(void);
void	print_info(int k, int l, char *title, const t_math *math);
void	print_error(t_err err);
void	put_double(double d);
void	put_complex_number(t_cmplx z);

#endif
