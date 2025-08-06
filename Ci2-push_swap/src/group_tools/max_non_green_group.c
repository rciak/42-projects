/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_non_green_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:08:27 by reciak            #+#    #+#             */
/*   Updated: 2025/08/06 10:39:25 by reciak           ###   ########.fr       */
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
 *        other "non-green" groups, cf. big_size_algo()
 * @note This functions was orignally designed to be applied to stack[A]
 *       (any node of stack a).
 *       Calling it with stack[B] makes no sense since it would pick the
 *       **smallest** group since pushing causes a sign change...
 * @note For picking the **effectively maximal** group in **stack b**
 *       the function `truly_max_group` should be used.
 * @warning This function expects a doubly linked list in **circular**
 *          form!
 * @param[in] stack_a a pointer to a node of stack[A], being in circular form.
 * @return
 *          * a pointer to the group that is maximal amongst the
 *            "non-green" groups, if any, or
 *          * `NULL` if there are no "non-green" groups
 *            on stack_a
 */
t_dl_node *max_non_green_group(t_dl_node *stack_a)
{
	int			max;
	t_dl_node	*best_so_far;
	t_dl_node	*node;
	t_ps_obj	*obj;

	if (stack_a == NULL)
		return (NULL);
	best_so_far = NULL;
	node = stack_a;
	max = SMALLER_THAN_ANY_GOAL;
	if (((t_ps_obj *) node->obj)->is_green == false)
	{
		best_so_far = node;
		max = ((t_ps_obj*)node->obj)->goal;
	}
	dl_lst_linearize(stack_a);
	while (node != NULL)
	{
		obj = (t_ps_obj*)node->obj; 
		if (obj->goal > max && obj->is_green == false)
		{
			max = obj->goal;
			best_so_far = node;
		}
		node = node->next;
	}
	dl_lst_circularize(stack_a);
	if (max == SMALLER_THAN_ANY_GOAL)
		return (NULL);
	while (((t_ps_obj*)best_so_far->obj)->group.starts != true)
		best_so_far = best_so_far->prev;
	return (best_so_far);
}
