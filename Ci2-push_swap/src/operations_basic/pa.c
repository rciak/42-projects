/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:51:28 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 12:28:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pa.c
 * @brief Stores the definition of pa()
 */

#include "push_swap.h"

static	t_dl_node *settle__estate_on_ori_stack(t_dl_node *ori);

/**
 * @brief push (to) a: Take the first element at the top of stack `b`
 *                     and put it at the top of stack `a` and
 *                     print the instruction "pa" followed by a newline.
 *                     Do nothing if b is empty.
 *
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	pa (t_dl_node **stack)
{
	t_dl_node	*dest;
	t_dl_node	*ori;
	t_dl_node	*future_ori;
	
	dest = stack[A];
	ori = stack[B];
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

// SECURE COPY of the very first version
/*
void	pa (t_dl_node **stack)
{
	t_dl_node	*future_b;

	if (stack[B] == NULL)
		return ;
	else if (dl_lst_size(stack[B]) == 1)
	{
		if (stack [A] != NULL)
		{
			stack[B]->next = stack[A];
			stack[B]->prev = stack[A]->prev;
			stack[B]->next->prev = stack[B];
			stack[B]->prev->next = stack[B];
		}
		stack[A] = stack[B];
		stack[B] = NULL;
	}
	else
	{
		future_b = stack[B]->next;
		stack[B]->next->prev = stack[B]->prev;
		stack[B]->prev->next = stack[B]->next;
		if (stack[A] != NULL)
		{
			stack[B]->next = stack[A];
			stack[B]->prev = stack[A]->prev;
			stack[B]->next->prev = stack[B];
			stack[B]->prev->next = stack[B];
			
		}	
		stack[A] = stack[B];
		stack[B] = future_b;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}
*/