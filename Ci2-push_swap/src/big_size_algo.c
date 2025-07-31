/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:53:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/31 15:29:15 by reciak           ###   ########.fr       */
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
	t_dl_node	*wanna_be_green;

	while (!all__marked_green(stack))
	{
		wanna_be_green = max_non_green_group(stack[A]);
		while (wanna_be_green != NULL)
		{
			while (group_size(wanna_be_green) > MAX_SIZE_DIRECT_SORT)
				trivide(&wanna_be_green, stack);
			join_green_directsort(&wanna_be_green, stack);
			wanna_be_green = max_non_green_group(stack[A]);
		}
//TODO: Manual testing: Only "green" numbers left on stack A at this moment?
		wanna_be_green = quasi_max_group(stack[B]);
		while (group_size(wanna_be_green) <= MAX_SIZE_DIRECT_SORT
			&& wanna_be_green != NULL)
		{
			join_green_directsort(&wanna_be_green, stack);
			wanna_be_green = quasi_max_group(stack[B]);
		}
		if (wanna_be_green != NULL)
			trivide(&wanna_be_green, stack);
	}
	//TODO: rotate till the smallest number is on top - theoretically there
	//should be no need to do that, but who knows if I overlooked something ...
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
