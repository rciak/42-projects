/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_memb_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:12:34 by reciak            #+#    #+#             */
/*   Updated: 2025/08/09 18:04:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file group_memb_last.c
 * @brief Stores the definition of group_memb_last
 */

#include "push_swap.h"

/**
 * @brief Finds the last node that still belongs to the given group.
 * @param[in] node_of_group A pointer to any group node (not `NULL` !)
 * @return A  pointer to the last node of the group
 */
t_dl_node	*group_memb_last(t_dl_node *node_of_group)
{
	while (((t_ps_obj *)node_of_group->obj)->group.ends == false)
		node_of_group = node_of_group->next;
	return (node_of_group);
}
