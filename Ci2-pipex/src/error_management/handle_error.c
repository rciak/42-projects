/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:40:35 by reciak            #+#    #+#             */
/*   Updated: 2025/10/24 14:12:57 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_error.c
 * @brief Stores the definition of handle_error()
 */

#include "pipex.h"

static void	print__error(t_x_err *x_err, int fd);

/**
 * @brief Transforms error information into an exit code and take action if need
 * @param[in] x_err Error information
 * @return exit code
 */
int	handle_error(t_data *data, t_x_err *x_err)
{
	print__error(x_err, STDERR_FILENO);
	if (x_err->code == ERR_NONE)
		return (EXITCODE_ERR_NONE);
	if (x_err->code == ERR_FORK && x_err->saved_errno == EAGAIN)
		return (EXITCODE_ERR_FORK);
	if (x_err->code == ERR_EXECVE)
		return (err_execve(data, x_err));
	return (EXITCODE_MISC_ERROR);
}

static void	print__error(t_x_err *x_err, int fd)
{
	out_str_fd("ERROR REPORT:", fd);
	out_str_fd("\n  origin: ", fd);
	out_str_fd((char*) x_err->origin, fd);
	out_str_fd("\n  msg:    ", fd);
	out_str_fd((char*) x_err->msg, fd);
	out_str_fd("\n  code:   ", fd);
	out_nbr_fd(x_err->code, "0123456789", fd);
	out_str_fd("\n  errno:  ", fd);
	out_nbr_fd(x_err->saved_errno, "0123456789", fd);
	out_str_fd("\n", fd);

}
