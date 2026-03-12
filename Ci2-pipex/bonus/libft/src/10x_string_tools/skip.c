/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:00:25 by reciak            #+#    #+#             */
/*   Updated: 2025/09/27 21:01:58 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file skip.c
 * @brief Stores the definition of skip()
 */

#include "libft.h"

/**
 * @brief ++ a char pointer until it no longer sits on the to be
 *        skipped characters
 * @param[in] pstr The address of a pointer to a C string.
 * @param[in] chars_to_skip A pointer to a string containing the to be skipped 
 *            characters.
 * @return 
 *          * the number of skipped chars.
 * @note If the first character is not to be skipped the above means that
 *       the outside pointer `*pstr` will not be modified and `0` is returned.
 */
size_t	skip(char **pstr, const char *chars_to_skip)
{
	size_t	count;

	count = 0;
	while (is_in(**pstr, chars_to_skip))
	{
		(*pstr)++;
		count++;
	}
	return (count);
}
