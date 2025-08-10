/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_green_directsort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:39:07 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 19:14:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file join_green_directsort
 * @brief Stores the definition of join_green_directsort()
 */

#include "push_swap.h"

static void	mark__group_as_green(t_dl_node *soon_green);
static void	set__ranks_as_if_on_stack_a(t_dl_node *group_of_size_3);

/**
 * @brief Sort the prepared group (of `size <= MAX_SIZE_DIRECT_SORT`),
 *        put the sorted group in front of the "green" area on stack `a` and
 *        add it by marking it as green.
 * @note By construction of the algorithm this function will be handed
 *       over a group that is the top group or bottom group of stack A or B and 
 *       thus close to the green area; more precise:
 * @note The position of the "soon_green" group `S` and the 
 *       already green area `G` is one of the following 
 *       (Bottom leftmost, Top rightmost; (ANY) means anything 
 *        [including nothing])
 *       * `S` is Topgroup of stack `a`  
 *         a: (ANY) `G` `S`  
 *         b: (ANY)  
 *       * `S` is Endgroup of stack `a`  
 *         a: `S` (ANY) `G`  
 *         b: (ANY)  
 *       * `S` is Topgroup of stack `b` (=> stack `a` is fully green)  
 *         a: `G`  
 *         b: (ANY) `G` `S`  
 *       * `S` is Endgroup of stack `b` (=> stack `a` is fully green)  
 *         a: `G`  
 *         b: `S` (ANY) `G`  
 * @param[in,out] soon_green The to be directly sorted group becoming green soon
 * @param[in,out] stack stack `a` and stack `b`
 */
void	join_green_directsort(t_dl_node *soon_green, t_dl_node **stack)
{
	int	size;

	if (soon_green == NULL)
		h_err_exit(error(ERR_LOGIC), "join_green_directsort (NULL input!)");
	mark__group_as_green(soon_green);
	size = ((t_ps_obj *)soon_green->obj)->group.size;
	if (size == 1)
		join_green_size_1(soon_green, stack);
	else if (size == 2)
		join_green_size_2(soon_green, stack);
	else if (size == 3)
	{
		if (!is_on_a(soon_green))
			set__ranks_as_if_on_stack_a(soon_green);
		join_green_size_3(soon_green, stack);
	}
}

static void	mark__group_as_green(t_dl_node *soon_green)
{
	int			size;

	if (((t_ps_obj *)soon_green->obj)->group.starts == false)
		h_err_exit(error(ERR_LOGIC), "mark_group_as_green (group.starts)");
	size = ((t_ps_obj *)soon_green->obj)->group.size;
	while (size > 1)
	{
		((t_ps_obj *)soon_green->obj)->is_green = true;
		soon_green = soon_green->next;
		size--;
	}
	if (((t_ps_obj *)soon_green->obj)->group.ends == false)
		h_err_exit(error(ERR_LOGIC), "mark_group_as_green (group.ends)");
	((t_ps_obj *)soon_green->obj)->is_green = true;
}

/**
 * @note This is a helper for treating the size 3 case
 */
static void	set__ranks_as_if_on_stack_a(t_dl_node *group_of_size_3)
{
	int		*rank[3];
	size_t	i;
	size_t	i_1;
	size_t	i_3;

	rank[0] = &((t_ps_obj *) group_of_size_3->obj)->group.rank;
	rank[1] = &((t_ps_obj *) group_of_size_3->next->obj)->group.rank;
	rank[2] = &((t_ps_obj *) group_of_size_3->next->next->obj)->group.rank;
	i_1 = 0xdeaf;
	i_3 = 0xdeaf;
	i = 0;
	while (i < 3)
	{
		if (*rank[i] == 1)
			i_1 = i;
		if (*rank[i] == 3)
			i_3 = i;
		i++;
	}
	if (i_1 == 0xdeaf || i_3 == 0xdeaf)
		h_err_exit(error(ERR_LOGIC), "set__ranks_as_if_on_stack_a: "
			"no rank 1 or rank 3 found!");
	*rank[i_1] = 3;
	*rank[i_3] = 1;
}
