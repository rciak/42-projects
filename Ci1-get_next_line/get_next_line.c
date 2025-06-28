/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/06/28 20:06:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Stores the definition of get_next_line() and st_gnl_proper()
 */

#include "get_next_line.h"

//Indentation would be better but norminette does not allow any...
const t_err	g_err[] = {
{E_GNL_NONE, "gnl: No error"},
{E_GNL_READ, "gnl: Read error"}
};

static char	*st_gnl_proper(int fd, t_err *err);
static char 

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
 * @note **Assumption:** @code fd < MAX_NUMB_FD @endcode
 * @param [in] fd A file descriptor
 * @return
 *     * a pointer to the extracted line from the file associated to 
 *     * (NULL) when write has finished reading from \p fd or on error.
 */
char	*get_next_line(int fd)
{
	t_err	err;

	err = g_err[E_GNL_NONE];
	return (st_gnl_proper(fd, &err));
}

static char	*st_gnl_proper(int fd, t_err *err)
{
	static char	*buf[MAX_NUMB_FD];
	ssize_t		bytes_read;

	if (fd < 0 || fd >= MAX_NUMB_FD)
		return (st_clear(&buf[fd], err, E_GNL_FD_RANGE), NULL);
	while (1)
	{
		if (st_has_newline(buf[fd]))
			return (st_extract_newline(buf[fd], err));
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (st_clear(&buf[fd], err, E_GNL_READ), NULL);
		if (bytes_read == 0)
			return (duplicate_n_clear(&buf[fd], err), NULL);
	}
	return (NULL);
}
