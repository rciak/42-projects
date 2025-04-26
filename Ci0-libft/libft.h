/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:42:14 by reciak            #+#    #+#             */
/*   Updated: 2025/04/26 18:08:27 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft_h
# define libft_h

# include <stdbool.h>  // true, false
# include <stdlib.h>   // malloc, free   (also NULL definition aside stddef.h)

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef t_list		t_lnd;


int ft_isalnum(int c);

#endif