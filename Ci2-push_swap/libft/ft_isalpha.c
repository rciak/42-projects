/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:42:01 by reciak            #+#    #+#             */
/*   Updated: 2025/05/25 13:30:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalpha.c
 * @brief Stores the definition of ft_isalpha
 */

#include "libft.h"

/**
 * @brief Checks if a character is a letter, cf.
 *        [isalpha](https://man7.org/linux/man-pages/man3/isalpha.3.html).
 * @note We assume that the **C locale** is used,
 *       when calling ft_isalpha() i.e.
 *       that only the letters `a-z` and `A-Z` in the ASCII table 
 *       (range 0...127) shall cause return 1 (true), while all other 
 *       values of c shall cause return 0 (false).
 * @note 
 *       If the code would be compiled/run with *legacy locales* like
 *       *ISO/IEC 8859-1 (Latin-1)*,
 *       e.g. ft_isalpha(255) will still return 0 (false), 
 *       even though 255 represents the letter ÿ in the ISO/IEC 8859-1 encoding,
 *       so that the original function isalpha(255) 
 *       probably will return something != 0 (true) !!!
 *       But non the less one can reason that the subject is still fullfilled:
 *       According to the man page 
 *       `c` is expected to be either in the range 0...127 or equal to EOF
 *       (a negative integer - in most implementations choosen as -1).
 *       As long as ft_isalpha(c) and isalpha(c) both return 0 resp. nonzero 
 *       for these values of `c` alike
 *       everything is ok. 
 *       (Differences in other cases can be viewed as caused 
 *       by **undefined behaviour**.)
 * @note If the used locale relies on the nowadays dominating UTF-8
 *       it is to be assumed that most implemtations of isalpha(c) and 
 *       ft_isalpha(c) have acutually the same behaviour:
 *       In UTF-8 it is only the 
 *       ASCII-characters (range 0...127) that can
 *       to be represeneted as 1 byte long Unicode characters but no other
 *       characters (all other characters take 2, 3 or 4 bytes in UTF-8).
 * @note Even on the 42-Campus Computers isalpha seems to returns 0 (false) or 
 *       1024 (true), whereas ft_isalpha returns in the latter case 1 
 *       which represents also "true".
 * @param[in] c The character to be checked; value 0...127 or `EOF` is assumed.
 * @return 
 *          * 1 if \p c does represents an (ASCII) letter,
 *          * 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
/*
#include <stdio.h>  // EOF
#include <ctype.h>  // isalpha
#include <locale.h>
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
		printf("ft_isalpha(%d): %d\n", c, ft_isalpha(c));
		printf("isalpha(%d): %d\n", c, isalpha(c));
		return (0);
	}
	
	//Not installed anymore in times of UTF-8
    //if (setlocale(LC_ALL, "en_US.ISO-8859-1") == NULL) {
    //    printf("Locale not available!\n");
    //    return 1;
    //}
    printf("Locale currently is: %s\n", setlocale(LC_ALL, NULL));
    
	printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
	printf("ft_isalpha(0xF6): %d\n", ft_isalpha(0xF6));
	printf("ft_isalpha(','): %d\n", ft_isalpha(','));
	printf("ft_isalpha(EOF): %d\n", ft_isalpha(EOF));

	printf("isalpha('a'): %d\n", isalpha('a'));
	printf("isalpha(0xF6): %d\n", isalpha(0xF6));
	printf("isalpha(','): %d\n", isalpha(','));
	printf("isalpha(EOF): %d\n", isalpha(EOF));

	return (0);
}
*/
