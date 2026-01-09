/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:48:14 by reciak            #+#    #+#             */
/*   Updated: 2026/01/09 23:11:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

///////////////////////////
//                       //
//  1.  I N C L U D E S  //
//                       //
///////////////////////////
//
//														!!! REMOVE before submission !!!
# include "../src/debug/debug.h"
//
//
# include <pthread.h>           // pthread_create, ...
# include <limits.h>            // LLONG_MAX
# include <stdlib.h>            // malloc, free
# include <unistd.h>            // STDERR_FILENO, ...
# include <stdbool.h>           // true, false, ...

/////////////////////////
//                     //
//  2.  D E F I N E S  //
//                     //
/////////////////////////

// Call make with DEBUG_PRINT=1 to see debug messages
#ifndef DEBUG_PRINT
# define DEBUG_PRINT 0
#endif

# define ONE_HOUR_IN_MS 3600000
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"


///////////////////////////////////
//                               //
//  3.  E N U M E R A T I O N S  //
//                               //
///////////////////////////////////

enum e_philosopers_constants
{
	MAX_NUM_PHILOS = 65535,
	MAX_TT_DIE = ONE_HOUR_IN_MS,
	MAX_TT_EAT = ONE_HOUR_IN_MS,
	MAX_TT_SLEEP = ONE_HOUR_IN_MS,
	MAX_NUM_MEALS = LLONG_MAX - 1,
};

/**
 * @warning The error codes `E_ATOLL_...` have been tweaked for philosophers.
 *          This tweaks should never be used in other projects, cf.
 *          the warning  in libft.h  (which refers to atof_strict).
 */
typedef enum e_error_code
{
	E_NONE,
	E_ARGC,
	E_MAX_NUM_MEALS_NEG,
	E_NUM_PHILOS_NOT_POS,
	E_TIME_TO_DIE_NOT_POS,
	E_TIME_TO_EAT_NOT_POS,
	E_TIME_TO_SLEEP_NEG,
	E_DISRESPECT,
	E_ATOLL_NO_ERR,
	E_ATOLL_BAD_STRING,
	E_ATOLL_RANGE,
	E_COUNT_THEM_ALL,
}	t_ecode;

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

typedef struct s_err
{
	t_ecode	code;
	char	*msg;
}	t_err;

typedef struct s_param
{
	long long	num_philos;
	long long	tt_die;
	long long	tt_eat;
	long long	tt_sleep;
	long long	max_num_meals;
}	t_param;
typedef struct s_all
{
	t_param	param;
}	t_all;

////////////////////////////////////////////////
//                                            //
//  5.  F U N C T I O N  P R O T O T Y P E S  //
//                                            //
////////////////////////////////////////////////

// *.c
int			main(int argc, char **argv);

// error_handling/*.c
int			herr(t_ecode err_code, const char *debug_info);

//tools/*.c
size_t		skip(char **pstr, const char *chars_to_skip);
ssize_t		putstr_fd(const char *str, int fd);
bool		is_in(char c, const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
long long	atoll_strict(const char *nptr, t_ecode *err_code);


void	print_parsed_args(t_param params);

#endif
