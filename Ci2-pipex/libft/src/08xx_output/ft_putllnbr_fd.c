/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:39:24 by reciak            #+#    #+#             */
/*   Updated: 2025/08/28 15:25:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putllnbr_fd.c
 * @brief Stores the definition of ft_putllnbr_fd()
 */

#include "libft.h"

/**
 * @brief Outputs the long long \p n to the specified file
 *        descriptor.
 * @note **Assumption:** The program is executed on a system where an int is
 *       4 bytes, i.e. 8*8 = 64 bits long, so that the minimal possible value
 *       for a long long should equal -2^63 = -9223372036854775808 
 * @note This code is essentially the same as ft_putnbr_fd.
 * @note The original first check, being  n == -9223372036854775808 
 *       caused issues; it seems that clang parses this as 
 *       (-1) * 9223372036854775808, causing an overflow issue;
 *       In contrast the check
 *         n == -9223372036854775807 - 1
 *       avoids that issue. It seems like 
 *              -9223372036854775807 is probably likewise parsed as
 *       (-1) * 9223372036854775808 and then stored and only then 1 substracted.
 * @param[in] n: The long long integer to output.
 * @param[in] fd: The file descriptor on which to write.
 */
void	ft_putllnbr_fd(long long n, int fd)
{
	char	digit;

	if (n == -9223372036854775807 - 1)
	{
		write (fd, "-9223372036854775808", 20);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (0 <= n && n <= 9)
	{
		digit = (char)(n + '0');
		write (fd, &digit, 1);
	}
	else
	{
		ft_putllnbr_fd(n / 10, fd);
		ft_putllnbr_fd(n % 10, fd);
	}
}
