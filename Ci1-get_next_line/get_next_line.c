/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:58 by reciak            #+#    #+#             */
/*   Updated: 2025/06/28 13:47:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const t_err	g_err[] = {
{NO_ERROR, "No error"}
};

static char	*st_gnl_proper(int fd, t_err *err);

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
