/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_on_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:15:29 by reciak            #+#    #+#             */
/*   Updated: 2025/07/31 12:31:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_on_a.c
 * @brief Stores the definition of is_on_a()
 */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Decides if the given group is on stack a or not
 * @note This is based on the following "trick" that is also elsewhere usefull
 *       when pushing a node from a stack to the other stack its entry
 *       @c goal is multiplied by -1. Hence a node has a positive @c goal value,
 *       if it is on stack `a` and a negative value if it is on stack `b`.
 * @param[in] node The node whose location shall be determined.
 * @return 
 *          * `true`, if `node` belongs to stack `a`.
 *          * `false`. if `node` belongs to stack `b`.
 */
bool	is_on_a(t_dl_node *node)
{
	if (((t_ps_obj *)node->obj)->goal > 0)
		return (true);
	return (false);
}