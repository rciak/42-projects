/**
 * @file ft_strlcat.c
 * @brief Stores the definition of ft_strlcat
 */

#include "libft.h"

static void	st_finish_counting_len(size_t *plen_src, char *src);

/**
 * @brief String catentation that respects the available space in the, cf.
 *        [string_copying]
 *          (https://man7.org/linux/man-pages/man7/string_copying.7.html)
 *        and
 *        [ft_strlcat](https://man.netbsd.org/strlcpy.3).
 *
 * ft_strlcat() attaches a source string to a destination string
 * addin a nullterminator, provided that the string plus the nullterminator
 * fits in, i.e. `strlen(dest) + 1 <= size` and the to be copied string is of
 * lenght <= `size - 1 - strlen(dest)`. Otherwise the concatenation is done
 * as far as possible.
 * @note
 *       1. In the boring case `strlen(dest) + 1 == size` nothing will be done
 *          at all; in particular the string pointed to by dest will not be
 *          changed.
 *       2. In the **intersting case `strlen(dest) + 1 < size` the source
 *          string will be fully attached and a nullterminator added
 *          provided that they fit in the destination, i.e.
 *          strlen(src) <= `size - 1 - strlen(dest)`. Otherwise, i.e. if
 *          `strlen(src) > `size - 1 - strlen(dest)`, then only the first
 *          `size - 1 - strlen(dest) > 0` bytes from the source will be attached
 *          and a nullterminator added.
 *
 *          * In particular: If `size - 1 - strlen(dest) == 1` then 0 bytes
 *            from source will be attached and just a nullterminator set.
 * @remark ft_strlcat is less error prone than `ft_strncat` (cf. piscine...),
 *       e.g.
 *       * ft_strlcat guarantes that the result it nullterminated (as long
 *         as there is at least one free byte in the destination, cf. man
 *         page )
 *       * it returns not a pointer but a number that can be used to 
 *         detect if there was not enough space in dest for copying, e.g.
           @verbatim
           if (ft_strlcat(dest, src, size) == ft_strlen(src) + size)
             //oh dest not nullterminated, something must have gone wrong before
           else if (ft_strlcat(dest, src, 10) >= 10)
             //react to that unexpected happening, that dest did not have
             //enough space to append the string that src points to.
           @endverbatim
 *       * There are vulnerbility to DoS attacks, 
 *         cf. the docu for ft_strlcpy().
 *       * the concatenation has performance problems, similar to the ones of
 *         [Shlemiel the Painter]
 *         (https://www.joelonsoftware.com/2001/12/11/back-to-basics/)
 * @warning In the man page installed on 42 Vienna campus computers 
 *          (as of 10.05.2025) the desciption of the return values seems not
 *          correct, as it reads like the return value to be always
 *          `strlen(src) + strlen(dest)`, which seems to be not the case:
 *          If dest is not nullterminated then the return value seems to be 
 *          `strlen(src) + size`.
 *          This behaviour is at least mentioned in the
 *          description section of the current 
 *          [ft_strlcat](https://man.netbsd.org/strlcpy.3)
 * @param[in, out] dest pointer to the start of the memory area 
 *                      to be attached to
 * @param[in] src pointer to the start of the memory area to be read from
 * @param[in] size Number of bytes that the buffer, pointed to by dest,
 *                 can store - including the terminating null byte!
 * @return 
 *          * `ft_strlen(src) + size` in the irregular case that none of
 *             dst[0], dst[1], ..., dst[size - 1] is a nullterminator.
 *          * `ft_strlen(src) + ft_strlen(dest)` else.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ori_len_dst;
	size_t	len_src;

	ori_len_dst = 0;
	while (*dst && ori_len_dst < size)
	{
		dst++;
		ori_len_dst++;
	}
	if (*dst != '\0')
		return (ft_strlen(src) + size);
	len_src = 0;
	while (size > ori_len_dst && *src)
	{
		*dst = *src;
		dst++;
		size--;
		src++;
		len_src++;
	}
	*dst = '\0';
	st_finish_counting_len(&len_src, src)
	return (len_src + ori_len_dst);
}

static void	st_finish_counting_len(size_t *plen_src, char *src)
{
	while (*src)
	{
		(*plen_src)++;
		src++;
	}
}
