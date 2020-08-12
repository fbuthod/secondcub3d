/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	dda_algorithm(t_data *img)
{
	img->hit = 0;
	while (img->hit == 0)
	{
		if (img->sidedistx <= img->sidedisty)
		{
			img->sidedistx += img->deltadistx;
			img->mapx += img->stepx;
			img->side = 1;
		}
		else
		{
			img->sidedisty += img->deltadisty;
			img->mapy += img->stepy;
			img->side = 0;
		}
		if (img->wmap[img->mapy][img->mapx] == '1')
			img->hit = 1;
	}
}

void	fisheye_adjustment(t_data *img)
{
	if (img->side == 1)
		img->perpwalldist = ((img->mapx - img->posx +
					(1 - img->stepx) / 2) / img->raydirx);
	else
		img->perpwalldist = ((img->mapy - img->posy +
					(1 - img->stepy) / 2) / img->raydiry);
}

void	height_wall(t_data *img)
{
	img->lineheight = (int)(img->sheight / img->perpwalldist);
}

void	fill_stripe(t_data *img)
{
	img->drawstart = (-img->lineheight / 2) + (img->sheight / 2);
	if (img->drawstart < 0)
		img->drawstart = 0;
	img->drawend = (img->lineheight / 2) + (img->sheight / 2);
	if (img->drawend >= img->sheight)
		img->drawend = img->sheight - 1;
}
