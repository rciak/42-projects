/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:05:55 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:08:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstclear_bonus.c
 * @brief Stores the definition of ft_lstclear()
 */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and all its
 *        successors, using the function `del` and free(3).
 *        Finally, set the pointer to the list to `NULL`,
 *        cf. Libft Subject (Version 16.7).
 * @param[in, out] lst: The address of a pointer to a node.
 * @param[in] del: The address of the function used to delete
 *                 the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*soon_gone;

	while (*lst)
	{
		soon_gone = *lst;
		*lst = (*lst)->next;
		del(soon_gone->content);
		free (soon_gone);
	}
}
