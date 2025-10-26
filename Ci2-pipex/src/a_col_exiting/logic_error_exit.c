/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:57:28 by reciak            #+#    #+#             */
/*   Updated: 2025/10/26 17:14:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file logic_error_exit.c
 * @brief Stores the definition of logic_error_exit()
 */

#include "pipex.h"

/**
 * @brief Prints the handed over Error Message and exits.
 * @param[in] msg The to be printed error message
 */

void	logic_error_exit(const char *msg)
{
	out_str_fd("Exiting directly because of LOGIC ERROR: \n  ", STDERR_FILENO);
	out_str_fd((char*) msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}