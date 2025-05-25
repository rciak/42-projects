/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:26:04 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 16:33:16 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstiter.c
 * @brief Stores the definition of ft_lstiter
 */

#include "libft.h"

/**
 * @brief Iterates through the list \p lst and applies the
 *        function `f` to the content of each node,
 *        cf. Libft Subject (Version 16.7).
 * @note 
 * @param[in] lst: The address of a pointer to a node.
 * @param[in] f: The address of the function to apply to each node's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
