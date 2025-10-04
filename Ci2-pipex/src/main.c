/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:07:32 by reciak            #+#    #+#             */
/*   Updated: 2025/10/03 11:14:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"

/**
 * @brief The entry point and dirigent for the pipex programm ...
 * @note 
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */

#include "pipex.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	write(STDOUT_FILENO, "Hello World!\n", 14);
}
