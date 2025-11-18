/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:26:51 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 08:01:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_exit_msg.c
 * @brief Stores the definition of print_exit_msg()
 */

#include "pipex.h"

/**
 * @brief Prints the handed over error message to stderr
 */
void	print_exit_msg(const t_err *err)
{
	out_str_fd("Exiting pipex\n  --> ", STDERR_FILENO);
	out_str_fd((char *)err->exit.msg, STDERR_FILENO);
	out_str_fd("\n", STDERR_FILENO);
}
