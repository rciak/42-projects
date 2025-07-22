/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:15:09 by reciak            #+#    #+#             */
/*   Updated: 2025/07/22 14:19:05 by reciak           ###   ########.fr       */
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
	ERR_MALLOC = 3
};

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

/**
 * @note This is a **d**oubly **l**inked node as basic building block for a
 *       doubly linked list or a doubly linked ring
 */
typedef struct s_dl_node
{
	void				*obj;
	struct s_bl_node	*prev;
	struct t_bl_node	*next;
}	t_dl_node;

//error.c
t_err	error(int error_code);

#endif
