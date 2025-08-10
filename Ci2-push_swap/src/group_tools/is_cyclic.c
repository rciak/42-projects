/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cyclic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:10:19 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 18:57:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_cyclic.c
 * @brief Stores the definition of is_cyclic()
 */

#include "push_swap.h"

/**
 * @brief Determines if a group is cyclic or not, i.e. the
 *        rank sequence 1 2 3 4,  2 3 4 1, 3 4 1 2, 4 1 2 3 are all cyclic,
 *        whereas 4 3 2 1, 1 4 2 3 are not
 * @note A group of size `1` or `2` is always cyclic.
 * @param[in] node A pointer to the **first** node of a group
 * @return 
 *          * true, if the group is cyclic
 *          * false, if the group is not cyclic
 */
bool	is_cyclic(t_dl_node *first)
{
	int	size;
	int	very_first_val;
	int	i;
	int	a;
	int	b;

	size = group_size(first);
	if (size == 1 || size == 2)
		return (true);
	very_first_val = ((t_ps_obj *) first->obj)->group.rank;
	i = 0;
	while (i < size - 1)
	{
		a = ((t_ps_obj *) first->obj)->group.rank;
		b = ((t_ps_obj *) first->next->obj)->group.rank;
		if ((b - a + size) % size != 1)
			return (false);
		first = first->next;
		i++;
	}
	a = b;
	b = very_first_val;
	if ((b - a + size) % size != 1)
		return (false);
	return (true);
}
