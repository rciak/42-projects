/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:31:27 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 11:05:17 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_unbr.c
 * @brief Stores the definition of out_unbr()
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_unbr_fd() when the output goes to stdout.
 */
int	out_unbr(unsigned int nbr, char *digits)
{
	return (out_unbr_fd(nbr, digits, STDOUT_FILENO));
}
