/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:29:39 by reciak            #+#    #+#             */
/*   Updated: 2025/10/21 10:58:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exit_msg.c
 * @brief Stores the definition of exit_msg()
 */

#include "pipex.h"

/**
 * @brief Provides the message corresponding to an exit code
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
char *	exit_msg(int exit_code)
{
	char	*str;

	if (exit_code == EXITCODE_ERR_NONE)
		str = "";
	else if (exit_code == EXITCODE_ERR_EXECV)
		str = "";
	else if (exit_code == EXITCODE_MISC_ERROR)
		str = "An error happened";
	else if (exit_code == EXITCODE_ERR_FORK)
		str = "fork() failed";
	else if (exit_code == EXITCODE_NOT_EXECUTABLE)
		str = "Found but not executable";
	else if (exit_code == EXITCODE_NOT_FOUND)
		str = "File or directory not found";
	else if (exit_code == EXITCODE_SIGINT)
		str = "Received Signal SIGINT"
		" - I told you so many times not to press CRTL + C ...";
	else
		exit (ERR_LOGIC_ELSE);
	return (str);
}
