/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_and_reset_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:48:36 by reciak            #+#    #+#             */
/*   Updated: 2025/11/30 14:38:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_array_and_reset.c
 * @brief Stores the definition of free_array_and_reset()
 */

#include "pipex_bonus.h"

/**
 * @brief Frees a (heap allocated) array of strings and NULLS its **pointer**
 * @param[in,out] p_arr The address of the array
 */
void	free_array_and_reset(char ***p_arr)
{
	free_array(*p_arr);
	*p_arr = NULL;
}
