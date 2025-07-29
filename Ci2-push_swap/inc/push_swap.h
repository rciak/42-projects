/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:15:09 by reciak            #+#    #+#             */
/*   Updated: 2025/07/28 18:36:11 by reciak           ###   ########.fr       */
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
	MAX_SIZE_DIRECT_SORT = 5
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

/**
 * @note \p rank describes how high or low a node is ranked in its current 
 *               group, e.g. rank == 1 means that the node is ranked smallest
 *               within the group (i.e. all other nodes of the same group
 *               have a higher value for obj->n),
 *               whereas rank == size  means that the node is ranked highest.
 */
typedef struct s_group
{
	int		size;
	int		rank;
	bool	starts;
	bool	ends;
}	t_group;
typedef struct s_push_swap_obj
{
	int		n;
	bool	is_green;
	t_group	group;
}	t_ps_obj;

////////////////////////////////////////////////////////////////////////////////
// src/*.c
////////////////////////////////////////////////////////////////////////////////

int		main(int argc, char **argv);
t_err	error(enum e_push_swap_errors error_code);
void	handle_error(t_err err);

////////////////////////////////////////////////////////////////////////////////
// src/group_tools/*.c
////////////////////////////////////////////////////////////////////////////////
void	update_group(t_dl_node *stack_a);
int		group_size(t_dl_node *ori_node);
bool	group_already_sorted(t_dl_node *node);

#endif
