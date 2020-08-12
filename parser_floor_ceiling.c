/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	floor_fill(t_data *img, char *line)
{
	t_color	color;
	int		i;

	i = 0;
	color.argb[3] = 0;
	while (!ft_isdigit(line[i]))
		i++;
	color.argb[0] = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	color.argb[1] = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	color.argb[2] = ft_atoi(line + i);
	img->color_floor = color.color;
}

void	ceiling_fill(t_data *img, char *line)
{
	t_color	color;
	int		i;

	i = 0;
	color.argb[3] = 0;
	while (!ft_isdigit(line[i]))
		i++;
	color.argb[0] = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	color.argb[1] = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	color.argb[2] = ft_atoi(line + i);
	img->color_ceiling = color.color;
}
