/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void		ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static void	check_space_last2(t_data *img, int error)
{
	if (error == 1)
	{
		ft_putstr("Error\nErreur de la map... Non ferme par un 1\n");
		gest_error(img, 0);
	}
}

static void	check_space_last(t_data *img, int i, int k)
{
	int i2;
	int k2;
	int error;

	i2 = i;
	k2 = k;
	while (img->wmap[i][k] == ' ')
		i--;
	if (img->wmap[i][k] != '1')
		error = 1;
	i = i2;
	k = k2;
	while (img->wmap[i][k] == ' ')
		k--;
	if (img->wmap[i][k] != '1')
		error = 1;
	i = i2;
	k = k2;
	while (img->wmap[i][k] == ' ')
		k++;
	if (img->wmap[i][k] != '1')
		error = 1;
	check_space_last2(img, error);
}

static void	ft_check_line_next(t_data *img, int i, int k)
{
	if (img->wmap[i][k] == 'N' || img->wmap[i][k] == 'E' ||
		img->wmap[i][k] == 'W' || img->wmap[i][k] == 'S')
	{
		if (++img->wmap_false == 1)
			img->dir_player = img->wmap[i][k];
		img->posx = (double)k;
		img->posy = (double)i;
	}
	if (img->wmap[i][0] == ' ')
	{
		while (img->wmap[i][k] == ' ')
			k++;
	}
	if (img->wmap[i][k] != '0' && img->wmap[i][k] != '1' && img->
		wmap[i][k] != '2' && img->wmap[i][k] != 'N' && img->wmap[i][k]
		!= 'S' && img->wmap[i][k] != 'E' && img->wmap[i][k] != 'W')
	{
		if (img->wmap[i][k] == ' ')
			check_space_last(img, i, k);
		else
		{
			ft_putstr("Error\nErreur de la map...\n");
			gest_error(img, 0);
		}
	}
}

void		ft_check_line(t_data *img, int i, int k)
{
	while (img->wmap[i][k])
	{
		ft_check_line_next(img, i, k);
		if (img->wmap[i][k] == 'N' || img->wmap[i][k] == 'E' ||
			img->wmap[i][k] == 'W' || img->wmap[i][k] == 'S' ||
			img->wmap[i][k] == '0' || img->wmap[i][k] == '2')
		{
			if ((img->wmap[i + 1] != '\0' && (int)ft_strlen(img->wmap
			[i + 1]) <= k) || (img->wmap[i - 1] != '\0' &&
			(int)ft_strlen(img->wmap[i - 1]) <= k))
			{
				ft_putstr("Error\nErreur de la map : a | 0 | 2 |");
				ft_putstr(" N | S | E | W | en dehors de la map...\n");
				gest_error(img, 0);
			}
		}
		if (img->wmap[i][k++] == '2')
			img->sp_nbr++;
	}
	if (img->wmap[i][k - 1] != '1')
	{
		ft_putstr("Error\nErreur de la map : pas de '1'");
		ft_putstr(" a la fin de la ligne...\n");
		gest_error(img, 0);
	}
}
