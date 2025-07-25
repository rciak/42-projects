/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_add_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:16:35 by reciak            #+#    #+#             */
/*   Updated: 2025/07/25 10:31:19 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_add_after
 * @brief Stores the definition of dl_lst_add_after()
 */

#include "libft.h"

/**
 * @brief Add a node after the current node of the doubly linked list
 * @note 
 * @param[in, out] \p addr_pdl_node The address of a pointer to the node after
 *                 which the new node shall be inserted.
 * @param[in] \p pnew A pointer to the to be added node
 * @note In the case of an empty list, the outer list *lst will be changed
 *       to \p pnew and thus be potentially no longer `NULL`.
 */
void	dl_lst_add_after(t_dl_node **addr_pdl_node, t_dl_node *const pnew)
{
	if (pnew == NULL)
		return ;
	if (*addr_pdl_node == NULL)
	{
		*addr_pdl_node = pnew;
		return ;
	}
	pnew->next = (*addr_pdl_node)->next;
	pnew->prev = (*addr_pdl_node);
	(*addr_pdl_node)->next = pnew;
	pnew->next->prev = pnew;
}
