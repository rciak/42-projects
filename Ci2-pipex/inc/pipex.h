/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 19:10:54 by reciak           ###   ########.fr       */
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

typedef struct s_cmd
{
	char	*infile;
	char	*outfile;
	int		*left_pipe;
	int		*right_pipe;
	char	**av;
	size_t	ac;
}	t_cmd;

typedef struct s_data
{
	size_t	num_cmds;
	t_cmd	*cmd;
}	t_data;

////////////////////////////////////////////////
//                                            //
//  5.  F U N C T I O N  P R O T O T Y P E S  //
//                                            //
////////////////////////////////////////////////

// *.c
int		main(int argc, char **argv, char **envp);
t_err	error(int error_code);
void	exec_pipeline(t_cmd *cmd, size_t num_cmds, char** envp, t_x_err *x_err);

// error_management/*.c
t_x_err	x_error(int error_code, int cur_errno, const char *origin);

// init/*.c
bool	parse(int argc, char** argv, t_data *data, t_x_err *x_err);
void	no_left_and_right_pipes(t_cmd *cmd, size_t num_commands);

// memory/*.c
void	final_free(t_data data);

#endif
