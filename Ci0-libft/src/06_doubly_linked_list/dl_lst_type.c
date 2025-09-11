/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:31:17 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 21:53:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_type.c
 * @brief Stores the definition of dl_lst_type()
 */

#include "libft.h"

/**
* @brief Determins if a doubly linked list is linear or circular 
*        (potentially empty).
* @note A broken doubly linked list might cause infinite looping or other
*       problematic behaviour.
* @param[in] pdl_node A pointer to **any** node of the doubly linked list.
*                   (or `NULL` in case of an empty list)
* @return One of the entries of t_dl_list_type
*          * DL_EMPTY
*          * DL_NON_EMPTY_LINEAR
*          * DL_NON_EMPTY_CIRCULAR
* @warning **Test Status:** not unit tested,
*          circular case indirectly tested via push_swap_project.
*/
t_dl_type	dl_lst_type(const t_dl_node *const pdl_node)
{
	const t_dl_node	*pnode;

	if (pdl_node == NULL)
		return (DL_EMPTY);
	pnode = pdl_node->next;
	while (pnode != NULL && pnode != pdl_node)
		pnode = pnode->next;
	if (pnode == NULL)
		return (DL_NON_EMPTY_LINEAR);
	return (DL_NON_EMPTY_CIRCULAR);
}
