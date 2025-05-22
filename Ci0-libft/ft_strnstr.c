/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:22:42 by reciak            #+#    #+#             */
/*   Updated: 2025/05/13 11:42:17 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @brief Stores the definition of ft_strnstr
 */

#include "libft.h"

static bool	st_little_here_n_visible(const char *b, const char *l, size_t len);

/**
 * @brief Locate the first occurence of a substring in a string, where not
 *        more than \p len characters are scanned, cf.
 *        [strnstr]
 *        (https://manpages.debian.org/testing/libbsd-dev/strnstr.3bsd.en.html).
 * @warning Man page: "Since the strnstr() function is a FreeBSD specific API,
 *          it should only be used when portability is not a concern."
 * @param[in] big The string to be scanned,
 * @param[in] little The string to be found,
 * @param[in] len At most this number of character is looked at.
 * @return
 *          * big, if \p little is an empty string,
 *          * NULL, if \p big does not
 *            contain \p little in its first \p n bytes,
 *          * a pointer to the first occurence of \p little in \p big else.
 * @remark For clarification an *example* is added that extends the sample code
 *         from the man page; After saving the code in a file
 *         `tryout.c` it can be compiled and be executed via  
 *         `cc -lbsd -Werror -Wall -Wextra tryout.c -o test; ./test`  
 *         (if the bsd library stuff is installed)
   @code
	#include <stdio.h>
	#include <bsd/string.h>

	int main() {
	    const char *largestring = "Foo Bar Baz";
	    const char *smallstring = "Bar";
	    char *ptr, *ptr2, *ptr3;
	
	    ptr = strnstr(largestring, smallstring, 4);  // Not found
	    ptr2 = strnstr(largestring, smallstring, 6); // Still Not complete found
	    ptr3 = strnstr(largestring, smallstring, 7); // Found!
		
	    printf("largestring:  |%p| --> |%s|\n", largestring, largestring );
	    printf("smallstring:  |%p| --> |%s|\n", smallstring, smallstring );
	    printf("4; ptr:  |%p| --> |%s|\n", ptr, ptr );
	    printf("6; ptr2: |%p| --> |%s|\n", ptr2, ptr2);
	    printf("7; ptr3: |%p| --> |%s|\n", ptr3, ptr3);
	    return 0;
	}
   @endcode
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *) big);
	while (*big && len > 0)
	{
		if (st_little_here_n_visible(big, little, len))
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}

static bool	st_little_here_n_visible(const char *b, const char *l, size_t len)
{
	while (*l && len > 0)
	{
		if (*b != *l)
			return (false);
		b++;
		l++;
		len--;
	}
	if (*l == '\0')
		return (true);
	return (false);
}
