/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	calculate_sort_dist(t_data *img)
{
	int			i;
	int			j;
	int			tmp;
	double		tmp1;

	j = 0;
	i = -1;
	while (++i < img->sp_nbr)
	{
		j = i - 1;
		while (++j < img->sp_nbr)
		{
			if (img->sp_dist[i] < img->sp_dist[j])
			{
				tmp = img->sp_order[i];
				img->sp_order[i] = img->sp_order[j];
				img->sp_order[j] = tmp;
				tmp1 = img->sp_dist[i];
				img->sp_dist[i] = img->sp_dist[j];
				img->sp_dist[j] = tmp1;
				i = -1;
				j = img->sp_nbr;
			}
		}
	}
}

static void	calculate_sprite_dist(t_data *img, t_sprites *sprites, int k)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (img->wmap[++i] != '\0')
	{
		j = -1;
		while (img->wmap[i][++j] != '\0')
			if (img->wmap[i][j] == '2')
			{
				sprites[k].y = i + 0.5;
				sprites[k++].x = j + 0.5;
			}
	}
	i = -1;
	while (++i < img->sp_nbr)
	{
		img->sp_order[i] = i;
		img->sp_dist[i] = ((img->posx - sprites[i].x) * (img->posx -
			sprites[i].x) + (img->posy - sprites[i].y) * (img->posy -
			sprites[i].y));
	}
	calculate_sort_dist(img);
}

static void	calculate_sprite_next(t_data *img)
{
	if (img->drawstarty < 0)
		img->drawstarty = 0;
	img->drawendy = img->sp_h / 2 + img->sheight / 2;
	if (img->drawstarty >= img->sheight)
		img->drawstarty = img->sheight - 1;
	img->sp_w = abs((int)(img->sheight / (img->transy)));
	img->drawstartx = -img->sp_w / 2 + img->sp_screen;
	if (img->drawstartx < 0)
		img->drawstartx = 0;
	img->drawendx = img->sp_w / 2 + img->sp_screen;
	if (img->drawendx >= img->swidth)
		img->drawendx = img->swidth - 1;
}

void		calculate_sprite(t_data *img, int x)
{
	int			k;
	t_sprites	*sprites;

	k = 0;
	sprites = malloc(sizeof(t_sprites) * (img->sp_nbr + 1));
	calculate_sprite_dist(img, sprites, k);
	x = (int)x;
	img->sp_x = sprites[img->sp_order[x]].x - img->posx;
	img->sp_y = sprites[img->sp_order[x]].y - img->posy;
	img->inv_det = 1.0 / (img->planex * img->diry - img->dirx *
		img->planey);
	img->transx = img->inv_det * (img->diry * img->sp_x - img->dirx
		* img->sp_y);
	img->transy = img->inv_det * (-img->planey * img->sp_x +
		img->planex * img->sp_y);
	img->sp_screen = (int)((img->swidth / 2) * (1 + img->transx /
		img->transy));
	img->sp_h = abs((int)(img->sheight / img->transy));
	img->drawstarty = -img->sp_h / 2 + img->sheight / 2;
	calculate_sprite_next(img);
}
