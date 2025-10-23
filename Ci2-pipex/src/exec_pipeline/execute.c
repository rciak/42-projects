/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:18:48 by reciak            #+#    #+#             */
/*   Updated: 2025/10/23 20:27:20 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute.c
 * @brief Stores the definition of execute()
 */

#include "pipex.h"

/**
 * @brief This essentially a pimped execv including path search
 * @param[in] av The to be executed program and its parameters
 * @param[in] path
 */
void	execute(char **av, char **path)
{
	execv(av[0], av);
}
