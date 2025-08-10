/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_already_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:45:49 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 18:57:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file group_already_sorted.c 
 * @brief Stores the definition of group_already_sorted()
 */

#include "push_swap.h"

/**
 * @brief Checks if a group of nodes insides a doubly linked list is already
 *        sorted.
 * @note This function is used by main to check if there is need to sort at all.
 * @param[in] node Any node of a group
 * @return 
 *          * `true` if the group is already sorted
 *          * `false` else
 */
bool	group_already_sorted(t_dl_node *node)
{
	int	size;

	while (((t_ps_obj *)node->obj)->group.starts == false)
		node = node->prev;
	size = group_size(node);
	while (1 < size)
	{
		if (((t_ps_obj *)node->obj)->n >= ((t_ps_obj *)node->next->obj)->n)
			return (false);
		node = node->next;
		size--;
	}
	return (true);
}
