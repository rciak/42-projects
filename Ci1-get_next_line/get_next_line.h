/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:54:45 by reciak            #+#    #+#             */
/*   Updated: 2025/07/03 07:44:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.h
 * @brief The header file for reciak's get_next_line project of the Common Core
 */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>      // malloc, free
# include <unistd.h>      // read
# include <stdbool.h>     // bool, true, false
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20000
# endif
# define MAX_NUMB_FD 1024 // Cur. softlim. at 42 Vienna; hardlim. 1048576 = 2^20

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_event;

/**
 * @warning The enumaration of the below event codes must be 0, 1, 2, ...
 *          since they are used as index for the constant array g_event !
 * @note In projects where the number of files / allowed number of functions
 *       is not limited this restriction can be removed by implementing
 *       a function  set_event() 
 *       with sample use @code err = seterr(O_GNL_EOF); @endcode
 */
enum e_gnl_event_codes
{
	EVTGNL_NONE = 0,


	
	ERRGNL_READ = 1,
	ERRGNL_FD_RANGE = 2,
	ERRGNL_MALLOC = 3,
	EVTGNL_EOF = 4,
	EVTGNL_READ_NEW = 5
};



extern const t_event g_event[];

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
