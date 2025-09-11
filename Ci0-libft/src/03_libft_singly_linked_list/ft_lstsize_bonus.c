/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:20:58 by reciak            #+#    #+#             */
/*   Updated: 2025/05/26 07:58:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize_bonus.c
 * @brief Stores the definition of ft_lstsize
 */

#include "libft.h"

/**
 * @brief Counts the number of nodes in the list,
 *        cf. Libft Subject (Version 16.7).
 * @remark It would way more natural to have a return type that is not signed...
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
