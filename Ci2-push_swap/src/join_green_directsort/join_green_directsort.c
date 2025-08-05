/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_green_directsort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:39:07 by reciak            #+#    #+#             */
/*   Updated: 2025/08/01 17:49:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file join_green_directsort
 * @brief Stores the definition of join_green_directsort()
 */

#include "libft.h"
#include "push_swap.h"

static void	mark__group_as_green(t_dl_node *soon_green);

/**
 * @brief Sort the prepared group (of `size <= MAX_SIZE_DIRECT_SORT`),
 *        put the sorted group in front of the "green" area on stack `a` and
 *        add it by marking it as green.
 * @note By construction of the algorithm this function will be handed
 *       over a group that is the top group or bottom group of stack A or B and 
 *       thus close to the green area; more precise:
 * @note The position of the "soon_green" group `S` and the 
 *       already green area `G` is one of the following 
 *       (Bottom leftmost, Top rightmost; (ANY) means anything 
 *        [including nothing])
 *       * `S` is Topgroup of stack `a`  
 *         a: (ANY) `G` `S`  
 *         b: (ANY)  
 *       * `S` is Endgroup of stack `a`  
 *         a: `S` (ANY) `G`  
 *         b: (ANY)  
 *       * `S` is Topgroup of stack `b` (=> stack `a` is fully green)  
 *         a: `G`  
 *         b: (ANY) `G` `S`  
 *       * `S` is Endgroup of stack `b` (=> stack `a` is fully green)  
 *         a: `G`  
 *         b: `S` (ANY) `G`  
 * @param[in,out] soon_green The to be directly sorted group becoming green soon
 * @param[in,out] stack stack `a` and stack `b`
 */
void	join_green_directsort(t_dl_node *soon_green, t_dl_node **stack)
{
	int	size;

	if (soon_green == NULL)
		h_err_exit(error(ERR_LOGIC),"join_green_directsort (NULL input!)");
	mark__group_as_green(soon_green);
	size = ((t_ps_obj *)soon_green->obj)->group.size;
	if (size == 1)
		join_green_size_1(soon_green, stack);
	else if (size == 2)
		join_green_size_2(soon_green, stack);
}
	//
	// ?? MAYBE NOT / no longer needed?! SETT all to groups of size 1 by setting the markers accorrdingly
	//

static void	mark__group_as_green(t_dl_node *soon_green)
{
	int			size;

	if (((t_ps_obj *)soon_green->obj)->group.starts == false)
		h_err_exit(error(ERR_LOGIC),"mark_group_as_green (group.starts)");
	size = ((t_ps_obj *)soon_green->obj)->group.size;
	while (size > 1)
	{
		((t_ps_obj *)soon_green->obj)->is_green = true;
		soon_green = soon_green->next;
		size--;
	}
	if (((t_ps_obj *)soon_green->obj)->group.ends == false)
		h_err_exit(error(ERR_LOGIC),"mark_group_as_green (group.ends)");
	((t_ps_obj *)soon_green->obj)->is_green = true;
}
