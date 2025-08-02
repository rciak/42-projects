/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:14:01 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 21:52:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
 * @brief Core swap (without printing) used by `sa`, `sb` and `ss`
 */

#include "push_swap.h"

/**
 * @brief Swaps the first and second elements of the chosen stack - provided it
 *        contains at least two elements.
 * @param[in]      chosen Either the integer constant `A` or `B`, specifiying
 *                        the stack to operate on.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 * @return
 *          * true, if the chosen stack had at least two elements
 *          * false, if there were none or only one element,
 *            i.e. too few elements for swapping.
 */
bool	swap(t_dl_node **stack, int chosen)
{
	size_t		size;
	t_dl_node	*node[4];
	
	size = dl_lst_size(stack[chosen]);
	if (size <= 1)
		return (false);
	// When everything is working: Try to delete this redundantent seeming else if block
	// and add a doxygen note about the size 2 case, (going in a circe - but no problem)
	else if (size == 2)
	{
		stack[chosen] = stack[chosen]->next;
		return (true);
	}
	node[0] = stack[chosen]->prev;
	node[2] = stack[chosen];
	node[1] = stack[chosen]->next;
	node[3] = stack[chosen]->next->next;
	node[0]->next = node[1];
	node[1]->prev = node[0];
	node[1]->next = node[2];
	node[2]->prev = node[1];
	node[2]->next = node[3];
	node[3]->prev = node[2];
	stack[chosen] = node[1];
	return (true);
}