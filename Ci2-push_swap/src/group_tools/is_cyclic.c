/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cyclic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:10:19 by reciak            #+#    #+#             */
/*   Updated: 2025/08/04 19:37:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_cyclic.c
 * @brief Stores the definition of is_cyclic()
 */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Determines if a group is cyclic or not, i.e. the
 *        rank sequence 1 2 3 4,  2 3 4 1, 3 4 1 2, 4 1 2 3 are all cyclic,
 *        whereas 4 3 2 1, 1 4 2 3 are not
 * @note A group of size `1` or `2` is always cyclic.
 * @param[in] node A pointer to any group node
 * @return 
 *          * true, if the group is cyclic
 *          * false, if the group is not cyclic
 */
bool	is_cyclic(t_dl_node *node)
{
	int	size;
	int	i;
	int a;
	int b;

	size = group_size(node);
	if (size == 1 || size == 2)
		return (true);
	i = 0;
	while (i < size)
	{
		a = ((t_ps_obj *) node->obj)->group.rank;
		b = ((t_ps_obj *) node->next->obj)->group.rank;
		if ((b - a) % size != 1 && ((b - a) % size ) + size != 1)
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}