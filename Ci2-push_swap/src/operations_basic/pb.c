/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:00:54 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 12:38:24 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pb.c
 * @brief Stores the definition of pb()
 */

#include "push_swap.h"

static	t_dl_node *settle__estate_on_ori_stack(t_dl_node *ori);

/**
 * @brief push (to) b: Take the first element at the top of stack `a`
 *                     and put it at the top of stack `b` and
 *                     print the instruction "pb" followed by a newline.
 *                     Do nothing if `a` is empty.
 *
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	pb (t_dl_node **stack)
{
	t_dl_node	*dest;
	t_dl_node	*ori;
	t_dl_node	*future_ori;
	
	dest = stack[B];
	ori = stack[A];
	if (ori == NULL)
		return ;
	future_ori = settle__estate_on_ori_stack(ori);
	if (dest == NULL)
	{
		ori->next = ori;
		ori->prev = ori;
	}
	else
	{
		ori->next = dest;
		ori->prev = dest->prev;
		ori->next->prev = ori;
		ori->prev->next = ori;
	}	
	dest = ori;
	ori = future_ori;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

static	t_dl_node *settle__estate_on_ori_stack(t_dl_node *ori)
{
	t_dl_node	*future_ori;

	if (dl_lst_size(ori) <= 1)
		return (NULL);
	future_ori = ori->next;
	ori->next->prev = ori->prev;
	ori->prev->next = ori->next;
	return (future_ori);
}
