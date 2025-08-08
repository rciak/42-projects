/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_green_size_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:14:11 by reciak            #+#    #+#             */
/*   Updated: 2025/08/08 21:16:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file join_green_size_3.c
 * @brief Stores the definition of join_green_size_3()
 */

#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>

static void	sortin__a_top(t_dl_node **stack, size_t i_max, bool cyclic);
static void	sortin__a_end(t_dl_node **stack, size_t i_max, bool cyclic);
static void	sortin__b_top(t_dl_node **stack, size_t i_max, bool cyclic);
static void	sortin__b_end(t_dl_node **stack, size_t i_max, bool cyclic);

/**
 * @brief For putting size 3 groups on top of the green area on stack `a`
 * @note regarding the variable \p i_max_min note that
 */
void	join_green_size_3(t_dl_node *group, t_dl_node **stack)
{
	size_t		i_max_min;
	bool		cyclic;
	t_dl_node	*last;

	if (((t_ps_obj *) group->obj)->group.rank == 3)
		i_max_min = 0;
	else if (((t_ps_obj *) group->next->obj)->group.rank == 3)
		i_max_min = 1;
	else if (((t_ps_obj *) group->next->next->obj)->group.rank == 3)
		i_max_min = 2;
	cyclic = is_cyclic(group);
	last = group_memb_last(group);
	if (group == stack[A])
		sortin__a_top(stack, i_max_min, cyclic);
	else if (last == stack[A]->prev)
		sortin__a_end(stack, i_max_min, cyclic);
	else if (group == stack[B])
		sortin__b_top(stack, i_max_min, cyclic);
	else if (last == stack[B]->prev)
		sortin__b_end(stack, i_max_min, cyclic);
	else
		h_err_exit(error(ERR_LOGIC), "join_green_size_3");
}

static void	sortin__a_top(t_dl_node **stack, size_t i_max, bool cyclic)
{
	if (i_max == 2)
	{
		if (!cyclic)
			sa(stack);
	}
	else if (i_max == 1)
	{
		ra(stack);
		sa(stack);
		rra(stack);
		if (cyclic)
			sa(stack);
	}
	else if (i_max == 0)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		if (!cyclic)
			sa(stack);
	}
}

static void	sortin__a_end(t_dl_node **stack, size_t i_max, bool cyclic)
{
	rra(stack);
	rra(stack);
	if (i_max == 2)
	{
		rra(stack);
		if (!cyclic)
			sa(stack);
	}
	else if (i_max == 1)
	{
		sa(stack);
		rra(stack);
		if (cyclic)
			sa(stack);
	}
	else if (i_max == 0)
	{
		pb(stack);
		rra(stack);
		sa(stack);
		pa(stack);
		if (!cyclic)
			sa(stack);
	}
}

static void	sortin__b_top(t_dl_node **stack, size_t i_max, bool cyclic)
{
	pa(stack);
	if (i_max == 0)
	{
		pa(stack);
		pa(stack);
		if (cyclic)
			sa(stack);
	}
	else if (i_max == 1)
	{
		pa(stack);
		sa(stack);
		pa(stack);
		if (!cyclic)
			sa(stack);
	}
	else if (i_max == 2)
	{
		sb(stack);
		pa(stack);
		sa(stack);
		pa(stack); 
		if (cyclic)
			sa(stack);
	}
}

static void	sortin__b_end(t_dl_node **stack, size_t i_max, bool cyclic)
{
	if (i_max == 0)
	{
		rrb(stack);
		rrb(stack);
		rrb(stack);
		sortin__b_top(stack, i_max, cyclic);
	}
	else if (i_max == 1)
	{
		rrb(stack);
		rrb(stack);
		pa(stack);
		if (!cyclic)
			pa(stack);
		rrb(stack);
		if (cyclic)
			pa(stack);
		pa(stack);
	}
	else if (i_max == 2)
	{
		rrb(stack);
		pa(stack);
		rrb(stack);
		pa(stack);
		rrb(stack);
		pa(stack);
		if (!cyclic)
			sa(stack);
	}
}
