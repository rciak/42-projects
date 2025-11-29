/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/11/29 17:06:57 by reciak           ###   ########.fr       */
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

# define GENERAL_ERROR_MSG "An error happened (not in the specification list)\n"

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
	E_ASSERTION,
	E_ALLOC,
	E_CLOSE,
	E_CREATE_PIPE,
	E_DUP_TWO,
	E_EXECVE,
	E_FORK,
	E_NO_PERM,
	E_NO_PERM_VIA_PATH,
	E_NOT_FOUND,
	E_OPEN_RD,
	E_OPEN_WR,
};

enum e_some_manually_defined_exit_codes
{
	MEX_GENERIC = 1,
	MEX_ASSERTION = 3,
	MEX_NO_PERM = 126,
	MEX_NOT_FOUND = 127,
};

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
	char	*pathname_first_match;
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

// exec_pipeline/*.c
void	close_fd_in_fd_out(t_data *data, int i);
int		wait_without_creating_zombies(pid_t pid_last_cmd);

// exec_pipeline/exec__cmd/*.c
void	set_pathname_as_av0(t_data *data, int i);
void	set_pathname_as_cur_dir_av0(t_data *data, int i);
void	set_pathname_via_path(t_data *data, int i);

// a_col_ending/*.c
void	exit_on(int type, int saved_errno, const char *origin, t_data *data);
void	print_msg(t_exit_info info, const char *origin, t_data *data);
void	do_final_nonsense_tidy_up(t_data *data);

// a_col_ending/do_final_nonsense_tidy_up/*.c
void	close_and_reset(int *fd);
void	free_and_reset(char **p_ptr);
void	free_array_and_reset(char ***p_arr);

# include "debug.h"   /////////////////////////////////////REMOVE for submission!
// debug/*.c
void	print_data(t_data *data, char *what);
void	print_cmds(t_data *data, char *intro, char *what);
void	print_cmd_i(t_data *data, int i, char *what);
void	print_arr(char **arr, char *prefix);
///////////////////////////////////////////////////////////REMOVE for submission!

#endif
