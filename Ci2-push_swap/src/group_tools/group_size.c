/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:20:18 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 21:24:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file group_size.c
 * @brief Stores the definition of group_size()
 */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Counts the size of a group.
 * @param[in] ori_node any node of a group (or `NULL`)
 * @return The counted number of nodes of the group
 */
int	group_size(t_dl_node *ori_node)
{
	t_dl_node *node;
	int size;

	if (ori_node == NULL)
		return (0);
	node = ori_node;
	size = 1;
	while (((t_ps_obj*)node->obj)->group.starts == false)
	{
		node = node->prev;
		size++;
	}
	node = ori_node;
	while (((t_ps_obj*)node->obj)->group.ends == false)
	{
		node = node->next;
		size++;
	}
	return (size);
}

