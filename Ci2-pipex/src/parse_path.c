/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:09:46 by reciak            #+#    #+#             */
/*   Updated: 2025/11/24 18:51:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_path.c
 * @brief Stores the definition of parse_path()
 */

#include "pipex.h"

static char	**extract__path(char **envp, t_data *data);
static void	free__path_before_index(t_cmd *cmd, size_t i_fail);

/**
 * @brief Check if there is envp contains a PATH variable and parses it in case.
 * @note If there is no PATH variable in the array pointed to by envp
 *       then data->path is set to \c NULL
 * @note If in that array there is a PATH variable but it is the empty string
 *       then data-path is not \c NULL but a pointer to an empty array.
 * @param[in] envp
 * @param[out] data -> path
 * @return 
 *          * When everything is ok (also no PATH is ok!)
 *          * When there was an error (e.g. malloc failed if there was a PATH)
 */
void	parse_path(char **envp, t_data *data)
{
	data->path = NULL;
	if (envp == NULL || *envp == NULL)
		return ;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", ft_strlen("PATH=")) == 0)
		{
			data->path = ft_split(*envp + ft_strlen("PATH="), ':');
			if (data->path == NULL)
				exit_on(E_ALLOC, errno, "parse_path", data);
			return ;
		}
		envp++;
	}
}
