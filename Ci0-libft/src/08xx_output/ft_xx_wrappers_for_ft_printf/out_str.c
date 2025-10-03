/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:31:09 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 11:06:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_str.c
 * @brief Stores the definition of out_str()
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_str_fd() when the output goes to stdout.
 */
int	out_str(char *str)
{
	return (out_str_fd(str, STDOUT_FILENO));
}
