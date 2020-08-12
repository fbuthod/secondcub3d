/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_init3(t_data *img)
{
	img->sp_nbr = 5;
	img->screenshot = 0;
	img->floor_color_r = 0;
	img->floor_color_g = 0;
	img->floor_color_b = 0;
	img->ceiling_color_r = 0;
	img->ceiling_color_g = 0;
	img->ceiling_color_b = 0;
	img->wmap = NULL;
	img->countline = -1;
	img->cardinal = NULL;
}

void	ft_init2(t_data *img)
{
	img->time = 0;
	img->oldtime = 0;
	img->planex = 0.66;
	img->planey = 0;
	img->movespeed = 0.05;
	img->rotspeed = 0.1;
	img->nb_down_key = 0;
	img->move_up = 0;
	img->move_down = 0;
	img->rotation_left = 0;
	img->rotation_right = 0;
	img->move_directional_left = 0;
	img->move_directional_right = 0;
	img->south = NULL;
	img->north = NULL;
	img->east = NULL;
	img->west = NULL;
	img->sprite = NULL;
	img->texwidth = -1;
	img->texheight = -1;
	img->tracked = 0;
	img->sp_width = 0;
	img->sp_height = 0;
	ft_init3(img);
}

void	ft_init(t_data *img)
{
	img->mlx = 0;
	img->x = 0;
	img->i = 0;
	img->mapx = 0;
	img->mapy = 0;
	img->sidedistx = 0;
	img->sidedisty = 0;
	img->deltadistx = 0;
	img->deltadisty = 0;
	img->camerax = 0;
	img->rayposx = 0;
	img->rayposy = 0;
	img->raydirx = 0;
	img->raydiry = 0;
	img->perpwalldist = 0;
	img->stepx = 0;
	img->stepy = 0;
	img->hit = 0;
	img->side = 0;
	img->lineheight = 0;
	img->drawstart = 0;
	img->drawend = 0;
	img->color = 0;
	img->frametime = 0;
	ft_init2(img);
}

void	camera_init_next(t_data *bag, int i, int ret)
{
	if (bag->dir_player == 'E')
	{
		bag->dirx = 1;
		bag->diry = 0;
		bag->planex = 0.0;
		bag->planey = 0.66;
	}
	if (bag->dir_player == 'W')
	{
		bag->dirx = -1;
		bag->diry = 0;
		bag->planex = 0.0;
		bag->planey = -0.66;
	}
	if (bag->cardinal != NULL)
	{
		bag->posy = (double)i;
		ret = ft_strichr(bag->wmap[i], bag->cardinal[0]);
		if (ret != -1)
			bag->posx = (double)ret;
		bag->wmap[i][ret] = '0';
	}
}

void	camera_init(t_data *bag)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	if (bag->wmap != NULL)
	{
		if (bag->dir_player == 'N')
		{
			bag->dirx = 0;
			bag->diry = -1;
			bag->planex = 0.66;
			bag->planey = 0.0;
		}
		if (bag->dir_player == 'S')
		{
			bag->dirx = 0;
			bag->diry = 1;
			bag->planex = -0.66;
			bag->planey = 0.0;
		}
		camera_init_next(bag, i, ret);
	}
}
