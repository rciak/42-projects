/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 22:48:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static bool	init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err);
static bool	is__duplicate(int nbr, t_dl_node *stack_a);
static bool	add__to_stack_a(int nbr, t_dl_node **stack_a);
static void	init__other_vars(t_dl_node *stack_a, int argc);

int	main(int argc, char **argv)
{
	t_err		err;
	t_dl_node	*stack[2];

	err = error(ERR_NONE);
	stack[A] = NULL;
	stack[B] = NULL;
	if (!init__stacks(argc, argv, (t_dl_node **)&stack, &err))
		return (handle_error(err), err.code);
//print_stacks(stack);
/*	
//TODO: if (group_already_sorted)...
//
	if (ring_len(stack[A]) <= MAX_SIZE_HANDSORT)
		small_size_algo(&stack, &err);
	else
		big_size_algo(&stack, &err);
	if (err.code != ERR_NONE)
		print_error(err);
*/
	dl_lst_clear(&stack[A], free);
	dl_lst_clear(&stack[B], free);
//print_stacks(stack);
	return (ERR_NONE);
}

static bool init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err)
{
	t_libft_err	atoi_code;
	int nbr;
	int	i;

	if (argc < 1 + 1)
		return (*err = error(ERR_ARG_NUM), false);
	i = 1;
	while (i < argc)
	{
		nbr = atoi_proper(argv[i], &atoi_code);
		if (atoi_code == E_ATOI_BAD_STRING || atoi_code == E_ATOI_RANGE)
			return (*err = error(ERR_ARGV), false);
		if (is__duplicate(nbr, stack[A]))
			return (*err = error(ERR_DUPLICATE), false);
		if (!add__to_stack_a(nbr, (t_dl_node **)&stack[A]))
			return (*err  = error(ERR_MALLOC), false);
		i++;
	}
print_stacks(stack);	
	init__other_vars(stack[A], argc);
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
static bool	add__to_stack_a(int nbr, t_dl_node **stack_a)
{
	t_ps_obj	*obj;
	t_dl_node	*node;

	dl_lst_circularize(*stack_a);
	obj = malloc(sizeof(t_ps_obj));
	if (obj == NULL)
		return (false);
	node = dl_lst_new_nd(obj);
	if (node == NULL)
	{
		free (obj);
		dl_lst_clear(stack_a, free);
		return (false);
	}
	((t_ps_obj*)node->obj)->n = nbr;
	dl_lst_add_before(stack_a, node);
	dl_lst_linearize(*stack_a);
	return (true);
}

static void	init__other_vars(t_dl_node *stack_a, int argc)
{
	t_dl_node	*node;
	t_ps_obj	*obj;
	int			i;

	node = stack_a;
	i = 1;
	while (i < argc)
	{
		obj = (t_ps_obj *)node->obj;
		obj->is_green = false;
		if (i == 1)
			obj->group.starts = true;
		else
			obj->group.starts = false;
		if (i == argc - 1)
			obj->group.ends = true;
		else
			obj->group.ends = false;		
		node = node->next;
		i++;
	}
	update_group(stack_a);
}

