/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:20:58 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 14:35:21 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize.c
 * @brief Stores the definition of ft_lstsize
 */

#include "libft.h"

/**
 * @brief Counts the number of nodes in the list,
 *        cf. Libft Subject (Version 16.7).
 * @param[in] lst: The beginning of the list, i.e. a pointer to its first node.
 * @return The length of the list, i.e. its number of nodes.
 */
int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

