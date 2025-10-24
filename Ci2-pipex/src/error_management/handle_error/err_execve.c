/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:01:05 by reciak            #+#    #+#             */
/*   Updated: 2025/10/24 12:56:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file err_execve.c
 * @brief Stores the definition of err_execve()
 */

#include "pipex.h"

/**
 * @brief Treat @c ERR_EXECVE
 */
int	err_execve(t_data *data, t_x_err *x_err)
{
	if (x_err->code != ERR_EXECVE)
		exit (EXITCODE_ERR_LOGIC);
	final_free(*data);
	return (EXITCODE_ERR_EXECVE);
}
