/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:02:13 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 21:58:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ss.c
 * @brief Stores the definition of ss()
 */

#include "push_swap.h"

/**
 * @brief Swaps "simultaneaous" on both stack `a` and `b` their respective
 *        first and second element - provided they exist. If the swaping
 *        was possible on at least on stack "sa" is printed;
 *        Otherwise nothing happens.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	ss(t_dl_node **stack)
{
	bool	a_swapable;
	bool	b_swapable;

	a_swapable = swap(stack, A);
	b_swapable = swap(stack, B);
	if (a_swapable || b_swapable)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}
