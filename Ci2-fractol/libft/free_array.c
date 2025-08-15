/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:12:45 by reciak            #+#    #+#             */
/*   Updated: 2025/08/15 14:25:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_array.c
 * @brief Stores the definition of free_array()
 */

#include "libft.h"

/**
 * @brief Frees the corresponding strings and the array (`NULL` terminated!).
 * @note Typical used to free the allocations done by ft_split().
 * @param[in] string_array Containing pointers to the allocated strings.
 */
void	free_array(char **string_array)
{
	char **p_char_pointer;

	p_char_pointer = string_array;
	while (*p_char_pointer != NULL)
	{
		free (*p_char_pointer);
		(*p_char_pointer)++;
	}
	free (string_array);
}