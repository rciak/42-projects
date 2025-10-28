/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:56:36 by reciak            #+#    #+#             */
/*   Updated: 2025/10/28 16:55:41 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_pipeline.c
 * @brief Stores the definition of exec_pipeline()
 */

#include "pipex.h"

/**
 * @brief Executes the pipe(x)line
 * @param[in] num_cmds
 * @param[in] cmd
 * @param[in] envp
 * @param[in] err
 * @return 
 *          * false, if a fork or if an execve
 *          * true, if the parent process successfully launched
 */
bool	exec_pipeline(size_t num_cmds, t_cmd *cmd, char **envp, t_err *err)
{
	size_t	i;

	if (err->type != E_NONE || num_cmds < 2)
		return (set_err(err, E_FUN_ASSERTION, errno, "exec_pipeline"), false);
	i = 0;
	while (i < num_cmds)
	{
		
		i++;
	}
	return (true);
}
