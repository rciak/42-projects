/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:33:42 by reciak            #+#    #+#             */
/*   Updated: 2025/10/05 17:39:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hello.c
 * @brief Stores the definition of hello()
 */

#include "pipex.h"

/**
 * @brief Prints "Hello World!" followed by a newline.
 * @note Here comes a relevant note to point out
 */
void	hello(void)
{
	write(STDOUT_FILENO, "Hello World!\n\n", 15);
}
