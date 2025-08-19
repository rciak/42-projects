/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:40:04 by reciak            #+#    #+#             */
/*   Updated: 2025/08/18 21:50:42 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_image_struct.c
 * @brief Stores the definition of init_image_struct()
 */

#include "fractol.h"

/**
 * @brief Calls mlx_get_data_addr entries to get some meta data about the image
 *        and stores them.
 * @note **Assumptions**: Endian is little endian, 
 *       one pixel is represent by an int, an int is 4 bytes long.
 * @param[out] img will store all retrieved infromations from 
 * @param[in] img_meta A void pointer to a certain mlx (or X) struct instance
 *                     containing meta information about the image.
 * @return 
 *          * false if something unexpected happened
 *          * true, else.
 */

bool	init_image_struct(t_image *img, void *img_meta, t_err *err)
{
	int	bits_per_pixel;
	int	endian;

	img->buf = mlx_get_data_addr(
		img_meta, 
		&bits_per_pixel,
		&img->size_line,
		&endian
	);
	if (img->buf != NULL)
		return (*err = error(ERR_MLX_GET_DATA_ADDR_NULL), false);
	if (endian == BIG_ENDIAN)
		return (*err = error(ERR_UNEXP_BIG_ENDIAN), false);
	if (bits_per_pixel != 4 * 8)
		return (*err = error(ERR_UNEXP_BITS_PER_PIXEL), false);
	img->bytes_per_pixel = bits_per_pixel / 8;
	return (true);
}
