/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_nbr_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:03:08 by reciak            #+#    #+#             */
/*   Updated: 2025/09/27 21:57:18 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file out_nbr_fd.c
 * @brief Stores the definition of out_nbr_fd()
 */

#include "libft.h"

/**
 * @brief Transform the integer \p nbr to a digit representation to a given
 *        base and outputs that to specified file descriptor
 * @note **Assumption:** The program is executed on a system where an int is
 *       4 bytes, i.e. 4*8 = 32 bits long, so that 
 *       INT_MIN should equal -2^31 = -2147483648
 * @param[in] nbr: The integer to output.
 * @param[in] digits: A pointer to a string containing the digits
 * @param[in] fd: The file descriptor on which to write.
 * @return
 *         * The number of bytes written, if all return values of of `write`
 *           were `>= 0`.
 *         * E_WRITE (< 0) on write Error.
 */
int	out_nbr_fd(int nbr, char *digits, int fd)
{
	int		bytes_sign;
	int		bytes_abs_val;

	if (nbr == -2147483648)
		return (write (fd, "-2147483648", 11));
	bytes_sign = 0;
	if (nbr < 0)
	{
		bytes_sign = write (fd, "-", 1);
		if (bytes_sign < 0)
			return (E_WRITE);
		nbr *= -1;
	}
	bytes_abs_val = out_unbr_fd((unsigned int) nbr, digits, fd);
	if (bytes_abs_val < 0)
		return (E_WRITE);
	return (bytes_sign + bytes_abs_val);
}
