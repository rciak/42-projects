/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_allows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:58:28 by reciak            #+#    #+#             */
/*   Updated: 2026/02/20 12:09:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include "debug.h"

void print_allows(bool *allows, int64_t n)
{
	int64_t	i;

	i = 0;
	while (i < n)
	{
		printf(   YELLOW"maestro: allows[-1+%li]: %i"RESET"\n", i+1, allows[i]);
		i++;
	}
}