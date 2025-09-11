/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:01:06 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 21:20:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ra.c
 * @brief Stores the definition of ra()
 */

#include "push_swap.h"

/**
 * @brief Rotates stack `a` such that the first element becomes the last
 *        and prints the instruction "ra" followed by a newline.
 *        Does nothing if stack `a` is empty.
 *
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	ra(t_dl_node **stack)
{
	if (stack[A] == NULL)
		return ;
	stack[A] = stack[A]->next;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}
