/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:03:34 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 10:51:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_str_fd.c
 * @brief Stores the definition of out_str_fd()
 */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the specified file
 *        descriptor.
 * @param[in] s: The string to output.
 * @param[in] fd: The file descriptor on which to write.
 * @return What the call of writes returns:
 *         * the number of bytes written, or
 *         * -1 on error.
 */
int	out_str_fd(char *str, int fd)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (E_WRITE);
		return (6);
	}
	return (write(fd, str, ft_strlen(str)));
}
