/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:30:46 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 11:04:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_nbr.c
 * @brief Stores the definition of out_nbr()
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_nbr_fd() when the output goes to stdout.
 */
int	out_nbr(int nbr, char *digits)
{
	return (out_nbr_fd(nbr, digits, STDOUT_FILENO));
}
