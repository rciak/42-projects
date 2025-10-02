/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:09:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Stores the definition of get_next_line() and gnl_proper()
 */

#include "get_next_line.h"

static bool	st_has_newline(char *buffer, size_t *i_nl);
static char	*st_detach_line(char **buffer, size_t i_nl, t_event *evt);
static char	*st_act_on(int evt_no, char **read_in, char **buffer, t_event *evt);

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
 * @warning To avoid memory leaks make sure that all files 
 *          have been read so often that EOF was detected by read/get_next_line!
 * @param [in] fd A file descriptor
 * @return
 *     * a pointer to the extracted line from the file associated to 
 *     * (NULL) when write has finished reading from \p fd or on error.
 */
char	*get_next_line(int fd)
{
	t_event	evt;

	return (gnl_proper(fd, &evt));
}

char	*gnl_proper(int fd, t_event *evt)
{
	char		*parcel;
	ssize_t		bytes_read;
	static char	*buf[MAX_NUMB_FD];
	size_t		i_nl;

	if (fd < 0 || fd >= MAX_NUMB_FD)
		return (*evt = gnl_evt(GNL_FDRANGE_ERR), NULL);
	while (1)
	{
		if (st_has_newline(buf[fd], &i_nl))
			return (st_detach_line(&buf[fd], i_nl, evt));
		parcel = malloc(BUFFER_SIZE + 1);
		if (parcel == NULL)
			return (st_act_on(GNL_PARCEL_ALLOC_ERR, &parcel, &buf[fd], evt));
		bytes_read = read(fd, parcel, BUFFER_SIZE);
		if (bytes_read < 0)
			return (st_act_on(GNL_READ_ERR, &parcel, &buf[fd], evt));
		parcel[bytes_read] = '\0';
		if (bytes_read == 0)
			return (st_act_on(GNL_EOF, &parcel, &buf[fd], evt));
		else
			(void) st_act_on(GNL_STH_READIN, &parcel, &buf[fd], evt);
	}
}

static bool	st_has_newline(char *buffer, size_t *i_nl)
{
	*i_nl = 0;
	if (buffer == NULL)
		return (false);
	while (buffer[*i_nl] != '\0')
	{
		if (buffer[*i_nl] == '\n')
			return (true);
		(*i_nl)++;
	}
	return (false);
}

/**
 * @note originally I thought about implementing a check like
        `if (i_nl >= SIZE_MAX - 2)` this will slow down the program.
        Given the huge size of SIZE_MAX (at least on 42 Vienna machines)
        it did restrain from doing it. (A line that long is totally
        unrealistic for now)
 */
static char	*st_detach_line(char **buf, size_t i_nl, t_event *evt)
{
	size_t	len_buf;
	char	*ln;
	char	*rem;

	len_buf = gnl_strlen(*buf);
	ln = malloc(i_nl + 1 + 1);
	if (ln == NULL)
		return (*evt = gnl_evt(GNL_LINE_ALLOC_ERR), free(*buf), NULL);
	rem = malloc(len_buf - i_nl);
	if (rem == NULL)
		return (*evt = gnl_evt(GNL_REM_ALLOC_ERR), free(ln), free(*buf), NULL);
	gnl_memcpy(ln, *buf, i_nl + 1);
	gnl_memcpy(rem, *buf + i_nl + 1, len_buf - i_nl - 1);
	ln[i_nl + 1] = '\0';
	rem[len_buf - i_nl - 1] = '\0';
	*evt = gnl_evt(GNL_DETACH_LINE);
	free(*buf);
	*buf = rem;
	return (ln);
}

/**
 * @brief Reaction to different happenings / "events" in the core function.
 * @note The events  GNL_FDRANGE_ERR  and  GNL_PARCEL_ALLOC_ERR
 *       do not appear in the if construct, but the last lines of that function
 *       are relevant for that cases.
 * @note Setting @code *read_in = NULL; @endcode after freeing should not at 
 *       all be neccessary. In the case of `evt_no` being different
 *       from `GNL_STH_READIN`, i.e. when st_gnl_proper will immediately
 *       return it is actually omitted, practically also staying within
 *       the required 25 lines limits per functions ...
 * @note It would be more nice to split this functions into two, but
 *       either norminette would complain about "too many functions"
 *       or the calls 
 *       @code *evt = gnl_evt(evt_no) @endcode
 *       had to be replaced again by the previous
 *       @code *evt = g_event[event_no] @endcode
 *       to get space for another helper function
 *       (which would feel though weird to put in get_next_line_utils.c)
 *       Although the latter would lead to a normconform (constant) global
 *       variable it tried to fully avoid it.
 */
static char	*st_act_on(int evt_no, char **read_in, char **buffer, t_event *evt)
{
	char	*result;

	*evt = gnl_evt(evt_no);
	result = NULL;
	if (evt_no == GNL_EOF && *buffer != NULL && **buffer != '\0')
		result = gnl_strdup(*buffer);
	else if (evt_no == GNL_STH_READIN && *buffer == NULL)
	{
		*buffer = *read_in;
		*read_in = NULL;
		return ((char *) 0xdeadbeef);
	}
	else if (evt_no == GNL_STH_READIN && *buffer != NULL)
	{
		result = gnl_strjoin(*buffer, *read_in);
		free (*read_in);
		free (*buffer);
		*read_in = NULL;
		*buffer = result;
		return ((char *) 0xcafe2def);
	}
	free (*read_in);
	free (*buffer);
	*buffer = NULL;
	return (result);
}
