/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:53:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/07 11:02:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file big_size_algo.c
 * @brief Stores the definition of big_size_algo
 */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>

static bool			all__marked_green(t_dl_node **stack);
static void			exit__on_unexpected(t_dl_node *group, t_dl_node** stack);
static t_dl_node	*get__max_non_green_group(t_dl_node **stack);
////////////////////////////////////////////////////////////////////////////////////
// static void	act__on_a_till_green(t_dl_node **stack);
// static void	extend__green_area_by_small_groups_from_b(t_dl_node **stack);

/**
 * @brief The main algorithm which is based on repeating the following idea:
 *        * Split a group A of unsorted numbers into three groups X, Y, Z
 *          of the same size (if possible) or +-1 else, such that X < Y < Z
 *          where X < Y means that every number in X is smaller than any number
 *          in Y. E.g. {7, 9, 8}  <  {11, 10} holds true.
 *        * If a group has reached a size <= 5 sort it directly and potentially
 *          add it to the "green" region of already perfectly sorted numbers.
 * @param[in, out] stack Well the to be sorted stack[A] and the initially empty
 *                       stack[B]
 */
void	big_size_algo(t_dl_node **stack)
{
	t_dl_node *max_group;
	int	size;

	while (!all__marked_green(stack))
	{
		max_group = get__max_non_green_group(stack);
		exit__on_unexpected(max_group, stack);
		size = group_size(max_group);
		if (size <= MAX_SIZE_DIRECT_SORT)
			join_green_directsort(max_group, stack);
		else
			trivide(max_group, stack);


		// act__on_a_till_green(stack);
		// extend__green_area_by_small_groups_from_b(stack);
		// if (stack[B] != NULL)
		// 	trivide(truly_max_group(stack[B]), stack);
	}
	//TODO: rotate till the smallest number is on top - theoretically there
	//should be no need to do that, but who knows if I overlooked something ......
}

static void	exit__on_unexpected(t_dl_node *group, t_dl_node** stack)
{
	t_dl_node	*last;

	if (group == NULL)
		h_err_exit(error(ERR_LOGIC), "big_size_algo (NULL unexpected)");
	last = group_memb_last(group);
	if (group == stack[A] || group == stack[B])
		return ;
	else if (last == stack[A]->prev || last == stack[B]->prev)
		return ;
	h_err_exit(error(ERR_LOGIC), "big_size_algo (state unexpected)");
}

static bool	all__marked_green(t_dl_node **stack)
{
	t_dl_node	*node;

	if (stack[B] != NULL)
		return (false);
	if (stack[A] == NULL)
		return (true);
	node = stack[A];
	if (((t_ps_obj *)node->obj)->is_green == false)
		return (false);
	while (node->next != stack[A])
	{
		if (((t_ps_obj *)node->obj)->is_green == false)
			return (false);
		node = node->next;
	}
	return (true);
}

static t_dl_node	*get__max_non_green_group(t_dl_node **stack)
{
	t_dl_node *max_non_green_group_a;
	t_dl_node *truly_max_group_b;
	int max_goal_a;
	int min_goal_b;

	max_non_green_group_a = max_non_green_group(stack[A], &max_goal_a);
	truly_max_group_b = truly_max_group(stack[B], &min_goal_b);
	if (stack[A] == NULL)
		return (truly_max_group_b);
	if (stack[B] == NULL)
		return (max_non_green_group_a);
	if (max_goal_a > (-1) * min_goal_b)
		return (max_non_green_group_a);
	else
		return (truly_max_group_b);
}
///////////////////////////////////////////////////////////////////////////////////////

// static void	act__on_a_till_green(t_dl_node **stack)
// {
// 	t_dl_node	*wanna_be_green;

// 	wanna_be_green = max_non_green_group(stack[A]);
// 	while (wanna_be_green != NULL)
// 	{
// 		while (group_size(wanna_be_green) > MAX_SIZE_DIRECT_SORT)
// 		{
// 			trivide(wanna_be_green, stack);
// 			wanna_be_green = max_non_green_group(stack[A]);
// 		}
// 		join_green_directsort(wanna_be_green, stack);
// 		wanna_be_green = max_non_green_group(stack[A]);
// 	}
// }

// static void	extend__green_area_by_small_groups_from_b(t_dl_node **stack)
// {
// 	t_dl_node	*wanna_be_green;

// 	wanna_be_green = truly_max_group(stack[B]);
// 	while (group_size(wanna_be_green) <= MAX_SIZE_DIRECT_SORT
// 		&& wanna_be_green != NULL)
// 	{
// 		join_green_directsort(wanna_be_green, stack);
// 		wanna_be_green = truly_max_group(stack[B]);
// 	}
// }
