/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsed_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:22:14 by reciak            #+#    #+#             */
/*   Updated: 2026/02/22 18:20:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	print_parsed_args(t_param param)
{
	printf("Parsed arguments:\n");
	printf("  Number of philosophers: %ld\n", param.num_philos);
	printf("  Time to die (ms):       %ld\n", param.tt.die);
	printf("  Time to eat (ms):       %ld\n", param.tt.eat);
	printf("  Time to sleep (ms):     %ld\n", param.tt.sleep);
	if (param.meals_at_least == OMITTED_PARAM)
		printf("  Max number of meals:    unlimited\n");
	else
		printf("  Max number of meals:    %ld\n", param.meals_at_least);
}
