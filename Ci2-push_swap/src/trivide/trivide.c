/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:02:58 by reciak            #+#    #+#             */
/*   Updated: 2025/08/01 17:55:28 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file trivide.c
 * @brief Stores the definition of trivide()
 */

#include "push_swap.h"

static void	mark_subgroups_in_top(t_dl_node *non_trivided, t_dl_node **subgrp);
static void	mark_subgroups_in_end(t_dl_node *non_trivided, t_dl_node **subgrp);
static void	detect___hits_of_subgroups(
				t_dl_node **first_hit,
				t_dl_node **last_hit,
				t_dl_node *non_trivided,
				int *outside);
static void	remove___group_markers(t_dl_node *non_trivided);

/**
 * @brief Prepares and orchestrates the splitting of a group of
          `size > MAX_SIZE_DIRECT_SORT` into three subgroups,
          being the core idea behind the algorithm (for an initial stack of
          more than `MAX_SIZE_DIRECT_SORT` numbers).
 * @note The actual spliting is done by the functions @c trivide_top_group
 *       and @c trivide_end_group , respectively.
 * @param[in,out] boundary_group A pointer 
 *                               to the **first node** of either the top group
 *                               or end group (on any of the two stacks).
 * @param[in,out] stack A double pointer such that `stack[A]` and `stack[B]`
 *                      are pointers to stack a and stack b, respectively.
 */
void	trivide(t_dl_node *boundary_group, t_dl_node **stack)
{
	t_dl_node	*last;
	t_dl_node	*subgroup[3];

	update_group(boundary_group);   //---------------------------------------------try to omit
	last = group_memb_last(boundary_group);
	if (boundary_group == stack[A] || boundary_group == stack[B])
	{
		mark_subgroups_in_top(boundary_group, subgroup);
		trivide_top_group(boundary_group, stack);
	}
	else if (last == stack[A]->prev || last == stack[B]->prev)
	{
		mark_subgroups_in_end(boundary_group, subgroup);
		trivide_end_group(boundary_group, stack);
	}
	else
		h_err_exit(error(ERR_LOGIC), "trivide (unexpected state)");
	update_group(subgroup[0]);
	update_group(subgroup[1]);
	update_group(subgroup[2]);
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
           outside[LEAVER_UP] = 0
           outside[LEAVER_DOWN] = s / 3 = 7 / 3 = 2
           outside[STAYER]   = s - (s+2)/3 = 7 - 9/3 = 7 - 3 = 4
         @endcode
 *       Finally `outside[3] = s` fit into the picture
 *       when rewriting the above slightly:
         @code  
           outside[LEAVER_UP] == 0 < {2 1} <= 2 == outside[LEAVER_DOWN]
           outside[LEAVER_DOWN] == 2 < {3 4} <= 4 == outside[STAYER]
           outside[STAYER]   == 4 < {6 5 7} (<= 7 == outside[3])
         @endcode
 *
 */
static void	mark_subgroups_in_top(t_dl_node *non_trivided, t_dl_node **subgrp)
{
	t_dl_node	*first_hit[3];
	t_dl_node	*last_hit[3];
	int			outside[4];
	int			s;
	t_dl_node	*subgroup[3];

	ft_bzero(first_hit, sizeof(first_hit));
	ft_bzero(last_hit, sizeof(last_hit));
	s = ((t_ps_obj *) non_trivided->obj)->group.size;
	outside[LEAVER_UP] = 0;
	outside[LEAVER_DOWN] = s / 3;
	outside[STAYER] = s - (s + 2) / 3;
	outside[3] = s;
	detect___hits_of_subgroups(first_hit, last_hit, non_trivided, outside);
	remove___group_markers(non_trivided);
	((t_ps_obj *) first_hit[LEAVER_UP]->obj)->group.ends = true;
	((t_ps_obj *) last_hit[LEAVER_UP]->obj)->group.starts = true;
	((t_ps_obj *) first_hit[LEAVER_DOWN]->obj)->group.starts = true;
	((t_ps_obj *) last_hit[LEAVER_DOWN]->obj)->group.ends = true;
	((t_ps_obj *) first_hit[STAYER]->obj)->group.starts = true;
	((t_ps_obj *) last_hit[STAYER]->obj)->group.ends = true;
	subgroup[0] = last_hit[LEAVER_UP];
	subgroup[1] = first_hit[LEAVER_DOWN];
	subgroup[2] = first_hit[STAYER];
}

static void	mark_subgroups_in_end(t_dl_node *non_trivided, t_dl_node **subgrp)
{
	t_dl_node	*first_hit[3];
	t_dl_node	*last_hit[3];
	int			outside[4];
	int			s;
	t_dl_node	*subgroup[3];

	ft_bzero(first_hit, sizeof(first_hit));
	ft_bzero(last_hit, sizeof(last_hit));
	s = ((t_ps_obj *) non_trivided->obj)->group.size;
	outside[LEAVER_UP] = 0;
	outside[LEAVER_DOWN] = s / 3;
	outside[STAYER] = s - (s + 2) / 3;
	outside[3] = s;
	detect___hits_of_subgroups(first_hit, last_hit, non_trivided, outside);
	remove___group_markers(non_trivided);
	((t_ps_obj *) first_hit[LEAVER_UP]->obj)->group.starts = true;
	((t_ps_obj *) last_hit[LEAVER_UP]->obj)->group.ends = true;
	((t_ps_obj *) first_hit[LEAVER_DOWN]->obj)->group.ends = true;
	((t_ps_obj *) last_hit[LEAVER_DOWN]->obj)->group.starts = true;
	((t_ps_obj *) first_hit[STAYER]->obj)->group.starts = true;
	((t_ps_obj *) last_hit[STAYER]->obj)->group.ends = true;
	subgroup[0] = first_hit[LEAVER_UP];
	subgroup[1] = last_hit[LEAVER_DOWN];
	subgroup[2] = first_hit[STAYER];
}

static void	detect___hits_of_subgroups(
	t_dl_node **first_hit,
	t_dl_node **last_hit,
	t_dl_node *non_trivided,
	int *outside)
{
	int	i;
	int	j;
	int	r;
	
	i = 0;
	while (i < ((t_ps_obj *)non_trivided->obj)->group.size)
	{
		j = 0;
		while (j < 3)
		{
			r = ((t_ps_obj *)non_trivided->obj)->group.rank;
			if (outside[j] < r && r <= outside[j + 1] && first_hit[j] == NULL)
				first_hit[j] = non_trivided;
			if (outside[j] < r && r <= outside[j + 1])
				last_hit[j] = non_trivided;
			j++;
		}
		non_trivided = non_trivided->next;
		i++;
	}
}

static void	remove___group_markers(t_dl_node *non_trivided)
{
	int			size;

	if (((t_ps_obj *)non_trivided->obj)->group.starts == false)
		h_err_exit(error(ERR_LOGIC),"remove___group_markers"
			"(group.starts was unset)");
	size = ((t_ps_obj *)non_trivided->obj)->group.size;
	while (size > 1)
	{
		((t_ps_obj *)non_trivided->obj)->group.starts = false;
		((t_ps_obj *)non_trivided->obj)->group.ends = false;
		non_trivided = non_trivided->next;
		size--;
	}
	if (((t_ps_obj *)non_trivided->obj)->group.ends == false)
		h_err_exit(error(ERR_LOGIC),"remove___group_markers"
			"(group.ends was unset)");
	((t_ps_obj *)non_trivided->obj)->group.starts = false;
	((t_ps_obj *)non_trivided->obj)->group.ends = false;
}

