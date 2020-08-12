/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_function2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	window_init(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->swidth, img->sheight, "Cub3D");
	img->img = mlx_new_image(img->mlx, img->swidth, img->sheight);
	img->addr = (int *)mlx_get_data_addr(img->img,
		&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	alloc_sprite_order(t_data *img)
{
	img->sp_order = (int *)malloc(sizeof(int) * (img->sp_nbr + 1));
	img->sp_dist = (double *)malloc(sizeof(double) * (img->sp_nbr + 1));
	img->sp_order[img->sp_nbr] = '\0';
	img->sp_dist[img->sp_nbr] = '\0';
}
