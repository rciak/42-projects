/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:21:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 08:34:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file h_err_exit.c
 * @brief Stores the definition of h_err_exit()
 */

#include "pipex.h"

/**
 * @brief Handles the passed error and exits
 */
void	h_err_exit(const t_err *err)
{
	// if ...
	//else
	//  Unexpected error occured
	print_exit_msg_and_exit(err);
}