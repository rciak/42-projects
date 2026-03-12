/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_deli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:24:05 by reciak            #+#    #+#             */
/*   Updated: 2025/09/27 21:25:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file strlen_deli.c
 * @brief Stores the definition of strlen_deli()
 */

#include "libft.h"

/**
 * @brief Counts the length of given string till the nullterminator is hit
 *        or any of the additional defined delimiters.
 * @param[in] s pointer to a nullterminated string whose quasi-length
 *              shall be found.
 * @param[in] deli pointer to a nullterminated string which
 *                 contains the additional delimiting characters.
 * @note If \p s is `NULL` then `strlen_deli` will segfault - this is intended.
 * @note ft_strlen() corresponds to strlen_deli() with an empty string
 *       as delimiter set.
 * @remark The number `strlen_deli(s)` can be viewed in different ways:
 *         * As *quasi-length* of the string s,
 *         * As *index of the Nullterminator* of s or of the first occurence
 *           of one of the additional defined delimiters.
 * @return The quasi-length of the string.
 */
size_t	strlen_deli(const char *s, const char *deli)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_in(s[i], deli))
		i++;
	return (i);
}
