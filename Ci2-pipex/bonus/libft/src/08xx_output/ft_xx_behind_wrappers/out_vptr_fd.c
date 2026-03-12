/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_vptr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:04:45 by reciak            #+#    #+#             */
/*   Updated: 2025/09/26 10:52:51 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_vptr_fd.c
 * @brief Stores the definition of out_vptr_fd()
 */

#include "libft.h"

/**
 * @brief Outputs the address stored in \p ptr to the specified file descriptor.
 * @note **Assumption:** The program is executed on a system where an address
 *       can be stored in uintptr_t
 * @param[in] n: The integer to output.
 * @param[in] fd: The file descriptor on which to write.
 */
int	out_vptr_fd(void *ptr, int fd)
{
	uintptr_t	address;

	if (ptr == NULL)
	{
		if (write (1, "(nil)", 5) < 0)
			return (E_WRITE);
		return (5);
	}
	if (write(fd, "0x", 2) < 0)
		return (E_WRITE);
	address = (uintptr_t) ptr;
	return (2 + out_uintptr_fd(address, "0123456789abcdef", fd));
}
