/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void		ft_check_space_next_3(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == 'N') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == 'N') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
		img->wmap[i][j + 2] == 'N') || (img->wmap[i + 1] != '\0' && (int)
		ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == 'N'))
	{
		ft_putstr("Error\nErreur de la map : un espace et un ");
		ft_putstr("| N | ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->wmap[i - 1] != '\0' && (int)ft_strlen(img->wmap[i
		- 1]) >= j && img->wmap[i - 1][j] == 'S') || ((j - 2) >= 0 && img->wmap
		[i][j - 2] == 'S') || ((j + 2) <= (int)ft_strlen(img->wmap[i]) &&
		img->wmap[i][j + 2] == 'S') || (img->wmap[i + 1] != '\0' && (int)
		ft_strlen(img->wmap[i + 1]) >= j && img->wmap[i + 1][j] == 'S'))
	{
		ft_putstr("Error\nErreur de la map : un espace et un ");
		ft_putstr("| S | ne peuvent pas etre cote a cote...\n");
		gest_error(img, 0);
	}
}

int			ft_all_line2(t_data *img, int i, int k)
{
	while (img->wmap[i][++k])
	{
		if (img->wmap[i][k] != '1' && img->wmap[i][k] != ' ')
		{
			ft_putstr("Error\nErreur de la map : manque un 1 a la fin ");
			ft_putstr("de la ligne...\n");
			gest_error(img, 0);
		}
	}
	return (i);
}
