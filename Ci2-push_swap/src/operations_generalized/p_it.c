/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_it.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:02:46 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 14:24:28 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file p_it.c
 * @brief Stores the definition of p_it()
 */

#include "push_swap.h"

/**
 * @brief Pushes a given node, being on either stack `a` stack `b` to the other
 *        stack.
 * @note  This unifies `pa` and `pb` in one single command. Together with
 *        the other "generalized" operations r_it() and rr_it(), along with
 *        the sign change of the goal value of the pushed node when applying
 *        `pa` or `pb` this allows a rather nice implementation of trivide() :
 *        * The two external helpers `trivide_top_group` and `trivide_end_group`
 *          are sufficient (no further distinguishment need if these groups are
 *          on stack `a` or `b`)
 *        * The two static helpers mark_subgroups_in_top() and
 *          mark_subgroups_in_end() can mark the subgroups that stays
 *          on the stack in the same unified way (although that subgroup is 
 *          once the subgroup of biggest numbers (when being on stack `a`)
 *          and once the subgroup of smallest numbers (when being on stack `b`)!
 * @note `p_it` stands for *push it*.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	p_it(t_dl_node *node, t_dl_node **stack)
{
	if (is_on_a(node))
		pb(stack);
	else
		pa(stack);
}
