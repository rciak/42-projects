/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/11/24 18:19:22 by reciak           ###   ########.fr       */
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
# include <sys/wait.h>      // waitpid
# include <fcntl.h>         // open
# include <errno.h>         // ENOENT, EACCES, ...
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

enum e_saved_errno_specials
{
	KEEP = -1,
	ERRNO_IRREL = -2,
};

enum e_special_negative_integer_states
{
	UNUSED = -10,
};

enum e_pipe_fd_kind
{
	READ_FROM = 0,
	WRITE_TO = 1,
};

enum e_pipex_errors
{
	E_NONE,
	E_ARGC,
	E_ALLOC,
	E_NEGATIVE_FD,
	E_CLOSE_FAILED,
	E_ENVP_NULL,
	E_ENVP_EMPTY_ARRAY,
	E_TOO_FEW_CMDS,
	E_CREATE_PIPE,
	E_OPEN_READ,
	E_OPEN_WRITE,
	E_ASSERTION,
	E_FORK,
	E_NOT_FOUND,
	E_EXECVE_FAILED,
};

//enum e_some_manually_defined_exit_codes
//{
//	MEX_PERM_DENIED = 126,
//	MEX_NOT_FOUND = 127,
//};

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
 * @param type  One of the errorcode names in the above enum
 * @param saved_errno
 * @param origin A pointer to a string literal: origin of the error
// * @param msg   A pointer to a string literal: error message
// * @param exit Exit code and (potential) exit message
// * @param cmd_index The command index that caused the issue. (Mostly not needed)
 */
typedef struct s_err
{
	int			type;
	int			saved_errno;
//	const char	*origin;
//const char	*msg;
//t_exit		exit;
//size_t		cmd_index;
}	t_err;

typedef struct s_cmd
{
	size_t	ac;
	char	**av;
	char	*pathname;
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	pid_t	pid;
}	t_cmd;

typedef struct s_data
{
	int		i_cmd_err;
	int		num_cmds;
	t_cmd	*cmd;
	char	**path;
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
void	parse_argv(int argc, char **argv, t_data *data);
void	parse_path(char **envp, t_data *data);
int		exec_pipeline(t_data *data, char **envp);

// exec_pipeline_d/*.c
void	exec_cmd(t_data *data, int i, char **envp);
int		wait_without_creating_zombies(pid_t pid_last_cmd);
//void	set_err(t_err *err, int error_type, int cur_errno, const char *origin);
//bool	parse_argv(int argc, char **argv, t_data *data, t_err *err);
//bool	parse_path(char **envp, size_t num_cmds, t_cmd *cmd, t_err *err);
//bool	open_pipes(size_t num_cmds, t_cmd *cmd, t_err *err);
//bool	open_files(size_t num_cmds, t_cmd *cmd, t_err *err);
//bool	exec_pipeline(t_data *data, char **envp, t_err *err);

// a_col_exiting/*.c
//void	print_err(const t_err *err);
//void	print_exit_msg(const t_err *err);
//void	print_exit_msg_and_exit(const t_err *err);
//void	h_err_exit(size_t num_cmds, t_cmd *cmd, t_err *err);
//void	logic_error_exit(const char *msg);

// a_col_tools/*.c
//void	tidy_up_and_reset_cmd_items(t_cmd *cmd, t_err *err);
//int		close_and_reset(int *fd, t_err *err);
//void	free_and_reset(char **p_ptr);
//void	free_array_and_reset(char ***p_arr);

#endif
