/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:24:41 by reciak            #+#    #+#             */
/*   Updated: 2025/10/14 19:23:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file x_error.c
 * @brief Stores the definition of error()
 */

#include "pipex.h"


/**
 * @brief Complements an error code, defined in pipex.h by an error message,
 *        cf. error(), with the possibility to store the current errno value
 *        and a string literal (which should help in debugging)
 * @note This allows to have return statements like e.g. the following
 *       @code
return (*x_err = x_error(ERR_MALLOC, errno, "in main:"), false);
 *       @endcode
 *       or if no update of the copy of errno is wished
 *       @code
return (*x_err = x_error(ERR_MALLOC, KEEP, "in main:"), false);
 *       @endcode
 *       Important therein is the def. KEEP = -1  < 0	
 * @param[in] error_code An error code as defined in pipex.h
 * @param[in] update
 * @return 
 *          * an instance of the t_x_err struct.
 */
t_x_err	x_error(int error_code, int cur_errno, const char *origin)
{
	t_x_err	x_err;

	x_err.err = error(error_code);
	if (cur_errno >= 0)
		x_err.saved_errno = cur_errno;
	x_err.origin = origin;
	return (x_err);
}
