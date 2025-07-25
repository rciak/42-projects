/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_circularize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:57:52 by reciak            #+#    #+#             */
/*   Updated: 2025/07/25 11:53:02 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_circularize.c
 * @brief Stores the definition of dl_lst_circularize()
 */

#include "libft.h"

/**
* @brief Transform a linear doubly linked list into a circular one by
*        detecting the first and last nodes and linking them to each other.
*        In the irregular case of an empty list simply nothing happens.
* @param[in, out] pnode A pointer to any node of the doubly linked list.
*                        which becomes the first node after breaking
*                        the circular structure by cuting its connection
*                        to its predecessor.
* @warning **Test Status:** not unit tested.
*/
void		dl_lst_circularize(t_dl_node *pdl_node)
{
	t_dl_node	*first;
	t_dl_node	*last;

	if (pdl_node == NULL)
		return ;
	first = pdl_node;
	last = pdl_node;
	while (first->prev != NULL)
		first = first->prev;
	while (last->next != NULL)
		last = last->next;
	first->prev = last;
	last->next = first;
}
