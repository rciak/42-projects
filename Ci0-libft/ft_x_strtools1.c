/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_strtools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:15:36 by reciak            #+#    #+#             */
/*   Updated: 2025/05/12 18:15:30 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_x_strtools1.c
 * @brief Stores the definitions of some useful functions in the string context.
 */

#include "libft.h"

/**
 * @brief Tell whether a character is in a string or not.
 * @note `is_in(c, str)` can in general not be replaced by the condition
 *       `ft_strchr(str, (int) c) != NULL` as setting \p c to the
 *       *nullterminator* illustrates:
 * @note Consider this particular choice for `c` e.g. for `str = "0123456789"`.
 *       Then
 *       `is_in(c, "01234567889")` returns *false*,
 *       whereas the condition `ft_strchr(str, (int) c) != NULL` would be
 *       *true*, since `ft_strchr((int) c, "01234566789")`
 *       would return the address of the 
 *       nullterminator of "0123456789", being different from `NULL`!
 * @param[in] c A character of interest
 * @param[in] str A pointer to string that should be scanned for \p c.
 * @return 
 *          * true, if \p str contains \p c *before* the terminating  nullbyte.
 *          * false, if \p str does not contain \p c *before*
 *            the terminating nullbyte.
 */
bool	is_in(char c, const char *str)
{
	if (c == '\0')
		return (false);
	return (ft_strchr(str, (int) c) != NULL);
}
