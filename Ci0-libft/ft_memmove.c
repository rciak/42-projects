/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:57 by reciak            #+#    #+#             */
/*   Updated: 2025/05/11 22:01:28 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @brief Stores the definition of ft_memmove
 */

#include "libft.h"

/**
 * @brief Copies n bytes from src to dest, cf.
 *        [memmove](https://man7.org/linux/man-pages/man3/memmove.3.html)
 * @note In contrast to memcpy() the copying over still work when the
 *       memory areas do overlap but it is slower than ft_memmove,
 *       since it needs if statements.
 * @warning Still both memory areas should have a length of at least n bytes.
 * @param[in, out] dest pointer to the start of the memory area to be written to
 * @param[in] src pointer to the start of the memory area to be read from
 * @return dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_uchar			*uc_dest;
	const t_uchar	*uc_src = (t_uchar *) src;
	size_t			step;

	if (n == 0)
		return (dest);
	uc_dest = (t_uchar *) dest;
	if (dest < src)
		step = +1;
	else if (dest > src)
	{
		uc_dest += (n - 1);
		uc_src += (n - 1);
		step = -1;
	}
	else
		return (dest);
	while (n > 0)
	{
		*uc_dest = *uc_src;
		uc_dest += step;
		uc_src += step;
		n--;
	}
	return (dest);
}
