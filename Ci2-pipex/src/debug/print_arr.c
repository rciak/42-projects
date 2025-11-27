/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:28:39 by reciak            #+#    #+#             */
/*   Updated: 2025/11/26 10:50:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_arr.c
 * @brief Stores the definition of print_arr()
 */

#include "pipex.h"
#include <stdio.h>

void	print_arr(char **arr, char *prefix)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s%s\n", prefix, arr[i]);
		i++;
	}
	printf("%s%s\n", prefix, arr[i]);
}
