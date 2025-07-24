/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_add_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:16:35 by reciak            #+#    #+#             */
/*   Updated: 2025/07/24 19:17:48 by reciak           ###   ########.fr       */
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
 * @param[in, out] \p *dl_lst The caller's doubly linked list
 * @param[in] \p pnew A pointer to the to be added node
 * @note In the case of an empty list, the outer list *lst will be changed
 *       to \p pnew and thus be potentially no longer `NULL`.
 */
void	dl_lst_add_after(t_dl_node **dl_lst, t_dl_node *const pnew)
{
	if (*p_new == NULL)
		return ;
	if (*dl_lst == NULL)
	{
		*dl_lst = new;
		return ;
	}
	pnew->next = (*dl_lst)->next;
	pnew->prev = (*dl_lst);
	(*dl_lst)->next = pnew;
	pnew->next->prev = pnew;
}