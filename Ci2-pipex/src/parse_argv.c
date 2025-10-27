/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:44:39 by reciak            #+#    #+#             */
/*   Updated: 2025/10/27 19:14:30 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_argv.c
 * @brief Stores the definition of parse_argv()
 */

#include "pipex.h"

static void	pre__init(t_cmd *cmd, size_t num_cmds);
static bool	set__files(t_cmd *cmd, int ac, char **av, t_err *err);
static bool	set_ac_and_create__av(t_cmd *cmd, int ac, char **av, t_err *err);
static void	free__av_before_index(t_cmd *cmd, size_t i_last);

/**
 * @brief This parses the input into the s_cmd_structure (most item of it)
 * @param[in] ac Number of arguments given to this program
 * @param[in] argv Arguments of this program
 * @param[out] data the parsed data
 * @param[out] x_err error information for caller
 * @return 
 *          * true if parsing worked
 *          * false if an error occured
 */

bool	parse_argv(int argc, char **argv, t_data *data, t_err *err)
{
	t_cmd	*cmd;
// Refactor later after parsing works: THE NEXT three lines should go to main....
// Then argc
	if (argc < 1 + 4)
		return (set_err(err, E_ARGC, errno, "parse_argv"), false);
	data->num_cmds = (size_t) argc - 3;
	data->cmd = malloc(data->num_cmds * sizeof (*cmd));
	cmd = data->cmd;
	if (cmd == NULL)
		return (set_err(err, E_ALLOC, errno, "parse: cmd"), false);
// During development this should be commented out: Pre__init might otherwise
// Turn good bugs (indicated by valgrind) into hard to find bugs (not indicated) ..
	pre__init(cmd, data->num_cmds);
	if (!set__files(cmd, argc, argv, err))
		return (free(cmd), false);
	if (!set_ac_and_create__av(cmd, argc, argv, err))
	{
		free(cmd[0].infile);
		free(cmd[data->num_cmds - 1].outfile);
		free(cmd);
		return (false);
	}
	return (set_err(err, E_NONE, errno, "parse: ok"), true);
}

static void	pre__init(t_cmd *cmd, size_t num_cmds)
{
	size_t i;

	i = 0;
	while (i < num_cmds)
	{
		cmd[i].ac = 0;
		cmd[i].av = NULL;
		cmd[i].path = NULL;
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		cmd[i].fd_in = DO_NOT_USE;
		cmd[i].fd_out = DO_NOT_USE;
		cmd[i].pid = DO_NOT_USE;
		                            //    Decomment if  .status  gets added to struct s_cmd:  cmd[i].status = EXITCODE_ERR_NONE;
		i++;
	}
}

static bool	set__files(t_cmd *cmd, int ac, char **av, t_err *err)
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
		return (set_err(err, E_ALLOC, errno, "parse: set__files"), false);
	}
	return (true);
}

static bool	set_ac_and_create__av(t_cmd *cmd, int ac, char **av, t_err *err)
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
			set_err(err, E_ALLOC, errno, "parse: create__av");
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
