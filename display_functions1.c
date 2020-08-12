/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	calcul_stepx(t_data *img)
{
	if (img->raydirx < 0)
	{
		img->stepx = -1;
		img->sidedistx = (img->posx - img->mapx) * img->deltadistx;
	}
	else
	{
		img->stepx = 1;
		img->sidedistx = (img->mapx + 1.0 - img->posx) * img->deltadistx;
	}
}

void	calcul_stepy(t_data *img)
{
	if (img->raydiry < 0)
	{
		img->stepy = -1;
		img->sidedisty = (img->posy - img->mapy) * img->deltadisty;
	}
	else
	{
		img->stepy = 1;
		img->sidedisty = (img->mapy + 1.0 - img->posy) * img->deltadisty;
	}
}
