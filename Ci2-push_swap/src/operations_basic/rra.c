/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:05:37 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 14:18:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rra
 * @brief Stores the definition of rra()
 */

#include "push_swap.h"

/**
 * @brief Rotates stack `a` such that the last element becomes the first
 *        and prints the instruction "rra" followed by a newline.
 *        Does nothing if stack `a` is empty.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	rra(t_dl_node **stack)
{
	if (stack[A] == NULL)
		return ;
	stack[A] = stack[A]->prev;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}
