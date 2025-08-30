/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:17:37 by reciak            #+#    #+#             */
/*   Updated: 2025/08/30 13:49:30 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_info.c
 * @brief Stores the definition of print_info()
 */

#include "fractol.h"

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
	static int info_nr = 0;

	info_nr++;
	ft_putstr_fd("\n*********************************************************"
		"***********", STDOUT_FILENO);
	ft_putstr_fd("\n                           Info No. ", STDOUT_FILENO);
	ft_putnbr_fd(info_nr, STDOUT_FILENO);
	ft_putstr_fd("\n*********************************************************"
		"***********", STDOUT_FILENO);
	ft_putstr_fd("\n           ", STDOUT_FILENO);
	ft_putstr_fd("\nWindow:  ", STDOUT_FILENO);
	ft_putstr_fd(title, STDOUT_FILENO);

	ft_putstr_fd("\n  "RED"x"RESET"------ ", STDOUT_FILENO);
	ft_putstr_fd("\n  |      |", STDOUT_FILENO);
	ft_putstr_fd("\n  |      | ", STDOUT_FILENO);
	put_double(math->square.side_len);
	ft_putstr_fd("   <-- Side length of square", STDOUT_FILENO);
	ft_putstr_fd("\n  |      |", STDOUT_FILENO);
	ft_putstr_fd("\n   ------"YELLOW"x"RESET, STDOUT_FILENO);

	ft_putstr_fd(RED"\n  Up-left:    "RESET, STDOUT_FILENO);
	put_double(math->square.up_left.re);
	ft_putstr_fd("  +i(", STDOUT_FILENO);
	put_double(math->square.up_left.im);
	ft_putstr_fd(")", STDOUT_FILENO);


	ft_putstr_fd(YELLOW"\n  Down-right: "RESET, STDOUT_FILENO);
	put_double(math->square.down_right.re);
	ft_putstr_fd("  +i(", STDOUT_FILENO);
	put_double(math->square.down_right.im);
	ft_putstr_fd(")", STDOUT_FILENO);
	ft_putstr_fd("\n           ", STDOUT_FILENO);

	ft_putstr_fd("\nClick", STDOUT_FILENO);
	ft_putstr_fd("\n  At: (", STDOUT_FILENO);
	ft_putnbr_fd(k, STDOUT_FILENO);
	ft_putstr_fd(", ", STDOUT_FILENO);
	ft_putnbr_fd(l, STDOUT_FILENO);
	ft_putstr_fd(")", STDOUT_FILENO);
	t_cmplx	a;
	ft_putstr_fd("\n  Complex number: ", STDOUT_FILENO);
	a = coord_transf(k, l, math->square);
	put_double(a.re);
	ft_putstr_fd("  +i(", STDOUT_FILENO);
	put_double(a.im);
	ft_putstr_fd(")", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

