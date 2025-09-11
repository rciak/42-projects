/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:01:36 by reciak            #+#    #+#             */
/*   Updated: 2025/08/10 15:07:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file update_group.c
 * @brief Stores the definition of update_group()
 */

#include "push_swap.h"

static void			write__groupsize_to_members(t_dl_node *first, int size);
static void			calc__and_write_rank_to_members(t_dl_node *first, int size);
static void			unset___rank_of_members(t_dl_node *first, int size);
static t_dl_node	*find___smallest_unranked(t_dl_node *first, int size);

/**
 * @brief Iterates of over the nodes within the group.starts and group.ends
 *        markers and refreshes the (group size) information and rank of the
 *        node inside the group.
 * @note This functions should be called after the creation of
 *       * the initial group (full original stack a), or
 *       * spliting of a group into subgroups (during which the new
 *         `group.starts` and `group.ends` markers must have already 
 *         have been set)
 * @param[in, out] node A pointer to any node of a group (giving access to 
 *                      all nodes of the group)
 */
void	update_group(t_dl_node *node)
{
	int			size;

	size = group_size(node);
	if (size == 0)
		return ;
	while (((t_ps_obj *)node->obj)->group.starts == false)
		node = node->prev;
	write__groupsize_to_members(node, size);
	calc__and_write_rank_to_members(node, size);
}

static void	write__groupsize_to_members(t_dl_node *first, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		((t_ps_obj *)first->obj)->group.size = size;
		first = first->next;
		i++;
	}
}

static void	calc__and_write_rank_to_members(t_dl_node *first, int size)
{
	int			rank;
	t_dl_node	*smallest_unranked;

	unset___rank_of_members(first, size);
	rank = 1;
	while (rank <= size)
	{
		smallest_unranked = find___smallest_unranked(first, size);
		((t_ps_obj *)smallest_unranked->obj)->group.rank = rank;
		rank++;
	}
}

static void	unset___rank_of_members(t_dl_node *first, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		((t_ps_obj *)first->obj)->group.rank = -1;
		first = first->next;
		i++;
	}
}

static t_dl_node	*find___smallest_unranked(t_dl_node *first, int size)
{
	t_dl_node	*node;
	t_dl_node	*min_unrank;
	int			i;

	node = first;
	min_unrank = first;
	while (((t_ps_obj *)min_unrank->obj)->group.rank != -1)
		min_unrank = min_unrank->next;
	if (min_unrank == NULL)
		return (NULL);
	i = 1;
	while (i <= size)
	{
		if (((t_ps_obj *)node->obj)->goal < ((t_ps_obj *)min_unrank->obj)->goal
			&& ((t_ps_obj *)node->obj)->group.rank == -1
		)
			min_unrank = node;
		node = node->next;
		i++;
	}
	return (min_unrank);
}
