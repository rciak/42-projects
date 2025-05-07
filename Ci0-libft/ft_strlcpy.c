/**
 * @file ft_strlcpy.c
 * @brief Stores the definition of ft_strlcpy
 */

#include "libft.h"

/**
 * @brief String copying that respects the available space in the destination,
 *        cf.
 *        [strlcpy](https://man7.org/linux/man-pages/man3/strlcpy.html).
 *
 * ft_strlcpy() copies a string from src to dest adding a nullterminator,
 * provided that the string plus the nullterminator fits in,
 * i.e. the string is of length <= `size-1`. If though its length is
 * >= `size` then 
 * copying will be done as far as possible, i.e.
 * only `size-1` bytes are copied; also a nullteminator
 * will be added provided that `size` > 0).
 *        
 * @note 
 *       1. In the boring case `size` == 0 nothing will be done at all;
 *          in particular the string pointed to by dest will not be changed.
 *       2. In the **interesting case `size` > 0** the original string 
 *          will be fully copied and a nullterminator 
 *          added provided that they fit in the destination, 
 *          i.e. the string to be copied is of
 *          length <= `size-1`. Otherwise, i.e. if 
 *          length >= `size` > 0 then `size-1 >= 0` bytes will be copied
 *          and a nullterminator added.
 *
 *          * In particular: If `size == 1` then 0 bytes will be copied and just
 *            a nullterminator set, resulting in an *empty string*.
 * @remark ft_strlcpy is less error prone than `ft_strncpy` (cf. piscine...),
 *       e.g. 
 *       * ft_strlcpy guarantes that the result is nullterminated
 *         (as long as `size > 0`)
 *       * it returns not a pointer but a number that can be used to 
 *         detect if there was not enough space in dest for copying, e.g.
           @verbatim
               
           if (ft_strlcpy(dest, src, 10) > 10 + 1)
             //react to that unexpected happening.
               
           @endverbatim
           @code
               
           if (ft_strlcpy(dest, src, 10) > 10 + 1)
             //react to that unexpected happening.
               
           @endcode
 
 *
 * @param[in, out] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @return The length of the original string pointed to by `src`, i.e. the 
 *         length of the string that was intended to be created.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0
	while (i < size - 1)
	{

		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (ft_strlen(src));
}