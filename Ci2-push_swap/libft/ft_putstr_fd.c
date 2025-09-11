/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:55:30 by reciak            #+#    #+#             */
/*   Updated: 2025/05/14 22:13:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @brief Stores the definition of ft_putstr_fd
 */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the specified file
 *        descriptor, cf. Libft Subject (Version 16.7).
 * @note The implementation of `ft_putstr_fd` is done in a way that the `write`
 *        function is called only once.
 *        This should have the following advantages
 *        compared to calling `write` for each single individual byte:
 *        * It should be faster (not tested though, but feels very likely)
 *        * Printing to stdout or to a file with a single
 *          call of write ensures that no other suddenly executed function
 *          (e.g. a function that shall be executed as reaction to a mouseclick)
 *          can interfere and print something inbetween: The currently active
 *          write will not be interrupted.
 * @param[in] s: The string to output.
 * @param[in] fd: The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd)
{
	(void) write(fd, s, ft_strlen(s));
}
