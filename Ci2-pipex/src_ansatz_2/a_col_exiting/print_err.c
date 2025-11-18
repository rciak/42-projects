/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:39:27 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 18:32:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_err.c
 * @brief Stores the definition of print_err()
 */

#include "pipex.h"

/**
 * @brief Printing error information.
 * @param[in] 
 */
void	print_err(const t_err *err)
{
	out_str_fd("\nERROR INFO:", STDERR_FILENO);
	out_str_fd("\n  Type:   ", STDERR_FILENO);
	out_nbr_fd(err->type, "0123456789", STDERR_FILENO);
	out_str_fd("\n  errno:  ", STDERR_FILENO);
	out_nbr_fd(err->saved_errno, "0123456789", STDERR_FILENO);
	out_str_fd("\n  msg:    ", STDERR_FILENO);
	out_str_fd((char *) err->msg, STDERR_FILENO);
	out_str_fd("\n  origin: ", STDERR_FILENO);
	out_str_fd((char *) err->origin, STDERR_FILENO);
	out_str_fd("\n  - - - -", STDERR_FILENO);
	out_str_fd("\n  Exitcode: ", STDERR_FILENO);
	out_nbr_fd(err->exit.code, "0123456789", STDERR_FILENO);
	out_str_fd("\n  Exitmsg:  ", STDERR_FILENO);
	out_str_fd((char *) err->exit.msg, STDERR_FILENO);
	out_str_fd(". Exiting ...", STDERR_FILENO);
	out_str_fd("\n", STDERR_FILENO);
}
