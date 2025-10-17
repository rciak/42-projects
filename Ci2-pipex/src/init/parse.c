/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:42 by reciak            #+#    #+#             */
/*   Updated: 2025/10/17 19:08:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.c
 * @brief Stores the definition of parse()
 */

#include "pipex.h"

static bool	set__files(t_cmd *cmd, int ac, char **av, t_x_err *x_err);
static bool	set_ac_and_create__av(t_cmd *cmd, int ac, char **av, t_x_err *x_err);
static void	free__av_before_index(t_cmd *cmd, size_t i_last);

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
	t_cmd	*cmd;

	if (argc < 1 + 4)
		return (*x_err = x_error(ERR_ARGC, errno, "parse"), false);
	data->num_cmds = (size_t) argc - 3;
	data->cmd = malloc((data->num_cmds + 1) * sizeof (*cmd));
	cmd = data->cmd;
	if (cmd == NULL)
		return (*x_err = x_error(ERR_ALLOC, errno, "parse: cmd"), false);
	if (!set__files(cmd, argc, argv, x_err))
		return (free(cmd), false);
	if (!set_ac_and_create__av(cmd, argc, argv, x_err))
	{
		free(cmd[0].infile);
		free(cmd[data->num_cmds - 1].outfile);
		free(cmd);
		return (false);
	}
	return (*x_err = x_error(ERR_NONE, errno, "parse: ok"), true);
}

static bool	set__files(t_cmd *cmd, int ac, char **av, t_x_err *x_err)
{
	size_t	ac_cmds;
	size_t	i;

	ac_cmds = (size_t) ac - 3;
	i = 0;
	while (i < ac_cmds)
	{
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		i++;
	}
	cmd[0].infile = ft_strdup(av[1]);
	cmd[ac_cmds - 1].outfile = ft_strdup(av[ac - 1]);
	if (cmd[0].infile == NULL || cmd[ac_cmds - 1].outfile == NULL)
	{
		free(cmd[0].infile);
		free(cmd[ac_cmds - 1].outfile);
		return (*x_err = x_error(ERR_ALLOC, errno, "parse: set__files"), false);
	}
	return (true);
}

static bool	set_ac_and_create__av(t_cmd *cmd, int ac, char **av,
	t_x_err *x_err)
{
	size_t	ac_cmds;
	size_t	i;

	ac_cmds = (size_t) ac - 3;
	i = 0;
	while (i < ac_cmds)
	{
		cmd[i].ac = count_words(av[i + 2], " ");
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

static void	free__av_before_index(t_cmd *cmd, size_t i_fail)
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
