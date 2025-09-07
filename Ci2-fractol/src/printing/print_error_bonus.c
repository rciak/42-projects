/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:32:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 15:40:54 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_error.c
 * @brief Stores the definition of print_error()
 */

#include "fractol_bonus.h"

/**
 * @brief Prints an error message and its (fractol) error code, cf. error()
 * @param[in] err the to be printed error message and
 *                the correspondingerror code.
 */
void	print_error(t_err err)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd((char *) err.msg, STDERR_FILENO);
	ft_putstr_fd("\nError code: ", STDERR_FILENO);
	ft_putnbr_fd(err.code, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
