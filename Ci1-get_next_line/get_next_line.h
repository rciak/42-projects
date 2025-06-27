/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:45 by reciak            #+#    #+#             */
/*   Updated: 2025/06/27 18:37:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_prinf.h
 * @brief The header file for reciak's get_next_line project of the Common Core
 */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>    //malloc, free
# include <unistd.h>    //read

typedef struct s_err
{
	int		code;
	char	*msg;
}	t_err;

enum e_gnl_error_codes
{
	NO_ERROR = 0
}

const t_err g_err[] =
{
	{NO_ERROR, "No error"}
};

char	*get_next_line(int fd);

#endif