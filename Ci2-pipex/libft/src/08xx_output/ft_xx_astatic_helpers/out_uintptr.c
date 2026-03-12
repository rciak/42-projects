/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_uintptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:31:17 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 11:05:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_uintptr.c
 * @brief Stores the definition of out_uintptr()
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_uintptr_fd()
 *        when the output goes to stdout.
 */
int	out_uintptr(uintptr_t unbr, char *digits)
{
	return (out_uintptr_fd(unbr, digits, STDOUT_FILENO));
}
