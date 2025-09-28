/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_listed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:21:37 by reciak            #+#    #+#             */
/*   Updated: 2025/08/15 09:39:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_listed
 * @brief Stores the definition of is_listed()
 */

#include "libft.h"

/**
 * @brief Checks if a string appears in a `NULL`-terminated array of strings.
 * @param[in] str A pointer to the string to be checked
 * @param[in] list The Address of a pointer to the first string 
 *                 of the outside array.
 * @warning If the last entry of the outside array is not `NULL` undefined
 *          behaviour occurs.
 * @return 
 *          * true, if the string is contained in the outside array.
 *          * false, if the string is not contained  in the outside array.
 */
bool	is_listed(const char *str, const char **list)
{
	while (*list != NULL)
	{
		if (ft_strcmp(str, *list) == 0)
			return (true);
		list++;
	}
	return (false);
}
