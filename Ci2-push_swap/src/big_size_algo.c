/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:53:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/01 15:02:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file big_size_algo.c
 * @brief Stores the definition of big_size_algo
 */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>

static bool	all__marked_green(t_dl_node **stack);
static void	act__on_a_till_green(t_dl_node **stack);
static void	extend__green_area_by_small_groups_from_b(t_dl_node **stack);

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
	while (!all__marked_green(stack))
	{
		act__on_a_till_green(stack); //Manual testing: Only "green" numbers left on stack A afterwards?
		extend__green_area_by_small_groups_from_b(stack);
		if (stack[B] != NULL)
			trivide(truly_max_group(stack[B]), stack);
	}
	//TODO: rotate till the smallest number is on top - theoretically there
	//should be no need to do that, but who knows if I overlooked something ......
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
	}
	return (true);
}

static void	act__on_a_till_green(t_dl_node **stack)
{
	t_dl_node	*wanna_be_green;

	wanna_be_green = max_non_green_group(stack[A]);
	while (wanna_be_green != NULL)
	{
		while (group_size(wanna_be_green) > MAX_SIZE_DIRECT_SORT)
		{
			trivide(wanna_be_green, stack);
			wanna_be_green = max_non_green_group(stack[A]);
		}
		join_green_directsort(wanna_be_green, stack);
		wanna_be_green = max_non_green_group(stack[A]);
	}
}

static void	extend__green_area_by_small_groups_from_b(t_dl_node **stack)
{
	t_dl_node	*wanna_be_green;

	wanna_be_green = truly_max_group(stack[B]);
	while (group_size(wanna_be_green) <= MAX_SIZE_DIRECT_SORT
		&& wanna_be_green != NULL)
	{
		join_green_directsort(wanna_be_green, stack);
		wanna_be_green = truly_max_group(stack[B]);
	}
}
