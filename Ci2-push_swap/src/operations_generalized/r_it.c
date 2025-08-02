/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_it.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:04:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 23:00:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file r_it
 * @brief Stores the definition of r_it()
 */

#include "push_swap.h"

/**
 * @brief Rotates a given node, being on either stack `a` stack `b` by
 *        calling ra or rb.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	r_it(t_dl_node *node, t_dl_node **stack)
{
	if (is_on_a(node))
		ra(stack);
	else
	 	rb(stack);
}
