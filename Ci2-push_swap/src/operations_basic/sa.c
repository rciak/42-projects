/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:05:48 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 21:52:14 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sa.c
 * @brief Stores the definition of sa()
 */

#include "push_swap.h"

/**
 * @brief Swaps the first and second elements of stack `a` - provided it 
 *        contains at least two elements. In this case "sa" is printed;
 *        otherwise nothing happens.
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	sa(t_dl_node **stack)
{
	if (swap(stack, A))
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}
