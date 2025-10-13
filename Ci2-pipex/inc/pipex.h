/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:23:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/13 12:46:17 by reciak           ###   ########.fr       */
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

enum e_pipex_errors
{
	ERR_NONE,
	ERR_ALLOC,
	ERR_FILE_NOT_FOUND,
	ERR_NO_READ_PERM,
	ERR_NO_WRITE_PERM,
};

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

typedef struct s_all
{
	t_err		err;
}	t_all;

////////////////////////////////////////////////
//                                            //
//  5.  F U N C T I O N  P R O T O T Y P E S  //
//                                            //
////////////////////////////////////////////////

// *.c
int				main(int argc, char **argv, char **envp);
t_err			error(int error_code);

#endif
