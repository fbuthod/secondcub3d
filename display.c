/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	display_next(t_data *img, int i)
{
	while (img->x < img->sp_nbr)
	{
		calculate_sprite(img, img->x);
		draw_sprite(img, i);
		img->x++;
	}
	if (img->screenshot == 1)
	{
		save_bitmap("bitmap.bmp", img);
		close_window(img);
	}
}

void	display(t_data *img)
{
	int		i;

	i = 0;
	img->x = -1;
	draw_floor_ceiling(img);
	while (++img->x < img->swidth)
	{
		setup_raytracer(img);
		step_side_distance(img);
		dda_calculs(img);
		texture(img);
		while (img->drawstart <= img->drawend)
		{
			draw(img);
			img->addr[img->drawstart++ * img->swidth + img->x] = img->color;
		}
		img->zbuffer[img->x] = img->perpwalldist;
	}
	img->x = 0;
	display_next(img, i);
}

void	setup_raytracer(t_data *img)
{
	ray_pos_dir(img);
	case_detect(img);
	ray_len(img);
}

void	step_side_distance(t_data *img)
{
	calcul_stepx(img);
	calcul_stepy(img);
}

void	dda_calculs(t_data *img)
{
	dda_algorithm(img);
	fisheye_adjustment(img);
	height_wall(img);
	fill_stripe(img);
}
