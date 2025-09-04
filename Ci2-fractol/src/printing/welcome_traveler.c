/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_traveler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:35:43 by reciak            #+#    #+#             */
/*   Updated: 2025/09/04 18:56:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file welcome_traveler.c
 * @brief Stores the definition of welcome_traveler()
 */

#include "fractol.h"

/**
 * @brief Greets the user and gives an short overview on how to use fractol
 */
void	welcome_traveler(void)
{
	ft_putstr_fd(WELCOME_MESSAGE, STDOUT_FILENO);
}
