/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:53:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/30 19:37:12 by reciak           ###   ########.fr       */
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
static void	tri__vide(t_dl_node **boundary_group, t_dl_node **stack);
static void	set__markers_subgroups(t_dl_node *non_trivided, t_dl_node **new_wb);

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
				tri__vide(&wanna_be_green, stack);
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
			tri__vide(&wanna_be_green, stack);
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

static void	tri__vide(t_dl_node **boundary_group, t_dl_node **stack)
{
	t_dl_node	*last;
	t_dl_node	*new_wanna_be_green;

	update_group(*boundary_group);
	set__markers_subgroups(*boundary_group, &new_wanna_be_green);
	last = group_memb_last(*boundary_group);
	if (*boundary_group == stack[A] || *boundary_group == stack[B])
		trivide_top_group(*boundary_group, stack);
	else if (last == stack[A]->prev || last == stack[B]->prev)
		trivide_end_group(*boundary_group, stack);
	else
	{
		handle_error(error(ERR_LOGIC));
		exit (ERR_LOGIC);
	}
	*boundary_group = new_wanna_be_green;
}

/**
 * @note The arrayname `outside` and its values deserves to be illustrated by
 *       an example: Consider a group of 7 elements such that its rank list is
 *       `2 6 3 5 1 7 4`.
 *       The numbers with rank
 *       * `2 1`  form the first leaver group (they will go to the other stack),
 *       * `3 4`  form the second leaver group
 *       * `6 5 7` form the stayer group (they will stay on the same stack).
 *       The integer just below the ranks `2 1` is **0**
 *       below `3 4` it is **2** and below `6 5 7` it is **4**.
 *       This fits to the variable values set inside the function
         @code 
           s = 7; 
           outside[LEAVER_1] = 0
           outside[LEAVER_2] = s / 3 = 7 / 3 = 2
           outside[STAYER]   = s - (s+2)/3 = 7 - 9/3 = 7 - 3 = 4
         @endcode
 *       Finally `outside[3] = s` fit into the picture
 *       when rewriting the above slightly:
         @code  
           outside[LEAVER_1] == 0 < {2 1} <= 2 == outside[LEAVER_2]
           outside[LEAVER_2] == 2 < {3 4} <= 4 == outside[STAYER]
           outside[STAYER]   == 4 < {6 5 7} (<= 7 == outside[3])
         @endcode
 */
static void	set__markers_subgroups(t_dl_node *non_trivided, t_dl_node **new_wb)
{
	t_dl_node	*first_hit[3];
	t_dl_node	*last_hit[3];
	int			outside[4];
	int			s;

	s = ((t_ps_obj *) non_trivided->obj)->group.size;
	outside[LEAVER_1] = 0;
	outside[LEAVER_2] = s / 3;
	outside[STAYER] = s - (s + 2) / 3;
	outside[3] = s;
	detect___hits_of_subgroups(first_hit, last_hit, non_trivided, outside);
	remove_group_markers(non_trivided);
	((t_ps_obj *) first_hit[STAYER]->obj)->group.starts = true;
	((t_ps_obj *) last_hit[STAYER]->obj)->group.ends = true;
	((t_ps_obj *) first_hit[LEAVER_1]->obj)->group.ends = true;
	((t_ps_obj *) last_hit[LEAVER_1]->obj)->group.starts = true;
	((t_ps_obj *) first_hit[LEAVER_2]->obj)->group.ends = true;
	((t_ps_obj *) last_hit[LEAVER_2]->obj)->group.starts = true;
	if (is_on_stack_a(non_trivided))
		*new_wb = first_hit[STAYER];
	else
	{
		*new_wb = last_hit[LEAVER_1];
	}
}

//detect___hits_of_subgroups(t_dl_node *first_hit,
// t_dl_node *last_hit, t_dl_node *non_trivided, int *outside)
detect___hits_of_subgroups(t_dl_node *first_hit, t_dl_node *last_hit)
{
}
