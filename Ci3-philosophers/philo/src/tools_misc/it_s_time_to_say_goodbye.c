/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_s_time_to_say_goodbye.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:19:11 by reciak            #+#    #+#             */
/*   Updated: 2026/02/16 14:35:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file it_s_time_to_say_goodbye.c
 * @brief Stores the definition of it_s_time_to_say_goodbye()
 */

#include "philosophers.h"

/** @brief Checks if a termination condition (for the simulation) was reached */
bool	it_s_time_to_say_goodbye(t_squad_end *squad_end)
{
	bool	starved;
	int64_t	n_pasta_lovers;

	starved = get_bool(&squad_end->starved, squad_end->mutex);
	n_pasta_lovers = get_int64(&squad_end->num_pasta_lovers, squad_end->mutex);
	if (starved == true || n_pasta_lovers == 0)
	{
		return (true);
	}
	return (false);
}
