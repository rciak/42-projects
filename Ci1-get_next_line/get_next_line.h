/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:45 by reciak            #+#    #+#             */
/*   Updated: 2025/06/28 13:15:48 by reciak           ###   ########.fr       */
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
	int			code;
	const char	*msg;
}	t_err;

/**
 * @warning The enumaration of the below error codes must be 0, 1, 2, ...
 *          since they are used as index for the constant array g_err !
 * @note In projects where the number of files / allowed number of functions
 *       is not limited this restriction can be removed by implementing
 *       a function  set_err() 
 *       with sample use @code err = seterr(NO_ERROR); @endcode
 */
enum e_gnl_error_codes
{
	NO_ERROR = 0
};

extern const t_err g_err[];

char	*get_next_line(int fd);

#endif
