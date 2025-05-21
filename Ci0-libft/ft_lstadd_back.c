/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:52:12 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 18:44:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 * @brief Stores the definition of ft_lstadd_back
 */

#include "libft.h"

/**
 * @brief Adds the node \p new at the end of the list,
 *        cf. Libft Subject (Version 16.7).
 * @param[in, out] lst: The address of a pointer to the first node of a list.
 * @param[in] new: The address of a pointer to the node to be added.
 * @note In the case of an empty list, the outer content *lst will be changed
 *       and be no longer `NULL`. In the other cases the pointer *lst will not
 *       change.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
