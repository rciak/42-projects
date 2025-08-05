/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:29:28 by reciak            #+#    #+#             */
/*   Updated: 2025/08/05 19:20:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file small_size_algo.c
 * @brief Stores the definition of small_size_algo()
 */

#include "libft.h"
#include "push_swap.h"

static void	rotate__rank_to_top_of_a(int rank, t_dl_node **stack, int size);
static void	size__4_algo(t_dl_node **stack);
static void	size__5_algo(t_dl_node **stack);
static int	steps___next_till_rank(t_dl_node *node, int rank);

/**
 * @brief Sorts an input stack of input size < `GO_FOR_BIG_SIZE_ALGO`
 * @note An input stack `a` of size 1 or 2 is always cyclic.
 *       For these cases and 
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	small_size_algo(t_dl_node **stack, int size)
{
	if (stack[A] == NULL)
		h_err_exit(error(ERR_LOGIC),
		"small_size_algo: stack[A] == NULL should have been treated before");
	if (is_cyclic(stack[A]))
		rotate__rank_to_top_of_a(1, stack, size);
	else if (size == 3 && !is_cyclic(stack[A]))
	{
		sa(stack);
		rotate__rank_to_top_of_a(1, stack, size);
	}
	else if (size == 4)
		size__4_algo(stack);
	else if (size == 5)
		size__5_algo(stack);
}

static void	rotate__rank_to_top_of_a(int rank, t_dl_node **stack, int size)
{
	int	i;

	i = steps___next_till_rank(stack[A], rank);
	if (i <= size / 2)
		while (i-- > 0)
			ra(stack);
	else
		while (i++ < size)
			rra(stack);
}

static void	size__4_algo(t_dl_node **stack)
{
	rotate__rank_to_top_of_a(1, stack, 4);
	pb(stack);
	be_group(stack[A], 3);
	small_size_algo(stack, 3);
	pa(stack);
}

static void	size__5_algo(t_dl_node **stack)
{
	(void) stack;
	return ;
}

static int	steps___next_till_rank(t_dl_node *node, int rank)
{
	int			i;
	
	i = 0;
	while (((t_ps_obj *)node->obj)->group.rank != rank)
	{
		node = node->next;
		i++;
	}
	return (i);
}