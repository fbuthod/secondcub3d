/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ray_pos_dir(t_data *img)
{
	img->camerax = (2 * img->x) / (double)img->swidth - 1;
	img->raydirx = img->dirx + img->planex * img->camerax;
	img->raydiry = img->diry + img->planey * img->camerax;
}

void	case_detect(t_data *img)
{
	img->mapx = (int)(img->posx);
	img->mapy = (int)(img->posy);
}

void	ray_len(t_data *img)
{
	img->deltadistx = fabs(1 / img->raydirx);
	img->deltadisty = fabs(1 / img->raydiry);
}
