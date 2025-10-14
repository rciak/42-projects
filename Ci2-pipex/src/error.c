/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:39:35 by reciak            #+#    #+#             */
/*   Updated: 2025/10/14 15:29:32 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * @brief Stores the definition of error()
 */

#include "pipex.h"

/**
 * @brief Complements an error code, defined in pipex.h by an error message.
 * @note This allows to have return statements like e.g. the following
 *       @code
return (*err = error(ERR_OVERFLOW), false);
 *       @endcode
 *       cf. is_three()
 * @param[in] error_code An error code as defined in pipex.h
 * @return 
 *          * an instance of the t_err struct, containing both the error code
 *            and an additional error message.
 */
t_err	error(int error_code)
{
	static const t_err	err[] = {
	{ERR_NONE, "pipex: Success - no error detected"},
	{ERR_ALLOC, "If one day memory is allocated change this message ;-)"},
	};

	return (err[error_code]);
}
