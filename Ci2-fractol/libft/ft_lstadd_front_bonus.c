/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:54:05 by reciak            #+#    #+#             */
/*   Updated: 2025/05/26 07:56:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front_bonus.c
 * @brief Stores the definition of ft_lstadd_front
 */

#include "libft.h"

/**
 * @brief Adds the node \p new at the beginning of the list,
 *        cf. Libft Subject (Version 16.7).
 * @param[in, out] lst: The address of a pointer to the first node of a list.
 * @param[in] new: The address of a pointer to the node to be added.
 * @note If one or two of the parameters are `NULL` a segfault
 *       shall be triggered as warning / to point out to that.
 * @note Yet `*lst == NULL`, indicating an empty list, is ok: 
 *       In this case just the node \p new will be choosen a new starting
 *       point of *lst.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
