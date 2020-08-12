/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	move_next_next_next(t_data *img, double olddirx, double oldplanex)
{
	if (img->move_directional_right == 1)
	{
		img->posy += img->planey * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posy -= img->planey * img->movespeed;
		img->posx += img->planex * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posx -= img->planex * img->movespeed;
	}
	if (img->rotation_left == 1)
	{
		olddirx = img->dirx;
		img->dirx = img->dirx * cos(-img->rotspeed) -
			img->diry * sin(-img->rotspeed);
		img->diry = olddirx * sin(-img->rotspeed) +
			img->diry * cos(-img->rotspeed);
		oldplanex = img->planex;
		img->planex = img->planex * cos(-img->rotspeed) -
			img->planey * sin(-img->rotspeed);
		img->planey = oldplanex * sin(-img->rotspeed) +
			img->planey * cos(-img->rotspeed);
	}
}

void	move_next_next(t_data *img, double olddirx, double oldplanex)
{
	if (img->rotation_right == 1)
	{
		olddirx = img->dirx;
		img->dirx = img->dirx * cos(img->rotspeed) - img->diry *
			sin(img->rotspeed);
		img->diry = olddirx * sin(img->rotspeed) + img->diry *
			cos(img->rotspeed);
		oldplanex = img->planex;
		img->planex = img->planex * cos(img->rotspeed) - img->planey
			* sin(img->rotspeed);
		img->planey = oldplanex * sin(img->rotspeed) + img->planey
			* cos(img->rotspeed);
	}
	if (img->move_directional_left == 1)
	{
		img->posy -= img->planey * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posy += img->planey * img->movespeed;
		img->posx -= img->planex * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posx += img->planex * img->movespeed;
	}
	move_next_next_next(img, olddirx, oldplanex);
}

void	move_next(t_data *img, double olddirx, double oldplanex)
{
	olddirx = (double)olddirx;
	oldplanex = (double)oldplanex;
	if (img->move_up == 1)
	{
		img->posy += img->diry * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posy -= img->diry * img->movespeed;
		img->posx += img->dirx * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posx -= img->dirx * img->movespeed;
	}
	move_next_next(img, olddirx, oldplanex);
}

void	move(t_data *img)
{
	double olddirx;
	double oldplanex;

	olddirx = 0;
	oldplanex = 0;
	img->movespeed = img->frametime * 3.0;
	img->rotspeed = img->frametime * 3.0;
	if (img->move_down == 1)
	{
		img->posy -= img->diry * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posy += img->diry * img->movespeed;
		img->posx -= img->dirx * img->movespeed;
		if (img->wmap[(int)(img->posy)][(int)(img->posx)] == '1' ||
			img->wmap[(int)(img->posy)][(int)(img->posx)] == '2')
			img->posx += img->dirx * img->movespeed;
	}
	move_next(img, olddirx, oldplanex);
}
