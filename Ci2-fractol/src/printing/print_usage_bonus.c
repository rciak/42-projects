/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:53:40 by reciak            #+#    #+#             */
/*   Updated: 2025/09/06 22:00:56 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_usage.c
 * @brief Stores the definition of print_usage()
 */

#include "fractol_bonus.h"

/**
 * @brief Prints help information
 */

void	print_usage(void)
{
	const char	*msg
		= "\n\
Just to please the queen (subject sheet) note that fractol must be\n\
called with a parameter or a 3 parameters as in the following list: \n\
             m2\n\
             m3\n\
             m4\n\
             m5\n\
             m6\n\
             m7\n\
             m8\n\
             m9\n\
             Mandelbrot\n\
             Julia  x  y\n\
with floats x y consisting of at most 2 integer- and 7 fractional digits.\n";

	ft_putstr_fd((char *) msg, STDOUT_FILENO);
}
