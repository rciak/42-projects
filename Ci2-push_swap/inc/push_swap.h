/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:15:09 by reciak            #+#    #+#             */
/*   Updated: 2025/07/31 10:34:35 by reciak           ###   ########.fr       */
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

/**
 * @note @c SMALLER_THAN_ANY_GOAL would no longer rightly bear its name
 *       in the theoretical case that push swap is given at least
 *       @c -INT_MIN numbers as arguments. The implementation would
 *       theoretically indeed fail anyway for such an amout of parameters;
 *       so that there is no use to consider an alternative approaches via
 *       @code # define	SMALLER_THAN_ANY_GOAL ((long long)INT_MIN - 1) @endcode
 *       and corresponding addoptions in e.g. max_non_green_group().
 * @note Note also that setting @c SMALLER_THAN_ANY_GOAL to @c 0 would be
 *       fine when working on `stack a` but not when working on `stack_b` since
 *       there the goal numbers are negative due the multiplication with -1
 *       when pushing a number / node to the other stack.
 */
enum e_miscellaneous
{
	MAX_SIZE_DIRECT_SORT = 5,
	SMALLER_THAN_ANY_GOAL = INT_MIN
};

/**
 * @warning The enumaration of the below names **must** be 0, 1, 2, ...
 *          since they are **used as index** for arrays,
 *          defined in set__markers_subgroups(), cf. big_size_algo() !
 */
enum e_subgroup
{
	LEAVER_1 = 0,
	LEAVER_2 = 1,
	STAYER = 2
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
	ERR_MALLOC = 4,
	ERR_LOGIC = 5
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
	int		goal;
	bool	is_green;
	t_group	group;
}	t_ps_obj;

////////////////////////////////////////////////////////////////////////////////
// src/*.c
////////////////////////////////////////////////////////////////////////////////
int		main(int argc, char **argv);
void	big_size_algo(t_dl_node **stack);
t_err	error(enum e_push_swap_errors error_code);
void	handle_error(t_err err, char *by_caller);

////////////////////////////////////////////////////////////////////////////////
// src/group_tools/*.c
////////////////////////////////////////////////////////////////////////////////

bool		group_already_sorted(t_dl_node *node);
t_dl_node	*group_memb_last(t_dl_node *node_of_group);
int			group_size(t_dl_node *ori_node);
t_dl_node	*max_non_green_group(t_dl_node *stack_a);
void		update_group(t_dl_node *stack_a);

////////////////////////////////////////////////////////////////////////////////
// src/trivide/*.c
////////////////////////////////////////////////////////////////////////////////
void	trivide_top_group(t_dl_node* node, t_dl_node **stack);
void	trivide_end_group(t_dl_node* node, t_dl_node **stack);

#endif
