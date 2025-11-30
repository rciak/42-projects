/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_reset_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:39:43 by reciak            #+#    #+#             */
/*   Updated: 2025/11/30 14:38:16 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_and_reset.c
 * @brief Stores the definition of free_and_reset()
 */

#include "pipex_bonus.h"

/**
 * @brief Frees memory and resets the corresponding pointer to NULL
 * @param[in,out] p_ptr The address of the pointer given to free.
 */

void	free_and_reset(char **p_ptr)
{
	free (*p_ptr);
	*p_ptr = NULL;
}
