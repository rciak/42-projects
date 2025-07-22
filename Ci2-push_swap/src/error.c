/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:30:34 by reciak            #+#    #+#             */
/*   Updated: 2025/07/22 09:23:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file  error.c
 * @brief Convenient error handling and printing.
 */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

/**
 * @note In contrast to gnl I declared it here as static reducing the
 *       "risk" of stack overflow (though it seems very unlikely anyway)
 */
t_err	error(int error_code)
{
	static const t_err	err[] = {
	{ERR_NONE, "push_swap: Success - no error detected", ""},
	{ERR_ARG_NUM, "push_swap: Wrong number of arguments",
		"- Give at least one!"},
	{ERR_ARGV, "push_swap: Invalid arguments - Only integers are allowed!"},
	{ERR_MALLOC, "push_swap: Memory allocation failed"}
	};

	return (err[error_code]);
}

void	print_error(t_err err)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putnbr_fd(err.code, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd((char *) err.msg, STDERR_FILENO);
}
