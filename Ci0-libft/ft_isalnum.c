/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:42:46 by reciak            #+#    #+#             */
/*   Updated: 2025/05/02 19:29:15 by reciak           ###   ########.fr       */
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

	if (c == EOF)
		return (false);
	uc = (unsigned char) c;
	if ('a' <= uc && uc <= 'z')
		return (true);
	if ('A' <= uc && uc <= 'Z')
		return (true);
	if ('0' <= uc && uc <= '9')
		return (true);
	return (false);
}