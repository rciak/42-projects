/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:06 by reciak            #+#    #+#             */
/*   Updated: 2025/07/23 12:04:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_err		err;
	t_dl_node	*stack[2];

	err = error(ERR_NONE);
	stack[A] = NULL;
	stack[B] = NULL;
	if (!st_parse_n_init(argc, argv, &stack, &err))
		return (err.code);
	if (ring_len(stack[A]) <= MAX_SIZE_HANDSORT)
		small_size_algo(&stack, &err);
	else
		big_size_algo(&stack, &err);
	if (err.code != ERR_NONE)
		print_error(err);
	clear_ring(stack[A]);
	clear_ring(stack[B]);
	return (ERR_NONE);
}
