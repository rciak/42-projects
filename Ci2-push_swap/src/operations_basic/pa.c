/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:51:28 by reciak            #+#    #+#             */
/*   Updated: 2025/08/02 22:43:06 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pa.c
 * @brief Stores the definition of pa()
 */

#include "libft.h"
#include "push_swap.h"

static	t_dl_node *settle__estate_on_ori_stack(t_dl_node *ori);

/**
 * @brief push (to) a: Take the first element at the top of stack `b`
 *                     and put it at the top of stack `a` and
 *                     print the instruction "pa" followed by a newline.
 *                     Do nothing if `b` is empty.
 * @note The sign change of the pushed node's goal value is on purpose,
 *       cf. documentation of p_it() !
 * @param[in, out] stack stack[A] and stack[B], respectively, are pointers to 
 *                       the first node of stack `a` and stack `b`,
 *                       respectively, if any; an empty stack is indicated by
 *                       `NULL`.
 */
void	pa (t_dl_node **stack)
{
	int			dest;
	int			ori;
	t_dl_node	*future_ori;
	
	dest = A;
	ori = B;
	if (stack[ori] == NULL)
		return ;
	future_ori = settle__estate_on_ori_stack(stack[ori]);
	if (stack[dest] == NULL)
	{
		stack[ori]->next = stack[ori];
		stack[ori]->prev = stack[ori];
	}
	else
	{
		stack[ori]->next = stack[dest];
		stack[ori]->prev = stack[dest]->prev;
		stack[ori]->next->prev = stack[ori];
		stack[ori]->prev->next = stack[ori];
	}
	stack[dest] = stack[ori];
	stack[ori] = future_ori;
	((t_ps_obj *)stack[dest]->obj)->goal *= -1;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
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