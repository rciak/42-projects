/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:48:14 by reciak            #+#    #+#             */
/*   Updated: 2026/02/07 17:24:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

///////////////////////////
//                       //
//  1.  I N C L U D E S  //
//                       //
///////////////////////////

# define _DEFAULT_SOURCE
# include <pthread.h>           // pthread_create, ...
# include <sys/time.h>          // gettimeofday
//# include <limits.h>                                                  // LLONG_MAX
# include <stdint.h>            // uint64_t
# include <stdlib.h>            // malloc, free
# include <unistd.h>            // STDERR_FILENO, ...
# include <stdbool.h>           // true, false, ...
# include <stdio.h>             // printf

/////////////////////////
//                     //
//  2.  D E F I N E S  //
//                     //
/////////////////////////

// Call make with DEBUG_PRINT=1 to see debug messages
# ifndef DEBUG_PRINT
#  define DEBUG_PRINT 0
# endif
// For transforming the time struct, returned by gettimeofday into microseconds
# define ONE_HOUR_IN_MS 3600000
# define ONE_SECOND_IN_US 1000000
// Colors
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
// Misc.
# define MAX_NUM_MEALS LLONG_MAX - 2
# define MAX_ENDED_MEALS LLONG_MAX - 1                                        //This is on purpose one bigger, cf. philo_fun!
# define FACTOR_USLEEP_WAIT_FOR 0.9                                           //This should be kicked out / not needed anymore when my custum sleep functions gets improved and tuned

// The unit for the following is usec (microseconds)
# define TIME_TILL_NEXT_FORK_CHECK 300
///////////////////////////////////////////////////////////////////////# define MAX_TIME_BIRTH_PHILO 1000/

///////////////////////////////////
//                               //
//  3.  E N U M E R A T I O N S  //
//                               //
///////////////////////////////////

enum e_events_to_log
{
	DIED,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK_EAT,
	SLEEP,
	THINK,
};

enum e_philosopers_int_constants
{
	END_SIMULATION = -1,
	OMITTED_PARAM = -1,
	MAX_NUM_PHILOS = 65535,
	MAX_TT_DIE = ONE_HOUR_IN_MS,
	MAX_TT_EAT = ONE_HOUR_IN_MS,
	MAX_TT_SLEEP = ONE_HOUR_IN_MS,
};

/**
 * @warning The error codes `E_ATOLL_...` have been tweaked for philosophers.
 *          This tweaks should never be used in other projects, cf.
 *          the warning  in libft.h  (which refers to atof_strict).
 * @note The special entry `E_COUNT_THEM_ALL` is not an error code, but
 *       is used to count the number of error codes; therefore it must stay
 *       as the last entry!
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
	E_ALLOC,
	E_MUTEX_INIT,
	E_THREAD_CREATE,
	E_THREAD_JOIN,
	E_COUNT_THEM_ALL,
}	t_ecode;

/////////////////////////
//                     //
//  4.  S T R U C T S  //
//                     //
/////////////////////////

typedef struct s_param
{
	long long	num_philos;
	long long	tt_die;
	long long	tt_eat;
	long long	tt_sleep;
	long long	meals_at_least;
}	t_param;

typedef struct s_time_to
{
	int64_t	die;
	int64_t	eat;
	int64_t	sleep;
}	t_time_to;

typedef struct s_meals
{
	int64_t	eaten;
	int64_t	min;
}	t_meals;

typedef struct s_int_philo
{
	pthread_t	thread;
	int64_t		id;
	t_time_to	tt;
	t_meals		meals;
	int64_t		t_0;
}	t_int_philo;

//
// to be shared amongst (all or some) threads
//
struct	s_squad_end;
struct	s_maestro;

typedef struct s_ext_philo
{
	struct s_maestro	*maestro;
	struct s_squad_end	*squad_end;
	pthread_mutex_t		*lock_philos_till_start;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_ext_philo;

typedef struct s_maestro
{
	pthread_mutex_t	mutex;
	bool			*allows;
}	t_maestro;
typedef struct s_squad_end
{
	pthread_mutex_t	mutex;
	bool			starved;
	int64_t			num_pasta_lovers;
}	t_squad_end;

typedef struct	philo
{
	t_int_philo		in;
	t_ext_philo		ex;
}	t_philo;

typedef struct s_err
{
	t_ecode	code;
	char	*msg;
}	t_err;

typedef struct s_interval
{
	int64_t	start;
	int64_t	end;
}	t_interval;

////////////////////////////////////////////////
//                                            //
//  5.  F U N C T I O N  P R O T O T Y P E S  //
//                                            //
////////////////////////////////////////////////

// *.c
int			main(int argc, char **argv);
bool		parse_args(int argc, char **argv, t_param *param, t_ecode *code);
bool		init_rest(t_all *all, t_ecode *code);
bool		create__philo_threads(t_all *all, t_ecode *code);
void		*philo_alone_at_table(void *arg);
void		*philo_fun(void *arg);
void		wait_for(long long time);

// philo_fun/*.c
long long	hope_for_meal(t_philo *phi, long long t_starved);
//          /zhared/*.c
bool		is_simulation_ended(t_philo *phi);


// error_handling/*.c
int			herr(t_ecode code, const char *debug_info);
int			herr_free(t_ecode code, const char *debug_info, t_all *all);

//tools_libft/*.c
size_t		skip(char **pstr, const char *chars_to_skip);
ssize_t		putstr_fd(const char *str, int fd);
bool		is_in(char c, const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
long long	atoll_strict(const char *nptr, t_ecode *err_code);

//tools_time/*.c
void		wait_for(long long time_span);
long long	gettimeofday_musec(void);

///////////////////////////
//                       //
//  X.  D E B U G I N G  //
//                       //
///////////////////////////
void	print_parsed_args(t_param param);
void	print_init_rest(t_all all);


#endif
