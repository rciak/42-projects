/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_non_green_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:08:27 by reciak            #+#    #+#             */
/*   Updated: 2025/07/29 15:59:51 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file max_non_green_group.c
 * @brief Stores the definition of max_non_green_group
 */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Finds the maximal group in stack a
 *        that is not yet added to the "green" region of
 *        already perfectly sorted numbers.
 *        The maximal of these "non green" groups is the one
 *        whose numbers are all bigger than the numbers of the
 *        other "non-green" groups.
 * @note This functions is designed to be applied to stack[A]
 *       (any node of stack a).
 *       Calling it with stack[B] is not intended.
 * @warning This function expects doubly linked list in circular
 *          form. 
 * @param[in] stack_a a pointer to a node of stack[A]
 * @return
 *          * a pointer to the group that is maximal amongst the
 *            "non-green" groups, if any, or
 *          * `NULL` if there are no "non-green" groups
 *            on stack_a
 */

t_dl_node *max_non_green_group(t_dl_node *stack_a)
{
	int	max;
	t_dl_node *node;
	t_dl_node *best_so_far;

	if (stack_a = NULL)
		return (NULL);
	node = stack_a;
	max = 0;
	while (node->next != stack_a)
	{

		node = node->next;
	}
	if (max == 0)
		return (NULL);
	return ();
}
