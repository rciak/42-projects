/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_out2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:12:02 by reciak            #+#    #+#             */
/*   Updated: 2025/06/17 08:52:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_xx_out2.c
 * @brief Stores the definition of convenience wrappers from the 
 *        output functions in ft_xx_out1.c that write to
 *        stdout. In case of a number (int, unsigned int or uintptr_t)
 *        a digit set like "0123456789" or "0123456789abcdef" may be secified
 */

#include "libft.h"

/**
 * @brief Convenience wrapper for out_nbr_fd() when the output goes to stdout.
 */
int	out_nbr(int nbr, char *digits)
{
	return (out_nbr_fd(nbr, digits, STDOUT_FILENO));
}

/**
 * @brief Convenience wrapper for out_unbr_fd() when the output goes to stdout.
 */
int	out_unbr(unsigned int nbr, char *digits)
{
	return (out_unbr_fd(nbr, digits, STDOUT_FILENO));
}

/**
 * @brief Convenience wrapper for out_uintptr_fd()
 *        when the output goes to stdout.
 */
int	out_uintptr(uintptr_t unbr, char *digits)
{
	return (out_uintptr_fd(unbr, digits, STDOUT_FILENO));
}

/**
 * @brief Convenience wrapper for out_str_fd() when the output goes to stdout.
 */
int	out_str(char *str)
{
	return (out_str_fd(str, STDOUT_FILENO));
}

/**
 * @brief Convenience wrapper for out_vptr_fd() when the output goes to stdout.
 */
int	out_vptr(void *ptr)
{
	return (out_vptr_fd(ptr, STDOUT_FILENO));
}
