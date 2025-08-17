/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:40:04 by reciak            #+#    #+#             */
/*   Updated: 2025/08/17 23:54:02 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_image_struct.c
 * @brief Stores the definition of init_image_struct()
 */

#include "fractol.h"

/**
 * @brief 
 *
 * @note 
 * @param[in] 
 * @param[out]
 * @param[in,out]
 * @return 
 *          * 
 *          * 
 */
 // TODO:                                                                 DOCUMENT ...!
bool	init_image_struct(t_image *img, void *img_meta)
{
	char *buf;

	buf = mlx_get_data_addr(
		img_meta, 
		&img->bits_per_pixel,
		&img->size_line,
		&img->endian
	)
	
	img->buf = (int *) buf;
	if ()
}

char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian)
{
  *bits_per_pixel = img->bpp;
  *size_line = img->size_line;
  *endian = img->image->byte_order;
  return (img->data);

