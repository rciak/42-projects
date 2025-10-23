/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/23 09:01:15 by reciak           ###   ########.fr       */
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
# include <sysexits.h>      // suggestions for exit codes (for system programms)
# include <sys/wait.h>
# include <fcntl.h>         // open
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

enum e_pipe_fd_kind
{
	READ_FROM = 0,
	WRITE_TO = 1,
};

enum e_pipex_errors                                                     // Fill in at error.c
{
	ERR_NONE,
	ERR_EXECV,
	ERR_ALLOC,
	ERR_ARGC,
	ERR_FORK,
	ERR_PIPE,
	ERR_DUP,
	ERR_ENVP,
	ERR_TOO_FEW_CMDS,
	ERR_OPEN,
	ERR_CLOSE,
	ERR_LOGIC,
	ERR_LOGIC_ELSE,
};

enum e_exit_codes
{
	EXITCODE_ERR_NONE = 0,
	EXITCODE_ERR_EXECV = 1,
	EXITCODE_MISC_ERROR = 2,
	EXITCODE_ERR_ALLOC = 2,
	EXITCODE_ERR_ARGC = EX_USAGE,
	EXITCODE_OPEN = EX_IOERR,
	EXITOCDE_ERR_CLOSE = EX_IOERR,
	EXITCODE_ERR_DUP = EX_OSERR,
	EXITCODE_ERR_FORK = EX_OSERR,
	EXITCODE_ERR_PIPE = EX_OSERR,
	EXITCODE_NOT_EXECUTABLE = 126,
	EXITCODE_NOT_FOUND = 127,
	EXITCODE_SIGINT = 130,
	EXITCODE_ERR_LOGIC = 3,
	EXITCODE_ERR_LOGIC_ELSE = 4,
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

typedef struct s_exit_pair
{
	int			code;
	const char	*msg;
}	t_exit_pair;

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
	size_t	ac;
	char	**av;
	char	**path;
	char	*infile;
	char	*outfile;
	int		fd_in;                                                  // remove if possible
	int		fd_out;                                                 // remove if possible
	pid_t	pid;
	                                                                // int		status;
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
bool	exec_pipeline(t_cmd	*cmd, size_t n_cmds, t_x_err *x_err);

// error_management/*.c
t_x_err	x_error(int error_code, int cur_errno, const char *origin);
int		handle_error(t_x_err x_err);

// init/*.c
bool	parse(int argc, char** argv, t_data *data, t_x_err *x_err);
bool	parse_path(char **envp, size_t num_cmds, t_cmd *cmd, t_x_err *x_err);

// memory/*.c
void	final_free(t_data data);

#endif
