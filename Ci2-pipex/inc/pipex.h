/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/16 18:50:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pipex.h
 * @brief The header file for reciak's pipex project of the Common Core
 */

#ifndef PIPEX_H
# define PIPEX_H

///////////////////////////
//                       //
//  1.  I N C L U D E S  //
//                       //
///////////////////////////
# include <stdint.h>
# include <errno.h>
# include "libft.h"

/////////////////////////
//                     //
//  2.  D E F I N E S  //
//                     //
/////////////////////////

///////////////////////////////////
//                               //
//  3.  E N U M E R A T I O N S  //
//                               //
///////////////////////////////////

/**
 * @brief Used when calling x_error().
 * @note x_error() can either be called in its second argument like
 *           x_error( , errno , )   or
 *           x_error( , KEEP , ).
 * @note Therefore KEEP needs to be a negative integer to avoid overlapping
 *       with errno values.
 */
enum e_prevent_overwriting
{
	KEEP = -1,
};

enum e_indexing_std__fds_exec_unit
{
	IN,
	OUT,
};

enum e_pipex_errors                                                     // Fill in at error.c
{
	ERR_NONE,
	ERR_ARGC,
	ERR_ALLOC,
};

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

/**
 * @brief This structure serves for error handling
 * @param code  One of the errorcode names in the above enum
 * @param msg   A pointer to a string literal defined in error()
 */
typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

/**
 * @brief This extends s_err adding a storage option for current errno 
 *        and a note (like which function caused the error).
 */
typedef struct s_x_err
{
	int			code;
	int			saved_errno;
	const char	*msg;
	const char	*origin;
}	t_x_err;

typedef struct s_parse_unit
{
	char	*redir[2];
	char	**av;
	size_t	ac;
}	t_parse_unit;

typedef struct s_data
{
	size_t		ac_cmd;
	t_parse_unit	*cmd;
}	t_data;

////////////////////////////////////////////////
//                                            //
//  5.  F U N C T I O N  P R O T O T Y P E S  //
//                                            //
////////////////////////////////////////////////

// *.c
int		main(int argc, char **argv, char **envp);
t_err	error(int error_code);
bool	parse(int argc, char** argv, t_data *data, t_x_err *x_err);

// error_management/*.c
t_x_err	x_error(int error_code, int cur_errno, const char *origin);


#endif
