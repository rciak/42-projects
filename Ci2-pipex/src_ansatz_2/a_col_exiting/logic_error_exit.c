/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:57:28 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 17:46:50 by reciak           ###   ########.fr       */
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
	out_str_fd((char *) msg, STDERR_FILENO);
	out_str_fd("\nAnd yes I still think it is nonsense\n"
		"to call a tidy up function before exiting and that,"
		"given the proper understanding of a memory leak"
		"not doing so does NOT CAUSE memory leaks..."
		"Let me know if you are interested in more details ;-)",
		STDERR_FILENO);
	exit(EXIT_FAILURE);
}
