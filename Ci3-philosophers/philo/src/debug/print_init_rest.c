/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:34:57 by reciak            #+#    #+#             */
/*   Updated: 2026/01/16 16:13:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include "debug.h"

static void	print_forks(t_all all);
static void	print_perm(t_all all);

void print_init_rest(t_all all)
{
	printf("\n");
	print_forks(all);
	printf("\n");
	print_perm(all);

	printf("\ndead: \n");
	if (all.dead == NO_DEAD)
		printf("  ✅ no dead philo yet\n");
	else
		printf("  ❌ dead philo: %lli\n", all.dead);

}

static void	print_forks(t_all all)
{
	long long	i;

	printf("fork ~> permission to take:\n");
	i = 0;
	while (i < all.param.num_philos)
	{
		printf("%4lld: ", i);
		if (all.fork[i].in_hand == true)
			printf("H - In hand\n");
		else
			printf("T - On table\n");
		i++;
	}
}

static void	print_perm(t_all all)
{
	long long	i;

	printf("perm:\n");
	i = 0;
	while (i < all.param.num_philos)
	{
		printf("%4lld: ", i);
		if (all.perm.pattern[i] == true)
			printf("   ✅\n");
		else
			printf("   ❌\n");
		i++;
	}
	printf("  shift: %lld\n", all.perm.shift);
	if (all.perm.go == true)
		printf("  go:    true\n");
	else
		printf("  go:    false\n");
}
