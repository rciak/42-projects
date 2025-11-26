/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/11/26 12:23:29 by reciak           ###   ########.fr       */
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

/**
 * @brief Specials values for calling exit_on(., *, . , .) or its internals.
 * @note \c ANY shall be used only internally but not when calling exit_on()
 */
enum e_saved_errno_specials
{
	ANY = -1,
	ERRNO_IRREL = -2,
};

enum e_special_negative_integer_states
{
	UNUSED = -1,
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
	//E_NEGATIVE_FD,
	E_CLOSE,
	//E_ENVP_NULL,
	//E_ENVP_EMPTY_ARRAY,
	//E_TOO_FEW_CMDS,
	E_CREATE_PIPE,
	E_OPEN_READ,
	E_OPEN_WRITE,
	E_ASSERTION,
	E_FORK,
	E_NOT_FOUND,
	E_EXECVE,
};

enum e_some_manually_defined_exit_codes
{
	MEX_GENERIC = 1,
	MEX_ASSERTION = 3,
	MEX_NO_PERM = 126,
	MEX_NOT_FOUND = 127,
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
 * @brief This pai models what is regarded as error in pipex.
 * @param type  One of the errorcode names in the above enum
 * @param saved_errno A copy of errno, or a special negative value.
 */
typedef struct s_err
{
	int			type;
	int			saved_errno;
}	t_err;

typedef struct s_exit_info
{
	char	*str1;
	char	*str2;
	int		code;
}	t_exit_info;

typedef struct s_err_to_exit
{
	t_err		err;
	t_exit_info	info;
}	t_err_to_exit;


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

// a_col_ending/*.c
void	exit_on(int type, int saved_errno, const char *origin, t_data *data);
void	do_final_nonsense_tidy_up(t_data *data);

// a_col_ending/do_final_nonsense_tidy_up/*.c
void	close_and_reset(int *fd);
void	free_and_reset(char **p_ptr);
void	free_array_and_reset(char ***p_arr);

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


#include "debug.h"
// debug/*.c
void	print_data(t_data *data, char* what);
void	print_cmds(t_data *data, char *intro, char *what);
void	print_cmd_i(t_data *data, int i, char *what);
void	print_arr(char **arr, char *prefix);



#endif
