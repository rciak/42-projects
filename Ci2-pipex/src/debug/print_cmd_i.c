/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:02:30 by reciak            #+#    #+#             */
/*   Updated: 2025/11/27 10:50:22 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_cmd_i.c
 * @brief Stores the definition of print_cmd_i()
 */

#include "pipex.h"
#include <stdio.h>

static void	print__cmd(t_cmd cmd, char *prefix, char *prefix2, char *what);

void	print_cmd_i(t_data *data, int i, char *what)
{
	fprintf(stderr, "cmd[%i] -------------------------------------------\n", i);
	print__cmd(data->cmd[i], "       ", "                   ", what);
}

static void	print__cmd(t_cmd cmd, char *prefix, char *prefix2, char *what)
{
	if (ft_strcmp(what, "all") == 0)
	{
		fprintf(stderr, "%sac:       %zu\n", prefix, cmd.ac);
		fprintf(stderr, "%sav:       \n", prefix);
		print_arr(cmd.av, prefix2);
		fprintf(stderr, "%spathname: %s\n", prefix, cmd.pathname);
		fprintf(stderr, "%sinfile:   %s\n", prefix, cmd.infile);
		fprintf(stderr, "%soutfile:  %s\n", prefix, cmd.outfile);
		fprintf(stderr, "%sfd_in:    %d\n", prefix, cmd.fd_in);
		fprintf(stderr, "%sfd_out:   %d\n", prefix, cmd.fd_out);
		fprintf(stderr, "%spid:      %d\n", prefix, cmd.pid);
	}
	else if (ft_strcmp(what, "fds") == 0)
	{
		fprintf(stderr, "%sfd_in:    %d\n", prefix, cmd.fd_in);
		fprintf(stderr, "%sfd_out:   %d\n", prefix, cmd.fd_out);
	}
	else if (ft_strcmp(what, "fds+iofiles") == 0)
	{
		fprintf(stderr, "%sinfile:   %s\n", prefix, cmd.infile);
		fprintf(stderr, "%soutfile:  %s\n", prefix, cmd.outfile);
		fprintf(stderr, "%sfd_in:    %d\n", prefix, cmd.fd_in);
		fprintf(stderr, "%sfd_out:   %d\n", prefix, cmd.fd_out);
	}
}
