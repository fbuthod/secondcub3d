/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	texture_no(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posy + img->perpwalldist * img->raydiry;
	else
		img->wallx = img->posx + img->perpwalldist * img->raydirx;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->no_width);
	if (img->side == 0 && img->raydiry > 0)
		img->tex_x = img->no_width - img->tex_x - 1;
	if (img->side == 1 && img->raydirx < 0)
		img->tex_x = img->no_width - img->tex_x - 1;
	img->step = 1.0 * img->no_height / img->lineheight;
	img->texpos = (img->drawstart - img->sheight / 2 + img->lineheight / 2)
	* img->step;
}

static void	texture_so(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posy + img->perpwalldist * img->raydiry;
	else
		img->wallx = img->posx + img->perpwalldist * img->raydirx;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->so_width);
	if (img->side == 0 && img->raydiry > 0)
		img->tex_x = img->so_width - img->tex_x - 1;
	if (img->side == 1 && img->raydirx < 0)
		img->tex_x = img->so_width - img->tex_x - 1;
	img->step = 1.0 * img->so_height / img->lineheight;
	img->texpos = (img->drawstart - img->sheight / 2 + img->lineheight / 2)
	* img->step;
}

static void	texture_we(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posy + img->perpwalldist * img->raydiry;
	else
		img->wallx = img->posx + img->perpwalldist * img->raydirx;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->we_width);
	if (img->side == 0 && img->raydiry > 0)
		img->tex_x = img->we_width - img->tex_x - 1;
	if (img->side == 1 && img->raydirx < 0)
		img->tex_x = img->we_width - img->tex_x - 1;
	img->step = 1.0 * img->we_height / img->lineheight;
	img->texpos = (img->drawstart - img->sheight / 2 + img->lineheight / 2)
	* img->step;
}

static void	texture_ea(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posy + img->perpwalldist * img->raydiry;
	else
		img->wallx = img->posx + img->perpwalldist * img->raydirx;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->ea_width);
	if (img->side == 0 && img->raydiry > 0)
		img->tex_x = img->ea_width - img->tex_x - 1;
	if (img->side == 1 && img->raydirx < 0)
		img->tex_x = img->ea_width - img->tex_x - 1;
	img->step = 1.0 * img->ea_height / img->lineheight;
	img->texpos = (img->drawstart - img->sheight / 2 + img->lineheight / 2)
	* img->step;
}

void		texture(t_data *img)
{
	img->lol = 1;
	if (img->side == 1 && img->stepx < 0)
		texture_ea(img);
	if (img->side == 1 && img->stepx >= 0)
		texture_we(img);
	if (img->side == 0 && img->stepy <= 0)
		texture_so(img);
	if (img->side == 0 && img->stepy > 0)
		texture_no(img);
}
