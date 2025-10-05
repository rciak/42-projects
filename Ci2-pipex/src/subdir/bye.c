/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:35:19 by reciak            #+#    #+#             */
/*   Updated: 2025/10/05 17:39:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file bye.c
 * @brief Stores the definition of bye()
 */

#include "pipex.h"

/**
 * @brief Prints "Goodbye!" followed by a newline.
 * @warning To many notes are dangerous, so there a warning instead.
 */
void	bye(void)
{
	write(STDOUT_FILENO, "Goodbye!\n", ft_strlen("Goodbye!\n"));
}
