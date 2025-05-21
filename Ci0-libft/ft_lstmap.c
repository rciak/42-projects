/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:36:36 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 18:56:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap.c
 * @brief Stores the definition of ft_lstmap
 */

#include "libft.h"

/**
 * @brief Iterates through the list \p lst, applies the
 *        function `f` to each node’s content, and creates
 *        a new list resulting of the successive applications
 *        of the function `f`. The `del` function is used to
 *        delete the content of a node if needed,
 *        cf. Libft Subject (Version 16.7).
 * @remark Using a signed datatype in `int i_fail` feels strange, but was
 *         choosen to keep concistency with the same weird return type
 *         of ft_lstsize().
 * @param[in] lst: The address of a pointer to a node.
 * @param[in] f: The address of the function applied to each node's content.
 * @param[in] del: The address of the function used to delete a
 *                 node's content if needed.
 *                 (If suddenly no more allocs are possible.)
 * @return 
 *          * The new linked list.
 *          * `NULL` on error, usually allocation errors.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*transf_content;
	t_list	*transf_lst;
	t_list	*new;

	transf_lst = NULL;
	while (lst)
	{
		transf_content = (*f)(lst->content);
		new = ft_lstnew(transf_content);
		if (new == NULL)
		{
			free(transf_content);
			ft_lstclear(&transf_lst, (*del));
			return (NULL);
		}
		ft_lstadd_front(&transf_lst, new);
		lst = lst->next;
	}
	return (transf_lst);
}
