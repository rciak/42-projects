/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:54:53 by reciak            #+#    #+#             */
/*   Updated: 2025/11/24 17:52:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_argv.c
 * @brief Stores the definition of parse_argv()
 */

#include "pipex.h"

static void	set__files(int argc, char **argv, t_data *data);
static void	free__av_before_index(t_cmd *cmd, size_t i_fail);

/**
 * @brief This parses the input into the s_cmd_structure (most item of it)
 * @param[in] argc Number of arguments given to this program
 * @param[in] argv The list of arguments given to this program
 * @param[out] data the parsed data (stored in data->cmd[i], i = 0, 1, ...)
 */
void	parse_argv(int argc, char **argv, t_data *data)
{
	t_cmd	*cmd;
	int		i;

	set__files(argc, argv, data);
	cmd = data->cmd;
	i = 0;
	while (i < data->num_cmds)
	{
		cmd[i].ac = count_words(argv[i + 2], " ");
		cmd[i].av = ft_split(argv[i + 2], ' ');
		if (cmd[i].av == NULL)
		{
			free__av_before_index(cmd, i);
			exit_on(E_ALLOC, errno, "parse_argv", data);
		}
		i++;
	}
}

static void	set__files(int argc, char **argv, t_data *data)
{
	int		n;
	t_cmd	*cmd;

	n = data->num_cmds;
	cmd = data->cmd;
	cmd[0].infile = ft_strdup(argv[1]);
	cmd[n - 1].outfile = ft_strdup(argv[argc - 1]);
	if (cmd[0].infile == NULL || cmd[n - 1].outfile == NULL)
		exit_on(E_ALLOC, errno, "set__files", data);
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
			cmd[i].av[j] = NULL;
			j++;
		}
		free(cmd[i].av);
		cmd[i].av = NULL;
		i++;
	}
}
