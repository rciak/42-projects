/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:35:13 by reciak            #+#    #+#             */
/*   Updated: 2025/05/19 15:04:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @brief Stores the definition of ft_putnbr_fd
 */

#include "libft.h"

/**
 * @brief Outputs the integer \p n to the specified file
 *        descriptor, cf. Libft Subject (Version 16.7).
 * @note **Assumption:** The program is executed on a system where an int is
 *       4 bytes, i.e. 4*8 = 32 bits long, so that 
 *       INT_MIN should equal -2^31 = -2147483648
 * @param[in] n: The integer to output.
 * @param[in] fd: The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (0 <= n && n <= 9)
	{
		digit = (char)(n + '9' - '0');
		write (fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
