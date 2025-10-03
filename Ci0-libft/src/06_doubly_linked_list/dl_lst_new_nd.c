/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_new_nd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:28:59 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 09:51:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_new_nd.c
 * @brief Stores the definition of dl_lst_new_nd()
 */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a new node
 *        for a doubly linked list.
 *        The \p obj member variable is
 *        initialized with the given parameter \p obj .
 *        The variables \p next and \p prev are initialized to `NULL`.
 * @param[in] obj: A pointer to the content to "store" in the new node.
 * @return
 *          * A pointer to the newly created node
 *          * `NULL` on error.
 * @warning **Test Status:** not unit tested,
 *          but indirectly tested via push_swap_project.
 */

t_dl_node	*dl_lst_new_nd(void *obj)
{
	t_dl_node	*pnode;

	pnode = calloc_uninit(1, sizeof(t_dl_node));
	if (pnode == NULL)
		return (NULL);
	pnode->obj = obj;
	pnode->prev = NULL;
	pnode->next = NULL;
	return (pnode);
}
