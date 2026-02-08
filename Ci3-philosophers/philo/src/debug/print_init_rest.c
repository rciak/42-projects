/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:34:57 by reciak            #+#    #+#             */
/*   Updated: 2026/02/08 11:25:39 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include "debug.h"

static void	print_forks(t_phi phi);
static void	print_perm(t_phi phi);

void print_init_rest(t_phi phi)
{
	printf("\n");
	print_forks(phi);
	printf("\n");
	print_perm(phi);

	printf("\ndead: \n");
	if (phi.dead == NO_DEAD)
		printf("  ✅ no dead philo yet\n");
	else
		printf("  ❌ dead philo: %lli\n", phi.dead);

}

static void	print_forks(t_phi phi)
{
	long long	i;

	printf("fork ~> permission to take:\n");
	i = 0;
	while (i < phi.param.num_philos)
	{
		printf("%4lld: ", i);
		if (phi.fork[i].in_hand == true)
			printf("H - In hand\n");
		else
			printf("T - On table\n");
		i++;
	}
}

static void	print_perm(t_phi phi)
{
	long long	i;

	printf("perm:\n");
	i = 0;
	while (i < phi.param.num_philos)
	{
		printf("%4lld: ", i);
		if (phi.perm.pattern[i] == true)
			printf("   ✅\n");
		else
			printf("   ❌\n");
		i++;
	}
	printf("  shift: %lld\n", phi.perm.shift);
	if (phi.perm.go == true)
		printf("  go:    true\n");
	else
		printf("  go:    false\n");
}
