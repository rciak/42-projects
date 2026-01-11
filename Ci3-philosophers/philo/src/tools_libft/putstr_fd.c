/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:30:05 by reciak            #+#    #+#             */
/*   Updated: 2026/01/07 23:14:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file putstr_fd.c
 * @brief Stores the definition of putstr_fd()
 */

#include "philosophers.h"

/**
 * @brief Prints a string
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
ssize_t	putstr_fd(const char *str, int fd)
{
	return (write(fd, str, ft_strlen((char *) str)));
}
