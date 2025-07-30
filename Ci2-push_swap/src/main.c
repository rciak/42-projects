/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/30 09:02:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>
#include "/home/reciak/github/42-projects/Ci2-push_swap/42-eva-lua/Ci2-push_swap-crtests/manual-test.h" 

static bool	init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err);
static bool	is__duplicate(int nbr, t_dl_node *stack_a);
static bool	add__to_stack_a(int nbr, t_dl_node **stack_a);
static void	init__other_vars(t_dl_node *stack_a, int argc);

/**
 * @note For practical sizes of input the program should work.
 *       Analysis of the code shows that it will fail if at least`-INT_MIN`
 *       parameters arre given - but being typically  2 147 483 648
 *       this is many order of magnitudes beyond the scope of the project...
 */
int	main(int argc, char **argv)
{
	t_err		err;
	t_dl_node	*stack[2];

	err = error(ERR_NONE);
	stack[A] = NULL;
	stack[B] = NULL;
	if (!init__stacks(argc, argv, stack, &err))
		return (handle_error(err), err.code);
	if (group_already_sorted(stack[A]))
		return (ERR_NONE);
/*
	if (group_size(stack[A]) <= MAX_SIZE_DIRECT_SORT)
		small_size_algo(stack);
	else
		big_size_algo(stack);
*/
dl_lst_linearize(stack[A]); print_stacks(stack);
return (ERR_NONE);
	dl_lst_clear(&stack[A], free);
	dl_lst_clear(&stack[B], free);
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
		if (!add__to_stack_a(nbr, &stack[A]))
			return (*err  = error(ERR_MALLOC), false);
		i++;
	}
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
		obj->group.starts = false;
		obj->group.ends = false;
		if (node ->next != NULL)
			node = node->next;
		i++;
	}
	((t_ps_obj*)stack_a->obj)->group.starts = true;
	((t_ps_obj*)node->obj)->group.ends = true;
	update_group(stack_a);
	while (i-- > 1)
	{
		obj = (t_ps_obj *)node->obj;
		obj->goal = obj->group.rank;
		node=node->prev;
	}
}

