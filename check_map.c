/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_check_space_next_2(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == 'W') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == 'W') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
			img->wmap[i][j + 2] == 'W') || (img->wmap[i + 1] != '\0' && (int)
				ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == 'W'))
	{
		ft_putstr("Error\nErreur de la map : un espace et un ");
		ft_putstr("| W | ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == '2') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == '2') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
			img->wmap[i][j + 2] == '2') || (img->wmap[i + 1] != '\0' && (int)
				ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == '2'))
	{
		ft_putstr("Error\nErreur de la map : un espace et un ");
		ft_putstr("| 2 | ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
}

static void	ft_check_space_next(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == '0') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == '0') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
			img->wmap[i][j + 2] == '0') || (img->wmap[i + 1] != '\0' && (int)
				ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == '0'))
	{
		ft_putstr("Error\nErreur de la map : un espace et un ");
		ft_putstr("'0' ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == 'E') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == 'E') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
			img->wmap[i][j + 2] == 'E') || (img->wmap[i + 1] != '\0' && (int)
				ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == 'E'))
	{
		ft_putstr("Error\nErreur de la map : un espace et ");
		ft_putstr("un | E | ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
}

void		ft_check_space(t_data *img, int i, int j)
{
	if (img->wmap[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		(int)ft_strlen(img->wmap[i]) && img->wmap[i][j + 1] != ' '))
	{
		ft_putstr("Error\nErreur de la map : il manque un ");
		ft_putstr("espace ou des espaces sont en trop...\n");
		gest_error(img, 0);
	}
	else if (img->wmap[i][j] == ' ' && ((j - 1) >= 0 &&
		img->wmap[i][j - 1] == ' ') && ((j + 1) <= (int)ft_strlen(img->wmap[i])
			&& img->wmap[i][j + 1] == ' '))
	{
		ft_check_space_next(img, i, j);
		ft_check_space_next_2(img, i, j);
		ft_check_space_next_3(img, i, j);
	}
}

static int	ft_all_line(t_data *img, int i, int k)
{
	i = 0;
	k = -1;
	while (img->wmap[1][++k])
	{
		if (img->wmap[1][k] == '0' && img->wmap[0][k] != '1')
		{
			ft_putstr("Error\nErreur de la map : manque un 1 au debut ");
			ft_putstr("de la ligne...\n");
			gest_error(img, 0);
		}
	}
	k = 0;
	while (img->wmap[i])
	{
		ft_check_line(img, i, k);
		k = 0;
		i++;
	}
	i--;
	k = -1;
	return (ft_all_line2(img, i, k));
}

void		check_map(t_data *img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (img->wmap[i] != 0)
	{
		j = 0;
		while (img->wmap[i][j] != 0)
		{
			ft_check_space(img, i, j);
			j++;
		}
		i++;
	}
	i = 0;
	i = ft_all_line(img, i, j);
	alloc_sprite_order(img);
	if (img->wmap_false != 1)
	{
		ft_putstr("Error\nErreur de la map : pas de 1 a la fin de la ligne ||");
		ft_putstr(" plusieurs | N | S | W | E | dans la map...\n");
		gest_error(img, 0);
	}
}
