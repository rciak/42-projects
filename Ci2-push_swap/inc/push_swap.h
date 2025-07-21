/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:15:09 by reciak            #+#    #+#             */
/*   Updated: 2025/07/21 18:06:03 by reciak           ###   ########.fr       */
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
};

// enum e_misc
// {
// 	MLX_WILL_ANYWAY_TROUGH_AWAY_THE_RETURN_VAL = 314
// };

typedef struct s_err
{
	int			code;
	const char	*msg;
}	t_err;

/**
 * @note This is a **d**oubly **l**inked node as basic building block for a
 *       doubly linked list
 */
typedef struct s_dl_node
{
	void				*obj;
	struct s_bl_node	*prev;
	struct t_bl_node	*next;
}	t_bl_node;

#endif
