/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_strtools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:15:36 by reciak            #+#    #+#             */
/*   Updated: 2025/05/12 17:00:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_strtools1.c
 * @brief Stores the definitions of some useful functions in the string context.
 */

#include "libft.h"

/**
 * @brief Tell whether a character is in a string or not.
 * @note `is_in` is a convenient "downgrade" for ft_strchr()
 * @param[in] c A character of interest
 * @param[in] str A pointer to string that should be scanned for \p c.
 * @return 
 *          * true, if \p str contains \p c
 *          * false, if \p str does not contain \p c.
 */
bool	is_in(char c, const char *str)
{
	return (ft_strchr(str, (int) c) != NULL);
}