/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_out2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:12:02 by reciak            #+#    #+#             */
/*   Updated: 2025/06/12 11:25:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		out_nbr(int nbr, char *digits)
{
	return (out_nbr_fd(nbr, digits, STDOUT_FD));
}

int		out_unbr(unsigned int nbr, char *digits)
{
	return (out_unbr_fd(nbr, digits, STDOUT_FD));
}

int		out_str(char *str)
{
	return (out_str_fd(nbr, STDOUT_FD));
}

int		out_vptr(void *ptr)
{
	return (out_vptr_fd(ptr, STDOUT_FD));
}