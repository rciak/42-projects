/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/06/28 15:23:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Stores the definition of get_next_line() and st_gnl_proper()
 */

#include "get_next_line.h"

const t_err	g_err[] = {
{NO_ERROR, "No error"}
};

static char	*st_gnl_proper(int fd, t_err *err);


/**
 * @brief This is the core function of the project.
 * @note  This function is just a wrapper for st_gnl_proper, which -
 *        in contrast to  get_next_line  - allows to distinguish if a returned
 *        (NULL) stands for an error or for having the file fully read.
 * @note On github there should be a version containing a `makefile` with rules
 *     * `make doc`
 *     * `make unit-tests`
 *     * `make DEV=1 unit-tests`
 *     * `make DEV=1 unit-tests > /dev/null`
 * @param [in] fd A file descriptor
 * @return
 *     * a pointer to the extracted line from the file associated to 
 *     * (NULL) when write has finished reading from \p fd or on error.
 */
char	*get_next_line(int fd)
{
	t_err	err;

	err = g_err[NO_ERROR];
	return (st_gnl_proper(fd, &err));
}

static char	*st_gnl_proper(int fd, t_err *err)
{
	(void) fd;
	(void) err;
	return (NULL);
}
