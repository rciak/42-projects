/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_and_reset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:48:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 11:10:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_array_and_reset.c
 * @brief Stores the definition of free_array_and_reset()
 */

#include "pipex.h"

/**
 * @brief Frees a (heap allocated) array of strings and NULLS its **pointer**
 * @param[in,out] p_arr The address of the array
 */
void	free_array_and_reset(char ***p_arr)
{
	free_array(*p_arr);
	*p_arr = NULL;
}
