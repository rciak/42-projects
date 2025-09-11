/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truly_max_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:16:07 by reciak            #+#    #+#             */
/*   Updated: 2025/08/09 18:09:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file truly_max_group.c
 * @brief Stores the definition of truly_max_group()
 */

#include "push_swap.h"

/**
 * @brief Finds the maximal group in **stack b**, cf. max_mon_green_group()
 * @warning This function is tailored for stack_b and should be used with
 *          it only!
 * @note Note that the sign of goal value of a node depends on its location:
 *       Being on stack `a` the goal value is positive, being on stack `b`
 *       it is negative! Therefor the truly maximal group on
 *       stack_b is found by looking for the minmal group:
 *       Consider two groups on stack `a` with `goal` values 
 *       {2, 1, 3} and {5, 4}.
 *       The second group is maximal, c.f. big_size_algo().
 *       How ever on stack_b these groups would have goal values
 *       `{-2, -1, -3} and {-5, -4} such that the second group can be now
 *       only obtained as minimum!
 * @note Also note that there can be no green nodes on stack `b`. Therefore
 *       a single `NULL` check is sufficient here - in contrast to
 *       max_non_green_group() !
 * @param[in] stack_b a pointer to a node of stack[B], being in circular form.
 * @param[out] min a pointer to an int receiving the min goal number of stack
 *                 `b`'s nodes. If stack `b` is empty the value 
 *                 `0` is stored.
 * @return
 *          * a pointer to the maximal group on stack_b, if any, or
 *          * `NULL` if there are no groups on stack_b
 */
t_dl_node	*truly_max_group(t_dl_node *stack_b, int *min)
{
	t_dl_node	*best_so_far;
	t_dl_node	*node;
	t_ps_obj	*obj;

	*min = 0;
	if (stack_b == NULL)
		return (NULL);
	best_so_far = stack_b;
	*min = ((t_ps_obj *) best_so_far->obj)->goal;
	node = stack_b;
	dl_lst_linearize(stack_b);
	while (node != NULL)
	{
		obj = (t_ps_obj *)node->obj;
		if (obj->goal < *min)
		{
			*min = obj->goal;
			best_so_far = node;
		}
		node = node->next;
	}
	dl_lst_circularize(stack_b);
	while (((t_ps_obj *)best_so_far->obj)->group.starts != true)
		best_so_far = best_so_far->prev;
	return (best_so_far);
}
