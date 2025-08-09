/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:07:24 by reciak            #+#    #+#             */
/*   Updated: 2025/08/09 17:43:54 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file be_group.c
 * @brief Stores the definition of be_group()
 */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Marks a new group inside a doubly linked list and sets the group
 *        values for all of its nodes.
 * @param[in,out] first A pointer to the node which shall be marked as
 *                      start of the group.
 * @param[in]     size the size of the group.
 * @note The nodes that is the \p size - 1 th `next` node after \p first
 *       will be marked as end of the group. For e.g. `size == 2` this would
 *       be the node \p first->next
 */
void	be_group(t_dl_node *first, int size)
{
	t_dl_node	*node;

	node = first;
	while (size > 0)
	{
		((t_ps_obj *)node->obj)->group.starts = false;
		((t_ps_obj *)node->obj)->group.ends = false;
		if (size > 1)
			node = node->next;
		size --;
	}
	((t_ps_obj *)first->obj)->group.starts = true;
	((t_ps_obj *)node->obj)->group.ends = true;
	update_group(first);
}
