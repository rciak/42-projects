/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_uintptr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:04:21 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 10:51:16 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_uintptr_fd.c
 * @brief Stores the definition of out_uintptr_fd()
 */

#include "libft.h"

/**
 * @brief Same as out_unbr_fd() except that the first argument is of type
 *        uintptr_t (instead of unsigned int)
 */
int	out_uintptr_fd(uintptr_t unbr, char *digits, int fd)
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
		new_bytes = out_uintptr_fd(unbr / base, digits, fd);
		if (new_bytes < 0)
			return (E_WRITE);
		bytes_total += new_bytes;
		new_bytes = out_uintptr_fd(unbr % base, digits, fd);
		if (new_bytes < 0)
			return (E_WRITE);
		bytes_total += new_bytes;
		return (bytes_total);
	}
}
