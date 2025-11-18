/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit_msg_and_exit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:27:21 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 18:32:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_exit_msg_and_exit.c
 * @brief Stores the definition of print_exit_msg_and_exit()
 */

#include "pipex.h"

/**
 * @brief Prints the handed over error message to stderr and exits
 */
void	print_exit_msg_and_exit(const t_err *err)
{
	print_exit_msg(err);
	exit(err->exit.code);
}
