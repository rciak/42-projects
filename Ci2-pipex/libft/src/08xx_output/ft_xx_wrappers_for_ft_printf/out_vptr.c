/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_vptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:31:33 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 11:06:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_vptr.c
 * @brief Stores the definition of out_vptr()
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_vptr_fd() when the output goes to stdout.
 */
int	out_vptr(void *ptr)
{
	return (out_vptr_fd(ptr, STDOUT_FILENO));
}
