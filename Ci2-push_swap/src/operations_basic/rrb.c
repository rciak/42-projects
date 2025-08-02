/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:01:57 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 13:02:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rrb.c
 * @brief Stores the definition of rrb()
 */

#include "push_swap.h"

/**
 * @brief Rotates stack `b` such that the last element becomes the first.
 *
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	rrb(t_dl_node **stack)
{
	if (stack[B] == NULL)
		return ;
	stack[B] = stack[B]->prev;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}