/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_traveler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:35:43 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 23:00:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file welcome_traveler.c
 * @brief Stores the definition of welcome_traveler()
 */

#include "fractol.h"

/**
 * @brief Greats the user and gives an short overview on how to use fractol
 */
void	welcome_traveler(void)
{
	ft_putstr_fd("\nWelcome to fractol!", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
