/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:40:35 by reciak            #+#    #+#             */
/*   Updated: 2025/10/20 17:58:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_error.c
 * @brief Stores the definition of handle_error()
 */

#include "pipex.h"

/**
 * @brief Transforms error information into an exit code and take action if need
 * @param[in] x_err Error information
 * @return exit code
 */
int	handle__error(t_x_err x_err)
{
	if (x_err.code == ERR_NONE)
		return (EXITCODE_ERR_NONE);
	if (x_err.code == ERR_FORK && x_err.saved_errno == EAGAIN)
		return (EXITCODE_ERR_FORK);
	return (EXITCODE_MISC_ERROR);
}
