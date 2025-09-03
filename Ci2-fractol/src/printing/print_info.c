/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:17:37 by reciak            #+#    #+#             */
/*   Updated: 2025/09/03 16:25:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_info.c
 * @brief Stores the definition of print_info()
 */

#include "fractol.h"

static void	put__general_info(void);
static void	put__square(char *title, t_square square);
static void	put__info_click(int k, int l, t_square square);
static void	put__julia_param(t_cmplx c);

/**
 * @brief Prints info to the terminal
 *        using a static helper that is a somewhat ad hoc printing of a double.
 * @note The coordinates might be of value in finding again a beautiful part
 *       of e.g. the Mandelbrot set.
 * @param[in] k, \p l Pixelcoordinates where the mouseclick had happened.
 * @param[in] all Well some of the corresp. variables are going to be printed.
 */
void	print_info(int k, int l, char *title, const t_math *math)
{
	put__general_info();
	put__square(title, math->square);
	put__info_click(k, l, math->square);
	if (ft_strcmp(title, "Fractol - Filled Julia set") == 0)
		put__julia_param(math->w_0);
}

static void	put__general_info(void)
{
	static int	info_nr = 0;

	info_nr++;
	ft_putstr_fd("\n*********************************************************"
		"***********", STDOUT_FILENO);
	ft_putstr_fd("\n                           Info No. ", STDOUT_FILENO);
	ft_putnbr_fd(info_nr, STDOUT_FILENO);
	ft_putstr_fd("\n*********************************************************"
		"***********", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	put__square(char *title, t_square square)
{
	ft_putstr_fd("\nWindow:  ", STDOUT_FILENO);
	ft_putstr_fd(title, STDOUT_FILENO);
	ft_putstr_fd("\n  "RED"x"RESET"------ ", STDOUT_FILENO);
	ft_putstr_fd("\n  |      |", STDOUT_FILENO);
	ft_putstr_fd("\n  |      |         ", STDOUT_FILENO);
	put_double(square.side_len);
	ft_putstr_fd("  <-- Side length of square", STDOUT_FILENO);
	ft_putstr_fd("\n  |      |", STDOUT_FILENO);
	ft_putstr_fd("\n   ------"YELLOW"x"RESET, STDOUT_FILENO);
	ft_putstr_fd(RED"\n  Up-left:        "RESET, STDOUT_FILENO);
	if (square.up_left.re >= 0)
		ft_putstr_fd(" ", STDOUT_FILENO);
	put_complex_number(square.up_left);
	ft_putstr_fd(YELLOW"\n  Down-right:     "RESET, STDOUT_FILENO);
	if (square.down_right.re >= 0)
		ft_putstr_fd(" ", STDOUT_FILENO);
	put_complex_number(square.down_right);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	put__info_click(int k, int l, t_square square)
{
	t_cmplx a;
	ft_putstr_fd("\nClick", STDOUT_FILENO);
	ft_putstr_fd("\n  At: (", STDOUT_FILENO);
	ft_putnbr_fd(k, STDOUT_FILENO);
	ft_putstr_fd(", ", STDOUT_FILENO);
	ft_putnbr_fd(l, STDOUT_FILENO);
	ft_putstr_fd(")", STDOUT_FILENO);
	ft_putstr_fd("\n  Complex number: ", STDOUT_FILENO);
	a = coord_transf(k, l, square);
	if (a.re >= 0)
		ft_putstr_fd(" ", STDOUT_FILENO);
	put_complex_number(a);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	put__julia_param(t_cmplx c)
{
	ft_putstr_fd("\n"BLUE"(Julia Parameter: "RESET, STDOUT_FILENO);
	if (c.re >= 0)
		ft_putstr_fd(" ", STDOUT_FILENO);
	put_complex_number(c);
	ft_putstr_fd(BLUE")"RESET, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
