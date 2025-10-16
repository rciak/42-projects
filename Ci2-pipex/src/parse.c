/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:42 by reciak            #+#    #+#             */
/*   Updated: 2025/10/16 12:22:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.c
 * @brief Stores the definition of parse()
 */

#include "pipex.h"

static bool	set__redir(t_parse_unit *cmd, int ac, char **av, t_x_err *x_err);
static bool	create__av(t_parse_unit *cmd, int ac, char **av, t_x_err *x_err);
static void	free__av_before_index(t_parse_unit *cmd, size_t i_last);

/**
 * @brief This parses the input into the s_exec_unit_structure
 * @param[in] ac Number of arguments given to this program
 * @param[in] argv Arguments of this program
 * @param[out] data the parsed data
 * @param[out] x_err error information for caller
 * @return 
 *          * true if parsing worked
 *          * false if an error occured
 */
bool	parse(int argc, char **argv, t_data *data, t_x_err *x_err)
{
	t_parse_unit	*cmd;

	if (argc < 1 + 4)
		return (*x_err = x_error(ERR_ARGC, errno, "parse"), false);
	data->ac_cmd = (size_t) argc - 3;
	cmd = data->cmd;
	cmd = malloc((data->ac_cmd + 1) * sizeof (*cmd));
	if (cmd == NULL)
		return (*x_err = x_error(ERR_ALLOC, errno, "parse: cmd"), false);
	if (!set__redir(cmd, argc, argv, x_err))
		return (free(cmd), false);
	if (!create__av(cmd, argc, argv, x_err))
	{
		free(cmd[0].redir[IN]);
		free(cmd[data->ac_cmd - 1].redir[OUT]);
		free(cmd);
		return (false);
	}
	return (*x_err = x_error(ERR_NONE, errno, "parse: ok"), false);
}

static bool	set__redir(t_parse_unit *cmd, int ac, char **av, t_x_err *x_err)
{
	size_t	ac_cmds;
	size_t	i;

	ac_cmds = (size_t) ac - 3;
	i = 0;
	while (i < ac_cmds)
	{
		cmd[i].redir[IN] = NULL;
		cmd[i].redir[OUT] = NULL;
		i++;
	}
	cmd[0].redir[IN] = ft_strdup(av[1]);
	cmd[ac_cmds - 1].redir[OUT] = ft_strdup(av[ac - 1]);
	if (cmd[0].redir[IN] == NULL || cmd[ac_cmds - 1].redir[OUT] == NULL)
	{
		free(cmd[0].redir[IN]);
		free(cmd[ac_cmds - 1].redir[OUT]);
		return (*x_err = x_error(ERR_ALLOC, errno, "parse: set__redir"), false);
	}
	return (true);
}

static bool	create__av(t_parse_unit *cmd, int ac, char **av, t_x_err *x_err)
{
	size_t	ac_cmds;
	size_t	i;

	ac_cmds = (size_t) ac - 3;
	i = 0;
	while (i < ac_cmds)
	{
		cmd[i].av = ft_split(av[i + 2], ' ');
		if (cmd[i].av == NULL)
		{
			*x_err = x_error(ERR_ALLOC, errno, "parse: create__av");
			free__av_before_index(cmd, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	free__av_before_index(t_parse_unit *cmd, size_t i_fail)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < i_fail)
	{
		j = 0;
		while (j < cmd[i].ac)
		{
			free(cmd[i].av[j]);
			j++;
		}
		free(cmd[i].av);
		i++;
	}
}
