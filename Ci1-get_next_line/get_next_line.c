/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/07/02 12:29:10 by reciak           ###   ########.fr       */
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
{ERRGNL_FD_RANGE, "gnl: File descriptor out of range"},
{ERRGNL_MALLOC, "gnl: Malloc failed"},
{EVTGNL_EOF, "gnl: End of file reached"}
};

static char	*st_gnl_proper(int fd, t_event *err);
static bool st_has_newline(char *buffer, size_t *i_nl);
static char	*st_detach_line(char *buffer, size_t i_nl, t_event *evt);


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
	t_event	evt;

	evt = g_event[EVTGNL_NONE];
	return (st_gnl_proper(fd, &evt));
}

/**
 * @note When making this function non static, in future projects:
 *       put the following from  get_next_line  here
 *           t_err	err;
 *           err = g_event[EVTGNL_NONE];
 */
static char	*st_gnl_proper(int fd, t_event *evt)
{
	char		*read_in;
	ssize_t		bytes_read;
	static char	*buf[MAX_NUMB_FD];
	size_t		i_nl;
	
	if (fd < 0 || fd >= MAX_NUMB_FD)
		return (st_act_on(ERRGNL_FD_RANGE, &buf[fd], evt));
	while (1)
	{
		if (st_has_newline(buf[fd]), &i_nl)
			return (st_detach_line(&buf[fd], i_nl, evt));
		read_in = malloc(BUFFER_SIZE);
		if (read_in == NULL)
			return (st_act_on(ERRGNL_MALLOC, &read_in, &buf[fd], evt));
		bytes_read = read(fd, read_in, BUFFER_SIZE);
		if (bytes_read < 0)
			return (st_act_on(ERRGNL_READ, &read_in, &buf[fd], evt));
		if (bytes_read == 0)
			return (st_act_on(EVTGNL_EOF, &read_in, &buf[fd], evt));
		            //duplicate_n_clear
	}
	return (NULL);
}

static bool st_has_newline(char *buffer, size_t *i_nl)
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


static char	*st_detach_line(char **buffer, size_t i_nl, t_event *evt)
{
	size_t	i;
	size_t	len_buffer;
	char 	*line;
	char 	*left_over;

	// if (i_nl >= SIZE_MAX - 2)
	// 	//react
	// if (*buffer == NULL)
	// 	//react
	len_buffer = ft_strlen(*buffer);
	line = malloc(i_nl + 1 + 1);
	left_over = malloc(len_buffer - i_nl);
	// if (line == NULL || left_over == NULL)
	// 		//react
	i = 0;
	while (i <= i_nl)
	{
		line[i] = (*buffer)[i];
		i++;
	}
	line[i] = '\0';
	while (i < len_buffer)
	{
		left_over[i - i_nl - 1] = (*buffer)[i];
		i++;
	}
	left_over[len_buffer - i_nl - 1] = '\0';
	*evt = g_event[EVTGNL_NONE];
	free(*buffer);
	*buffer = left_over;
}
