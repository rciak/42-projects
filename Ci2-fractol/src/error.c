/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:19:29 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 15:32:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <unistd.h>


/**
 * @note In contrast to gnl I declared it here as static reducing the
 *       "risk" of stack overflow (though it seems very unlikely anyway)
 */
t_err error(int error_code)
{
	static const t_err	err[] = {
	{ERR_NONE, "fractol: Success - no error detected"},
	{ERR_ARG, "fractol: Bad arguments."},
	{ERR_MLX_INIT, "fractol: mlx_init failed"},
	{ERR_MLX_NEW_WINDOW, "fractol: mlx_new_window failed"},
	{ERR_MLX_NEW_IMAGE, "fractol: mlx_new_image failed"}
	};
	return (err[error_code]);
}
