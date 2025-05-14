/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:45:43 by reciak            #+#    #+#             */
/*   Updated: 2025/05/14 22:10:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file t_putchar_fd.c
 * @brief Stores the definition of t_putchar_fd
 */

#include "libft.h"

/**
 * @brief Outputs the character stored in \p c to the specified file
 *        descriptor, cf. Libft Subject (Version 16.7).
 * @param[in] c: The character to output.
 * @param[in] fd: The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd)
{
	(void) write (fd, &c, 1);
}
