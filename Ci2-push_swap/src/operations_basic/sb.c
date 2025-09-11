/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:02:07 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 21:52:23 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sb.c
 * @brief Stores the definition of sb()
 */

#include "push_swap.h"

/**
 * @brief Swaps the first and second elements of stack `b`- provided it
 *        contains at least two elements. In this case "sb" is printed;
 *        otherwise nothing happens.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	sb(t_dl_node **stack)
{
	if (swap(stack, B))
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}
