/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lst_linearize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:29:32 by reciak            #+#    #+#             */
/*   Updated: 2025/07/27 22:03:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file dl_lst_linearize.c
 * @brief Stores the definition of dl_lst_linearize()
 */

#include "libft.h"

/**
* @brief Transform a circular doubly linked list into a linear one.
*        In the irregular case of an empty list simply nothing happens.
* @param[in, out] dl_lst A pointer to the node of the doubly linked list
*                        which becomes the first node after breaking
*                        the circular structure by cuting its connection
*                        to its predecessor.
* @warning **Test Status:** not unit tested,
*          indirectly tested via push_swap_project
*          (development / debug helper: printing stacks...)
*/
void	dl_lst_linearize(t_dl_node *pdl_node)
{
	if (pdl_node == NULL)
		return ;
	if (pdl_node->prev != NULL)
		pdl_node->prev->next = NULL;
	pdl_node->prev = NULL;
	return ;
}
