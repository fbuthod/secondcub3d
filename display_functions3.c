/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void		draw(t_data *img)
{
	if (img->side == 0)
		img->tex_y = img->stepy > 0 ? ((int)img->texpos &
				img->no_height - 1) :
			((int)img->texpos & img->so_height - 1);
	else if (img->side == 1)
		img->tex_y = img->stepx < 0 ? ((int)img->texpos &
				img->ea_height - 1) :
			((int)img->texpos & img->we_height - 1);
	if (img->side == 0)
		img->color = img->stepy > 0 ? img->data_no[img->no_height
			* img->tex_y + img->tex_x] :
			img->data_so[img->so_height * img->tex_y + img->tex_x];
	else if (img->side == 1)
	{
		if (img->ea_height * img->tex_y + img->tex_x <
				img->ea_height * img->ea_width)
		{
			img->color = img->stepx < 0 ?
				img->data_ea[img->ea_height * img->tex_y +
				img->tex_x] : img->data_we[img->we_height * img->tex_y
				+ img->tex_x];
		}
	}
	img->texpos += img->step;
}

void		draw_floor_ceiling(t_data *img)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	img->x = -1;
	while (++j < img->sheight / 2)
	{
		i = -1;
		while (++i < img->swidth)
			img->addr[j * img->swidth + i] = img->color_ceiling;
	}
	while (j < img->sheight)
	{
		i = -1;
		while (++i < img->swidth)
			img->addr[j * img->swidth + i] = img->color_floor;
		j++;
	}
}

static void	draw_sprite_next(t_data *img)
{
	img->tex_y = (int)((img->calc * img->sp_height) / img->sp_h) / 256;
	if (img->tex_x < 0)
		img->tex_x = 0;
	if (img->tex_y < 0)
		img->tex_y = 0;
	if (img->sp_width * img->tex_y + img->tex_x < img->sp_width *
			img->sp_height)
		img->color = img->data_sprite[img->sp_width *
			img->tex_y + img->tex_x];
}

void		draw_sprite(t_data *img, int i)
{
	while (img->drawstartx < img->drawendx && img->drawstartx < img->swidth)
	{
		i = img->drawstarty;
		img->tex_x = (int)(256 * (img->drawstartx - (-img->sp_w / 2
						+ img->sp_screen)) * img->sp_width / img->sp_w) / 256;
		if (img->tex_x < 0)
			img->tex_x = 0;
		if (img->tex_y < 0)
			img->tex_y = 0;
		if (img->drawstartx < img->swidth && img->transy > 0 &&
			img->drawstartx > 0 && img->transy < img->zbuffer[img->drawstartx])
		{
			while (++i < img->drawendy && i < img->sheight)
			{
				img->calc = i * 256 - img->sheight * 128 + img->sp_h * 128;
				draw_sprite_next(img);
				if ((img->color & 0xffffff) != 0 && img->swidth *
						img->sheight > i * img->swidth + img->drawstartx)
					img->addr[i * img->swidth +
						img->drawstartx] = img->color;
			}
		}
		img->drawstartx++;
	}
}
