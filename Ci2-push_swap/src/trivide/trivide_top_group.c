/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivide_top_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:03:36 by reciak            #+#    #+#             */
/*   Updated: 2025/08/05 20:46:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file trivide_top_group.c
 * @brief Stores the definition of trivide_top_group()
 */

#include "push_swap.h"

/**
 * @brief Splits the prepared top group (be it either on stack a or b)
 *        into three subgroups: 
 *        * One subgroup stays on the same stack becoming the new bottom group.
 *        * The two other groups are put to the other stack becoming its
 *          new top and bottim groups.
 * @note This functions was designed for a top group of at least three elements.
 * @param[in] node A pointer to the first node of a top group
 * @param[in,out] stack Stack a and b
 */
void	trivide_top_group(t_dl_node* node, t_dl_node **stack)
{
	int	s;
	int	i;
	int	r;
	t_dl_node	*next_node;

	s = ((t_ps_obj*)node->obj)->group.size;
	i = 0;
	while (i < s)
	{
		next_node  = node->next;
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
		node = next_node;
		i++;
	}
}
