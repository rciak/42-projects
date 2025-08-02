/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_r_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:54:33 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 22:57:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rev_r_it.c
 * @brief Stores the definition of rev_r_it()
 */

#include "push_swap.h"

/**
 * @brief Reverse rotates a given node, being on either stack `a` or `b`by
 *        calling rra or rrb.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	rev_r_it(t_dl_node *node, **stack)
{
	if (is_on_a(node))
		rra(stack);
	else
	 	rrb(stack);
}
