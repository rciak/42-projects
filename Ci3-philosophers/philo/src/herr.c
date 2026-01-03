/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:54:03 by reciak            #+#    #+#             */
/*   Updated: 2026/01/03 19:45:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file herr.c
 * @brief Stores the definition of herr()
 */


#include "philosophers.h"

/**
 * @brief Prints an error message and returns an error code
 * @param[in] err_code, an error code defined in philosophers.h
 * @param[in] debug_info, a debug message (might be NULL or "")
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
int	herr(enum e_error err_code, const char *debug_info)
{
	static t_err	err[] = {
	{E_NONE, "No error\n"},
	{E_ARGC, "Invalid number of arguments\n"},
	};

	putstr_fd(err[err_code].msg, STDERR_FILENO);
	if (debug_info != NULL && debug_info[0] != '\0')
		putstr_fd(debug_info, STDERR_FILENO);
	return (err_code);
}
