/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:26:18 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:08:47 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdelone_bonus.c
 * @brief Stores the definition of ft_lstdelone()
 */

#include "libft.h"

/**
 * @brief Takes a node as parameter and frees its content
 *        using the function \p del . Frees the node itself but
 *        does NOT free the next node, cf. Libft Subject (Version 16.7).
 * @note The empty list, represented by lst == NULL, is acceptable input.
 *       In this case just nothing will happen.
 * @warning Strangly the first argument lst is not a double pointer;
 *          In contrast to ft_lstadd_front() where the caller's pointer
 *          to the first node of the linked list got addopted, this function
 *          ft_lstdelone() can not change the caller's pointer!
 * @warning Consequently the caller need to manually adjust the pointer after
 *          calling  ft_lstdelone().
 * @param[in] lst: The node to free.
 * @param[in] del: The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
