/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivide_end_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:03:48 by reciak            #+#    #+#             */
/*   Updated: 2025/07/31 09:38:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file trivide_end_group.c
 * @brief Stores the definition of trivide_end_group()
 */

#include "push_swap.h"

/**
 * @brief Splits the prepared bottom group (be it either on stack a or b)
 *        into three subgroups: 
 *        * One subgroup stays on the same stack becoming the new top group.
 *        * The two other groups are put to the other stack becoming its
 *          new top and bottom groups.
 * @note This functions was designed for a top group of at least three elements.
 * @param[in] node A pointer to the first node of a bottom group
 * @param[in,out] stack Stack a and b
 */
void	trivide_end_group(t_dl_node* node, t_dl_node **stack)
{
	int	s;
	int	i;
	int	r;

	s = ((t_ps_obj*)node->obj)->group.size;
	i = 0;
	while (i < s)
	{
		rr_it(node, stack);
		r = ((t_ps_obj*)node->obj)->group.rank;
		if (r <= s / 3)
			p_it(node, stack);
		else if (s / 3 < r && r <= s - (s + 2) / 3)
		{
			p_it(node, stack);
			r_it(node, stack);
		}
		else if (s - (s + 2) / 3 < r && r <= s)
			r_it(node, stack);
		node = node->next;
		i++;
	}
}
