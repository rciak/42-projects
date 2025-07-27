/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 08:46:55 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static bool	args__ok(int argc, char **argv, t_err *err);
static bool init__stacks(int argc, char **argv, t_dl_node *stack, t_err *err);

int	main(int argc, char **argv)
{
	t_err		err;
	t_dl_node	*stack[2];

	err = error(ERR_NONE);
	if (!args__ok(argc, argv, &err)|| !init__stacks(argc, argv, &stack, &err))
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

static bool	args__ok(int argc, char **argv, t_err *err)
{
	int	i;

	if (argc < 1 + 1)
		return (*err = error(ERR_ARG_NUM), false);
	i = 0;
	while (i < argc)
	{
		if (does_not_contain)
		i++;
	}
	return (true);
}

static bool init__stacks(int argc, char **argv, t_dl_node **stack, t_err *err)
{
	int	i;

	stack[A] = NULL;
	stack[B] = NULL;
	i = 0;
	while (i < argc)

}
