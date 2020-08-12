/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	init_texture_next(t_data *img)
{
	if (!(img->img_we_ptr = mlx_xpm_file_to_image(img->mlx, img->west,
		&img->we_width, &img->we_height)))
		gest_error(img, 3);
	img->data_we = (int *)mlx_get_data_addr(img->img_we_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!(img->img_ea_ptr = mlx_xpm_file_to_image(img->mlx,
		img->east, &img->ea_width, &img->ea_height)))
		gest_error(img, 4);
	img->data_ea = (int *)mlx_get_data_addr(img->img_ea_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!(img->sprite_ptr = mlx_xpm_file_to_image(img->mlx,
		img->sprite, &img->sp_width, &img->sp_height)))
		gest_error(img, 5);
	img->data_sprite = (int *)mlx_get_data_addr(img->sprite_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
}

void		init_texture(t_data *img)
{
	if (!(img->img_no_ptr = mlx_xpm_file_to_image(img->mlx,
		img->north, &img->no_width, &img->no_height)))
		gest_error(img, 1);
	img->data_no = (int *)mlx_get_data_addr(img->img_no_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!(img->img_so_ptr = mlx_xpm_file_to_image(img->mlx,
		img->south, &img->so_width, &img->so_height)))
		gest_error(img, 2);
	img->data_so = (int *)mlx_get_data_addr(img->img_so_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	init_texture_next(img);
}
