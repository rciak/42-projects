/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_green_size_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:14:11 by reciak            #+#    #+#             */
/*   Updated: 2025/08/07 17:43:04 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file join_green_size_3.c
 * @brief Stores the definition of join_green_size_3()
 */

#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>

static void	sortin__a_top(t_dl_node **stack, int *rank, size_t m, bool cyclic);
static void	sortin__a_end(t_dl_node **stack, int *rank, size_t m, bool cyclic);
static void	sortin__b_top(t_dl_node **stack, int *rank, size_t m, bool cyclic);
static void	sortin__b_end(t_dl_node **stack, int *rank, size_t m, bool cyclic);

/**
 * @brief For putting size 3 groups on top of the green area on stack `a`
 */
void	join_green_size_3(t_dl_node *group, t_dl_node **stack)
{
	int			rank[3];
	size_t		i_max;
	bool		cyclic;
	t_dl_node	*last;

	rank[0] = ((t_ps_obj *) group->obj)->group.rank;
	rank[1] = ((t_ps_obj *) group->next->obj)->group.rank;
	rank[2] = ((t_ps_obj *) group->next->next->obj)->group.rank;
	i_max = 0;
	while (rank[i_max] != 3)
		i_max++;
	cyclic = is_cyclic(group);
	last = group_memb_last(group);
	if (group == stack[A])
		sortin__a_top(stack, rank, i_max, cyclic);
	else if (last == stack[A]->prev)
		sortin__a_end(stack);
	else if (group == stack[B])
		sortin__b_top(stack);
	else if (last == stack[B]->prev)
		sortin__b_end(stack);
	else
		h_err_exit(error(ERR_LOGIC), "join_green_size_3");
}

static void	sortin__a_top(t_dl_node **stack, int *rank, size_t m, bool cyclic)
{
	if (m == 2)
	{
		if (!cyclic)
			sa(stack);
	}
	else if (m == 1)
	{
		ra(stack);
		sa(stack);
		rra(stack);
		if (cyclic)
			sa(stack);
	}
	else if (m == 0)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		if (!cyclic)
			sa(stack);
	}
}

static void	sortin__a_end(t_dl_node **stack, int *rank, size_t m, bool cyclic)
{
	// rra(stack);
	// rra(stack);
	// if (((t_ps_obj *) stack[A]->obj)->n
	// 	> ((t_ps_obj *) stack[A]->next->obj)->n)
	// 	sa(stack);
}

static void	sortin__b_top(t_dl_node **stack, int *rank, size_t m, bool cyclic)
{
	// pa(stack);
	// pa(stack);
	// if (((t_ps_obj *) stack[A]->obj)->n
	// 	> ((t_ps_obj *) stack[A]->next->obj)->n)
	// 	sa(stack);
}

static void	sortin__b_end(t_dl_node **stack, int *rank, size_t m, bool cyclic)
{
	// rrb(stack);
	// pa(stack);
	// rrb(stack);
	// pa(stack);
	// if (((t_ps_obj *) stack[A]->obj)->n
	// 	> ((t_ps_obj *) stack[A]->next->obj)->n)
	// 	sa(stack);
}
