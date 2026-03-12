/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:36:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/02 19:08:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap_bonus.c
 * @brief Stores the definition of ft_lstmap()
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
 * @remark The following version is a speeded up Version from the submitted one
 *         (The current version now only of complexity `O(n)`, where n stands
 *         for the number of nodes of the original list.) 
 *         Maybe the factor 
 *         (in front of `n` might be improved still but for simplicity the
 *         current version, 30.05.2025, is kept.)
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
	void	*transf_cont;
	t_list	*transf_lst;
	t_list	*transf_lst_end;
	t_list	*new;

	transf_lst = NULL;
	transf_lst_end = NULL;
	while (lst)
	{
		transf_cont = (*f)(lst->content);
		new = ft_lstnew(transf_cont);
		if (new == NULL)
		{
			(*del)(transf_cont);
			ft_lstclear(&transf_lst, del);
			return (NULL);
		}
		if (transf_lst == NULL)
			transf_lst = new;
		ft_lstadd_back(&transf_lst_end, new);
		transf_lst_end = new;
		lst = lst->next;
	}
	return (transf_lst);
}
