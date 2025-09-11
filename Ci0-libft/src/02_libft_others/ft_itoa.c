/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:37:46 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 08:44:23 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @brief Stores the definition of ft_itoa
 */

#include "libft.h"

static size_t	st_num_digits(int n);
static void		st_number_to_string(int n, size_t num_digits, char *str);

/**
 * @brief Allocates memory (using malloc(3)) and returns a string representing
 *        the integer received as an argument. Negative numbers must be handled,
 *        cf. Libft Subject (Version 16.7).
 * @param[in] n: The integer to convert.
 * @return 
 *          * The string representing the integer.
 *          * `NULL` on error.
 */

char	*ft_itoa(int n)
{
	size_t	num_digits;
	size_t	num_bytes;
	char	*str;

	num_digits = st_num_digits(n);
	num_bytes = 0;
	if (n < 0)
		num_bytes += 1;
	num_bytes += num_digits + 1;
	str = calloc_uninit(1, num_bytes);
	if (str == NULL)
		return (NULL);
	st_number_to_string(n, num_digits, str);
	return (str);
}

/**
 * @brief Caluclates the number of digits of a number when it is represented
 *        in decimal system.
 * @note Although this is only a static function I would like to document it
 *       for a particular reason:
 *       This implementations relies (for negative n) heavily on C choice of
 *       defining the modulo operator in the symmetric variant, c.f.
 *       [wiki_modulo]
 *       (https://en.wikipedia.org/w/index.php?title=Modulo&oldid=1286945142)
 *       and the 
 *       [notes](https://github.com/rciak/42-projects/wiki/Ci0%E2%80%90libft) 
 *       to this libft project.
 * @param[in] n The number to investigate.
 * @return
 *          * The calculated number of digits.
 */
static size_t	st_num_digits(int n)
{
	size_t	num_digits;
	int		remainder;

	num_digits = 0;
	if (n == 0)
		num_digits = 1;
	while (n != 0)
	{
		remainder = n % 10;
		n = (n - remainder) / 10;
		num_digits += 1;
	}
	return (num_digits);
}

static void	st_number_to_string(int n, size_t num_digits, char *str)
{
	int		remainder;

	if (n < 0)
	{
		str[0] = '-';
		str++;
	}
	str[num_digits] = '\0';
	while (num_digits > 0)
	{
		remainder = n % 10;
		str[num_digits - 1] = abs(remainder) + '0';
		n = (n - remainder) / 10;
		num_digits--;
	}
}
