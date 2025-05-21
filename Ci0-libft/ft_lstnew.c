/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:19:50 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 08:49:59 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstnew.c
 * @brief Stores the definition of ft_lstnew
 */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a new node.
 *        The \p content member variable is
 *        initialized with the given parameter \p content .
 *        The variable \p next is initialized to `NULL`,
 *        cf. Libft Subject (Version 16.7).
 * @param[in] content: A pointer to the content to "store" in the new node.
 * @return
 *          * A pointer to the newly created node
 *          * `NULL` on error.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*pnode;

	pnode = calloc_uninit(1, sizeof(t_list));
	if (pnode == NULL)
		return (NULL);
	pnode->content = content;
	pnode->next = NULL;
	return (pnode);
}

