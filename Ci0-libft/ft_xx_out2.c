/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_out2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:12:02 by reciak            #+#    #+#             */
/*   Updated: 2025/06/12 11:16:51 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		out_nbr(int nbr, char *digits)
{
	return (out_nbr_fd(STDOUT_FD, nbr, digits));
}

int		out_unbr(int fd, unsigned int nbr, char *digits)
{
	return (out_unbr_fd(STDOUT_FD, nbr, digits));
}

int		out_str(char *str)
{
	return (out_str_fd(STDOUT_FD, nbr));
}

int		out_vptr(void *ptr)
{
	return (out_vptr_fd(STDOUT_FD, ptr));
}