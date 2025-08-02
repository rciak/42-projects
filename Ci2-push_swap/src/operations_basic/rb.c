/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:01:32 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 13:02:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rb
 * @brief Stores the definition of rb()
 */

#include "push_swap.h"

/**
 * @brief Rotates stack `b` such that the first element becomes the last.
 *
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	rb(t_dl_node **stack)
{
	if (stack[B] == NULL)
		return ;
	stack[B] = stack[B]->next;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}
