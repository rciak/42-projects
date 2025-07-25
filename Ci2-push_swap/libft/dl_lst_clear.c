/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:47:42 by reciak            #+#    #+#             */
/*   Updated: 2025/07/25 11:49:05 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_clear.c
 * @brief Stores the definition of dl_lst_clear()
 */

#include "libft.h"

void	st_clear_nonempty_linear(t_dl_node **addr_pdl_node, void (*del)(void*));

/**
 * @brief Clear a doubly linked list, no matter if it linear or circular.
 *        Finally, the pointer to the list is set to `NULL`.
 * @param[in, out] pdl_node The address of a pointer to any node of the 
 *                         doubly linked list.
 * @param[in] del The address of the function used to delete
 *                the object belonging to the node.
 * @warning This function should be called only on "normal" doubly linked list
 *          such that two different nodes never contain the same address to the 
 *          same object!
 * @warning **Test Status:** not unit tested,
 *          circular case indirectly tested via push_swap_project.
 */
void	dl_lst_clear(t_dl_node **addr_pdl_node, void (*del)(void*))
{
	t_dl_type type;

	type = dl_lst_type(*addr_pdl_node);
	if (type == DL_EMPTY)
		return ;
	if (type == DL_NON_EMPTY_CIRCULAR)
		dl_lst_linearize(*addr_pdl_node);
	st_clear_nonempty_linear(addr_pdl_node, del);
}

void	st_clear_nonempty_linear(t_dl_node **addr_pdl_node, void (*del)(void*))
{
	t_dl_node	*soon_gone;

	while ((*addr_pdl_node)->prev != NULL)
		*addr_pdl_node = (*addr_pdl_node)->prev;
	while (*addr_pdl_node != NULL)
	{
		soon_gone = *addr_pdl_node;
		*addr_pdl_node = (*addr_pdl_node)->next;
		del (soon_gone->obj);
		free(soon_gone);
	}
}
