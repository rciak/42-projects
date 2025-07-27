/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:15:09 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 12:41:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief The header file for reciak's push_swap project of the Common Core
 */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "libft.h"

enum e_miscellaneous
{
	MAX_SIZE_HANDSORT = 5
};

/**
 * @warning The enumaration of the below names **must** be 0, 1, 2, ...
 *          since they are **used as index** for stack, defined in main() !
 */
enum e_push_swap_stacks
{
	A = 0,
	B = 1
};

/**
 * @warning The enumaration of the below error codes **must** be 0, 1, 2, ...
 *          since they are **used as index** in error() !
 * @warning Also the value 0 must be named by `ERR_NONE`, since ERR_NONE
 *          is used to return from main in case of no error!
 */
enum e_push_swap_errors
{
	ERR_NONE = 0,
	ERR_ARG_NUM = 1,
	ERR_ARGV = 2,
	ERR_DUPLICATE = 3,
	ERR_MALLOC = 4
};

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

typedef struct s_group
{
	int		rank;
	int		size;
	bool	starts;
	bool	ends;
}	t_group;
typedef struct s_push_swap_obj
{
	int		n;
	int		rank;
	t_group	group;
}	t_ps_obj;

//error.c
t_err	error(enum e_push_swap_errors error_code);
void	handle_error(t_err err);

//main.c
int		main(int argc, char **argv);

#endif
