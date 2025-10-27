/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 18:24:51 by reciak           ###   ########.fr       */
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
 * @brief Used when calling error().
 * @note error() can either be called in its second argument like
 *           error( , errno , )   or
 *           error( , KEEP , ).
 * @note Therefore KEEP needs to be a negative integer to avoid overlapping
 *       with errno values.
 */
enum e_prevent_overwriting
{
	KEEP = -1,
};

enum e_prevent_reusing
{
	DO_NOT_USE = -1,
};


enum e_pipe_fd_kind
{
	READ_FROM = 0,
	WRITE_TO = 1,
};

enum e_pipex_errors                                                     // Fill in at error.c
{
	E_NONE,
	E_ARGC,
	E_ALLOC,
	E_NEGATIVE_FD,
	E_CLOSE_FAILED,
	E_ENVP_NULL,
	E_ENVP_EMPTY_ARRAY,
	E_TOO_FEW_CMDS,
};

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

/**
 * @brief For convenient mapping of error type to error message, cf. set_err()
 */
typedef struct s_err_type_to_msg
{
	int		type;
	char	*msg;
}	t_err_type_to_msg;


/**
 * @brief This serves as substructure for t_err
 */
typedef struct s_exit
{
	const char	*msg;
	int			code;
}	t_exit;

/**
 * @brief This structure serves for error handling
 * @param code  One of the errorcode names in the above enum
 * @param msg   A pointer to a string literal: error message
 * @param origin A pointer to a string literal: origin of the error
 */
typedef struct s_err
{
	int			type;
	int			saved_errno;
	const char	*msg;
	const char	*origin;
	t_exit		exit;
}	t_err;


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
//
//  see src and subfolders for implementation
//

// *.c
void	set_err(t_err *err, int error_type, int cur_errno, const char *origin);
bool	parse_argv(int argc, char **argv, t_data *data, t_err *err);
bool	parse_path(char **envp, size_t num_cmds, t_cmd *cmd, t_err *err);

// a_col_exiting/*.c
void	print_err(const t_err *err);
void	print_exit_msg(const t_err *err);
void	print_exit_msg_and_exit(const t_err *err);
void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err);
void	logic_error_exit(const char *msg);

// a_col_tools/*.c
void	tidy_up_and_reset_cmd_items(t_cmd *cmd, t_err *err);
int		close_and_reset(int *fd, t_err *err);
void	free_and_reset(char **p_ptr);
void	free_array_and_reset(char ***p_arr);

#endif