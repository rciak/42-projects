/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:12:45 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 12:01:10 by reciak           ###   ########.fr       */
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
 * @remark (17.10.2025) Found and fixed a bug that was in till commit
 *           3a5f6e5a4109daf61fec0bc4b86b671e9bd550c3    (branch  Ci2-pipex)
 *         This fix was also commited in the main branch at commit
 *           3bb347579ba2f66aa53e8b5a73477807a88cdaa1
 */
void	free_array(char **string_array)
{
	char	**p_char_pointer;

	p_char_pointer = string_array;
	while (*p_char_pointer != NULL)
	{
		free (*p_char_pointer);
		p_char_pointer++;
	}
	free (string_array);
}
