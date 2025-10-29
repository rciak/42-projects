/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:37:47 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:08:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstlast_bonus.c
 * @brief Stores the definition of ft_lstlast()
 */

#include "libft.h"

/**
 * @brief Returns (a pointer to) the last node of the list,
 *        cf. Libft Subject (Version 16.7).
 * @param[in] lst: The beginning of the list, i.e. a pointer to its first node.
 * @return 
 *         * A pointer to the last node of the list.
 *         * `NULL` in case of an empty list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
