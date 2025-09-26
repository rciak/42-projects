/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_unbr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:04:32 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 10:51:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_unbr_fd.c
 * @brief Stores the definition of out_unbr_fd()
 */

#include "libft.h"

/**
 * @brief Transform the unsigned integer \p unbr to a digit representation
 *        to a given base and outputs that to specified file descriptor.
 * @param[in] unbr: The unsigned integer to output.
 * @param[in] digits: A pointer to a string containing the digits.
 * @param[in] fd: The file descriptor on which to write.
 * @return
 *         * The number of bytes written, if all return values of `write`
 *           were `>= 0`.
 *         * E_WRITE on write Error.
 * @note Potential optimization: Avoid calling ft_strlen repeatedly.
 *       (Probably faster than the current version, but also more complex)
 */
int	out_unbr_fd(unsigned int unbr, char *digits, int fd)
{
	int		new_bytes;
	int		bytes_total;
	size_t	base;

	base = ft_strlen(digits);
	bytes_total = 0;
	if (unbr < base)
	{
		new_bytes = write(fd, &digits[unbr], 1);
		if (new_bytes < 0)
			return (E_WRITE);
		return (new_bytes);
	}
	else
	{
		new_bytes = out_unbr_fd(unbr / base, digits, fd);
		if (new_bytes < 0)
			return (E_WRITE);
		bytes_total += new_bytes;
		new_bytes = out_unbr_fd(unbr % base, digits, fd);
		if (new_bytes < 0)
			return (E_WRITE);
		bytes_total += new_bytes;
		return (bytes_total);
	}
}
