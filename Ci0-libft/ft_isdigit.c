/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:28:33 by reciak            #+#    #+#             */
/*   Updated: 2025/05/04 18:40:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @brief Stores the definition of ft_isdigit
 */

 #include "libft.h"

/**
 * @brief Checks if a character is a digit, cf.
 * [isdigit](https://man7.org/linux/man-pages/man3/isdigit.3.html).
 * @note Cf. also ft_isalpha()
 * @param[in] c The character to be checked (value 0-127) or EOF
 * @return 
 *          * 1 if \p c does represents a digit character,
 *          * 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (('0' <= c && c <= '9'));
}
/*
int main(int argc, char **argv)
{
	int c;

	if (argc != 1 && argc != 1 + 1)
		return (-1);

	if (argc == 1 + 1)
	{
		c = (int) argv[1][0];
		printf("c: %d\n", c);
		printf("(char)c: %c\n", (char)c);
		printf("ft_isdigit(%d): %d\n", c, ft_isdigit(c));
		printf("isdigit(%d): %d\n", c, isdigit(c));
		return (0);
	}
	
	printf("ft_isdigit('0'): %d\n", ft_isdigit('0'));
	printf("ft_isdigit(0xF6): %d\n", ft_isdigit(0xF6));
	printf("ft_isdigit(EOF): %d\n", ft_isdigit(EOF));
	printf("isdigit('0'): %d\n", isdigit('0'));
	printf("isdigit(0xF6): %d\n", isdigit(0xF6));
	printf("isdigit(EOF): %d\n", isdigit(EOF));
	return (0);
}
*/

