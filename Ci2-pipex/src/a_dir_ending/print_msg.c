/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:53:28 by reciak            #+#    #+#             */
/*   Updated: 2025/11/28 17:49:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_msg.c
 * @brief Stores the definition of print_msg()
 */

#include "pipex.h"

static char	*interpretation__str2(t_exit_info info, t_data *data);
static bool	add__to_str(char **str, char *postfix);
static char	*null__ft_strdup(char *str);

/**
 * @brief Print a message on exititing
 * @note  This converts the specs in map__to_exit_info() (exit_on.c)
 *        into output - an error in argc is not intended to be treated this way,
 *        cf. the warning in map__to_exit_info()
 * @param[in] info exit info
 * @param[in] origin the name of the function which caused the error
 * @param[in] data providing access to usuable information
 */
void	print_msg(t_exit_info info, const char *origin, t_data *data)
{
	char	*str2_final;
	char	*msg;

	str2_final = interpretation__str2(info, data);
	if (str2_final == NULL)
	{
		out_str_fd("Sorry: Mem seems too low ...\n", STDERR_FILENO);
		return ;
	}
	msg = NULL;
	if (!add__to_str(&msg, "Exiting  ") || !add__to_str(&msg, (char *) origin)
		|| !add__to_str(&msg, "\n  ---->  ") || !add__to_str(&msg, info.str1)
		|| !add__to_str(&msg, " ") || !add__to_str(&msg, str2_final)
		|| !add__to_str(&msg, "\n\n")
	)
	{
		free(str2_final);
		free(msg);
		out_str_fd("Sorry: Mem seems too low to create better exit message.\n",
			STDERR_FILENO);
		return ;
	}
	out_str_fd(msg, STDERR_FILENO);
	free(str2_final);
	free(msg);
}

static bool	add__to_str(char **str, char *postfix)
{
	char	*new;

	if (*str == NULL)
		new = null__ft_strdup(postfix);
	else
		new = ft_strjoin(*str, postfix);
	if (new == NULL)
		return (false);
	free(*str);
	*str = new;
	return (true);
}

static char	*interpretation__str2(t_exit_info info, t_data *data)
{
	t_cmd	*cmd;
	int		i;
	char	*take;

	cmd = data->cmd;
	i = data->i_cmd_err;
	take = NULL;
	if (ft_strcmp(info.str2, "cmd[i].av[0]") == 0)
		take = null__ft_strdup(cmd[i].av[0]);
	else if (ft_strcmp(info.str2, "cmd[i].infile") == 0)
		take = null__ft_strdup(cmd[i].infile);
	else if (ft_strcmp(info.str2, "cmd[i].outfile") == 0)
		take = null__ft_strdup(cmd[i].outfile);
	else
		take = null__ft_strdup(info.str2);
	return (take);
}

static char	*null__ft_strdup(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
