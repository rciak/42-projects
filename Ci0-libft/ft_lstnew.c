/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:32 by Rene Ciak         #+#    #+#             */
/*   Updated: 2025/04/26 17:50:35 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lnd	*ft_lstnew(void *content)
{
	t_lnd	*initial_node_of_new_list;

	initial_node_of_new_list = malloc(sizeof(t_lnd));
	if (initial_node_of_new_list != NULL)
	{
		initial_node_of_new_list->content = content;
		initial_node_of_new_list->next = NULL;
	}
	return (initial_node_of_new_list);
}