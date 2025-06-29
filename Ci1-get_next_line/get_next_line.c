/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/06/29 17:54:02 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Stores the definition of get_next_line() and st_gnl_proper()
 */

#include "get_next_line.h"

//Indentation would be better but norminette does not allow any...
const t_event	g_event[] = {
{EVTGNL_NONE, "gnl: No error"},
{ERRGNL_READ, "gnl: Read error"},
{},
{},
{}
};

static char	*st_gnl_proper(int fd, t_event *err);
static 

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
	t_event	err;

	err = g_err[EVTGNL_NONE];
	return (st_gnl_proper(fd, &err));
}

/**
 * @note When making this function non static, in future projects:
 *       put the following from  get_next_line  here
 *           t_err	err;
 *           err = g_err[EVTGNL_NONE];
 */
static char	*st_gnl_proper(int fd, t_event *err)
{
	char		*read_in;
	ssize_t		bytes_read;
	static char	*buf[MAX_NUMB_FD];
	
	if (fd < 0 || fd >= MAX_NUMB_FD)
		return (st_act_on(ERRGNL_FD_RANGE, &buf[fd], err));
	while (1)
	{
		if (st_has_newline(buf[fd]))   //maybe strchr?
			return (st_detach_line(&buf[fd], err));
		read_in = malloc(BUFFER_SIZE);
		if (read_in == NULL)
			return (st_act_on(ERRGNL_MALLOC, &read_in, &buf[fd], err));
		bytes_read = read(fd, read_in, BUFFER_SIZE);
		if (bytes_read < 0)
			return (st_act_on(ERRGNL_READ, &read_in, &buf[fd], err));
		if (bytes_read == 0)
			return (st_act_on(EVTGNL_EOF, &read_in, &buf[fd], err));
		            //duplicate_n_clear
	}
	return (NULL);
}


st_detach_line(buf, err)
{
	// Set err to NOERR
}