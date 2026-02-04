/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsed_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:22:14 by reciak            #+#    #+#             */
/*   Updated: 2026/02/04 10:36:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	print_parsed_args(t_param param)
{
	printf("Parsed arguments:\n");
	printf("  Number of philosophers: %lld\n", param.num_philos);
	printf("  Time to die (ms):       %lld\n", param.tt_die);
	printf("  Time to eat (ms):       %lld\n", param.tt_eat);
	printf("  Time to sleep (ms):     %lld\n", param.tt_sleep);
	if (param.meals_at_least == -1)
		printf("  Max number of meals:    unlimited\n");
	else
		printf("  Max number of meals:    %lld\n", param.meals_at_least);
}