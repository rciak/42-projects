/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:40:23 by reciak            #+#    #+#             */
/*   Updated: 2025/07/25 12:28:49 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_size.c
 * @brief Stores the definition of dl_lst_size()
 */

#include "libft.h"
#include <unistd.h>

static size_t	st_count_when_nonempty_linear(const t_dl_node *const pdl_node);
static size_t	st_count_when_nonempty_circular(const t_dl_node *const pdl_node);

/**
* @brief Counts the number of nodes in the double linked list,
*        no matter if it is linear, or circular.
* @note For simplicty of code no option to skip / override the autodetection
*       was included. If there ever should be need for the
*       helper functions in that functions could be made non-static
*       (with the need for renaming ...)
* @remark Here a unsigned return type is prefered, contrasting
*         ft_lstsize where return type `int` was requested.
* @param[in] pdl_node: A pointer to **any** node of the doubly linked list.
*                    (or `NULL` in case of an empty list)
* @return The length of the list, i.e. its number of nodes.
* @warning **Test Status:** not unit tested,
*          circular case indirectly tested via push_swap_project.
*/
size_t	dl_lst_size(const t_dl_node *const pdl_node)
{
	t_dl_type	type;

	type = dl_lst_type(pdl_node);
	if (type == DL_EMPTY)
		return (0);
	else if (type == DL_NON_EMPTY_LINEAR)
		return (st_count_when_nonempty_linear(pdl_node));
	else if (type == DL_NON_EMPTY_CIRCULAR)
		return (st_count_when_nonempty_circular(pdl_node));
	else
	{
		ft_putstr_fd("  dl_lst_size: " RED"Error", STDERR_FILENO);
		return (-1);
	}
}

static size_t	st_count_when_nonempty_linear(const t_dl_node *const pdl_node)
{
	const t_dl_node	*pnode;
	size_t			len;

	pnode = pdl_node;
	len = 0;
	while (pnode != NULL)
	{
		len++;
		pnode = pnode->next;
	}
	pnode = pdl_node->prev;
	while (pnode != NULL)
	{
		len++;
		pnode = pnode->prev;
	}
	return (len);
}

static size_t	st_count_when_nonempty_circular(const t_dl_node *const pdl_node)
{
	const t_dl_node	*pnode;
	size_t			len;

	pnode = pdl_node;
	len = 1;
	while (pnode->next != pdl_node)
	{
		len++;
		pnode = pnode->next;
	}
	return (len);
}

