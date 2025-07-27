/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 13:21:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static bool	init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err);
static bool	is__duplicate(int nbr, t_dl_node *stack_a);
static bool	add__to_stack_a(int nbr, t_dl_node *stack_a);

int	main(int argc, char **argv)
{
	t_err		err;
	t_dl_node	*stack[2];

	err = error(ERR_NONE);
	if (!init__stacks(argc, argv, stack, &err))
		return (handle_error(err), err.code);
	if (ring_len(stack[A]) <= MAX_SIZE_HANDSORT)
		small_size_algo(&stack, &err);
	else
		big_size_algo(&stack, &err);
	if (err.code != ERR_NONE)
		print_error(err);
	dl_lst_clear(stack[A]);
	dl_lst_clear(stack[B]);
	return (ERR_NONE);
}

static bool init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err)
{
	t_libft_err	atoi_code;
	int nbr;
	int	i;
	t_ps_obj *obj;

	if (argc < 1 + 1)
		return (*err = error(ERR_ARG_NUM), false);
	stack[A] = NULL;
	stack[B] = NULL;
	i = 0;
	while (i < argc)
	{
		nbr = atoi_proper(argv[i], &atoi_code);
		if (atoi_code == E_ATOI_BAD_STRING || atoi_code == E_ATOI_RANGE)
			return (*err = error(ERR_ARGV), false);
		if (is__duplicate(nbr, stack[A]))
			return (*err = error(ERR_DUPLICATE), false);
		if (!add__to_stack_a(nbr, stack[A]))
			return (*err  = error(ERR_MALLOC), false);
		i++;
	}
	dl_lst_circularize(stack[A]);
	return (true);
}

static bool is__duplicate(int nbr, t_dl_node *node)
{
	while (node != NULL)
	{
		if (nbr == ((t_ps_obj *)node->obj)->n)
			return (true);
		node = node->next;
	}
	return (false);
}
static bool	add__to_stack_a(int nbr, t_dl_node *stack_a)
{
	t_ps_obj	*obj;
	t_dl_node		*node;

	dl_lst_circularize(stack_a);
	obj = malloc(sizeof(t_ps_obj));
	if (obj == NULL)
		return (false);
	node = dl_lst_new_nd(obj);
	if (node == NULL)
	{
		free (obj);
		dl_lst_clear(&stack_a, free);
		return (false);
	}
	dl_lst_add_before(&stack_a, node);
	dl_lst_linearize(stack_a);
}

