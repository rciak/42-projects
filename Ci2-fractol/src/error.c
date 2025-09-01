/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:19:29 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 23:00:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @note In contrast to gnl I declared it here as static reducing the
 *       "risk" of stack overflow (though it seems very unlikely anyway)
 */
t_err	error(int error_code)
{
	static const t_err	err[] = {
	{ERR_NONE, "fractol: Success - no error detected"},
	{ERR_ARG, "fractol: Bad arguments."},
	{ERR_ATOF_STRICT, "fractol: atof_strict from libft gave an error"},
	{ERR_MLX_INIT, "fractol: mlx_init failed"},
	{ERR_MLX_NEW_WINDOW, "fractol: mlx_new_window failed"},
	{ERR_MLX_NEW_IMAGE, "fractol: mlx_new_image failed"},
	{ERR_MLX_GET_DATA_ADDR_NULL, "fractol: mlx_get_data_addr returned NULL"},
	{ERR_UNEXP_BITS_PER_PIXEL, "fractol: pits per pixel is expected to be 32"},
	{ERR_UNEXP_BIG_ENDIAN, "fractol: Big endian memory layout?"
		"Did you buy your computer in the last century?! ;-)"},
	};

	return (err[error_code]);
}
