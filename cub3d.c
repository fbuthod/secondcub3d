/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/cub3d.h"

void	fps_count(t_data *img)
{
	char	*fps;

	fps = NULL;
	img->oldtime = img->time;
	img->time = clock();
	img->frametime = (img->time - img->oldtime) / 1000000;
	if (img->frametime > 0)
		fps = ft_itoa(1.0 / img->frametime);
	mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x000000, "FPS :");
	mlx_string_put(img->mlx, img->mlx_win, 66, 25, 0x000000, fps);
}

int		main(int ac, char **av)
{
	t_data	img[1];

	ft_init(img);
	if (check_arg(ac, av, img) != 0)
		return (0);
	parser(img, av[1]);
	check_map(img);
	window_init(img);
	camera_init(img);
	fps_count(img);
	if (!(img->zbuffer = malloc(sizeof(double) * img->swidth)))
		return (0);
	init_texture(img);
	display(img);
	mlx_hook(img->mlx_win, 2, (1L << 0), event_key_down, img);
	mlx_hook(img->mlx_win, 3, (1L << 1), event_key_up, img);
	mlx_loop_hook(img->mlx, calculate, (void *)img);
	mlx_loop(img->mlx);
	return (0);
}
