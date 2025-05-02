/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:43:09 by reciak            #+#    #+#             */
/*   Updated: 2025/04/29 16:49:56 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>  // EOF

// Regarding locale the following is assumed: 
// unsigned char values between 128 and 255 are ignored
//
// false / true will be implicitely converted to an int
int ft_isalnum(int c)
{
	unsigned char uc;

	if (0 <= c && c <= 127)
		return (true);
	return (false);
}