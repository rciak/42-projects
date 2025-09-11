/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_add_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:46:54 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 13:06:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_add_before.c
 * @brief Stores the definition of dl_lst_add_before()
 */

 #include "libft.h"

/**
 * @brief Add a node before the current node of the doubly linked list
 * @param[in, out] \p addr_pdl_node The address of a pointer to the node before
 *                 which the new node shall be inserted.
 * @param[in] \p pnew A pointer to the to be added node
 * @note In the case of an empty list, the outer list *lst will be changed
 *       to \p pnew and thus be potentially no longer `NULL`.
 * @warning **Test Status:** not unit tested.
 */

void	dl_lst_add_before(t_dl_node **addr_pdl_node, t_dl_node *const pnew)
{
	if (pnew == NULL)
		return ;
	if (*addr_pdl_node == NULL)
	{
		*addr_pdl_node = pnew;
		return ;
	}
	pnew->prev = (*addr_pdl_node)->prev;
	pnew->next = (*addr_pdl_node);
	(*addr_pdl_node)->prev = pnew;
	if (pnew->prev != NULL)
		pnew->prev->next = pnew;
}