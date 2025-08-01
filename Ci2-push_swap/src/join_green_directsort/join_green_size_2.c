/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_green_size_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:08:44 by reciak            #+#    #+#             */
/*   Updated: 2025/08/01 18:20:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file join_green_size_2.c
 * @brief Stores the definition of join_green_size_2()
 */

#include "push_swap.h"

static void	sortin__a_top(t_dl_node **stack);
static void	sortin__a_end(t_dl_node **stack);
static void	sortin__b_top(t_dl_node **stack);
static void	sortin__b_end(t_dl_node **stack);

/**
 * @brief For putting size 1 groups on top of the green area on stack `a`
 */
void	join_green_size_2(t_dl_node *group, t_dl_node **stack)
{
	t_dl_node	*last;

	last = group_memb_last(group);
	if (group == stack[A])
		sortin__a_top(stack);
	else if (last == stack[A]->prev)
		sortin__a_end(stack);
	else if (group == stack[B])
		sortin__b_top(stack);
	else if (last == stack[B]->prev)
		sortin__b_end(stack);
	else
		h_err_exit(error(ERR_LOGIC), "join_green_size_2");
}

static void	sortin__a_top(t_dl_node **stack)
{

}

static void	sortin__a_end(t_dl_node **stack)
{

}

static void	sortin__b_top(t_dl_node **stack)
{

}

static void	sortin__b_end(t_dl_node **stack)
{

}
