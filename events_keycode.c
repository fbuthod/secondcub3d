/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		event_key_down(int keycode, t_data *img)
{
	img->nb_down_key += 1;
	if (keycode == 119 || keycode == KEY_W)
		img->move_up = 1;
	else if (keycode == 115 || keycode == KEY_S)
		img->move_down = 1;
	if (keycode == 124 || keycode == KEY_LEFT)
		img->rotation_left = 1;
	else if (keycode == 123 || keycode == KEY_RIGHT)
		img->rotation_right = 1;
	if (keycode == 97 || keycode == KEY_A)
		img->move_directional_left = 1;
	else if (keycode == 100 || keycode == KEY_D)
		img->move_directional_right = 1;
	return (0);
}

int		event_key_up(int keycode, t_data *img)
{
	if (keycode == 65307)
		close_window(img);
	img->nb_down_key -= 1;
	if (keycode == 119 || keycode == KEY_W)
		img->move_up = 0;
	else if (keycode == 115 || keycode == KEY_S)
		img->move_down = 0;
	if (keycode == 124 || keycode == KEY_LEFT)
		img->rotation_left = 0;
	else if (keycode == 123 || keycode == KEY_RIGHT)
		img->rotation_right = 0;
	if (keycode == 97 || keycode == KEY_A)
		img->move_directional_left = 0;
	else if (keycode == 100 || keycode == KEY_D)
		img->move_directional_right = 0;
	return (0);
}

int		calculate(t_data *img)
{
	move(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	display(img);
	fps_count(img);
	return (0);
}
