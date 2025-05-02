/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:42:14 by reciak            #+#    #+#             */
/*   Updated: 2025/05/02 22:45:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>  // true, false
# include <stdlib.h>   // malloc, free   (also NULL definition aside stddef.h)

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef t_list		t_lnd;

int	ft_isalnum(int c);

#endif