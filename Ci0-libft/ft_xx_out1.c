/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_out1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:08:33 by reciak            #+#    #+#             */
/*   Updated: 2025/06/16 17:52:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_xx_out1.c
 * @brief Stores the definition of output functions that write to
 *        a filedescriptor. In case of a number (int or unsigned int uintptr_t)
 *        a digit set like "0123456789" or "0123456789abcdef" may be secified
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
	bytes_abs_val = out_unbr_fd((uintptr_t) nbr, digits, fd);
	if (bytes_abs_val < 0)
		return (E_WRITE);
	return (bytes_sign + bytes_abs_val);
}

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

/**
 * @brief Same as out_uintptr_fd except that the first argument is of type
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
		if (write(1, "(NULL)", 6) < 0)
			return (E_WRITE);
		return (6);
	}
	return (write(fd, str, ft_strlen(str)));
}

/**
 * @brief Outputs the address stored in \p ptr to the specified file descriptor.
 * @note **Assumption:** The program is executed on a system where an address
 *       can be stored in uintptr_t
 * @param[in] n: The integer to output.
 * @param[in] fd: The file descriptor on which to write.
 * @note Potential improvement: Call not out_unbr_fd, but a variant of it
 *       that receives not an `uintptr_t` but an `uint_ptr`.
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
	return (2 + out_unbr_fd(address, "0123456789abcdef", fd));
}
