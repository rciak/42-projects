/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:45:57 by reciak            #+#    #+#             */
/*   Updated: 2025/05/15 12:59:08 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 * @brief Stores the definition of ft_putendl_fd
 */

#include "libft.h"

/**
 * @brief Outputs the string \p s to the specified file
 *        descriptor followed by a newline, cf. Libft Subject (Version 16.7).
 * @warning This implementation of `t_putendl_fd` calls `write` twice, i.e. more
 *          than a single time.
 *          In contrast to the implementation of `ft_putstr_fd()` where write is
 *          called only once it might happen that another suddenly 
 *          executed functions writes something between the two write calls
 *          in `ft_putendl_fd`, cf. also docu of ft_putstr_fd().
 *          
 * @param[in] s: The string to output.
 * @param[in] fd: The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
