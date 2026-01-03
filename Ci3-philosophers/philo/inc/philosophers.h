/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:48:14 by reciak            #+#    #+#             */
/*   Updated: 2026/01/03 19:35:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

///////////////////////////
//                       //
//  1.  I N C L U D E S  //
//                       //
///////////////////////////
# include <pthread.h>           // pthread_create, ...
# include <stdlib.h>
# include <unistd.h>

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

enum e_error
{
	E_NONE,
	E_ARGC,
};

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

typedef struct s_err
{
	enum e_error	err;
	char			*msg;
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
int	main(int argc, char **argv);

// error_handling/*.c
int	herr(enum e_error err_code, const char *debug_info);

//tools/*.c
ssize_t	putstr_fd(const char *str, int fd);

#endif