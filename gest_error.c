/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	gest_error_next(t_data *img, int code_erreur, int i)
{
	if (code_erreur > 0 && code_erreur < 7)
		printf("Error\nTexture invalide");
	if (code_erreur > 1)
		mlx_destroy_image(img->mlx, img->img_no_ptr);
	if (code_erreur > 2)
		mlx_destroy_image(img->mlx, img->img_so_ptr);
	if (code_erreur > 3)
		mlx_destroy_image(img->mlx, img->img_we_ptr);
	if (code_erreur > 4)
		mlx_destroy_image(img->mlx, img->img_ea_ptr);
	if (code_erreur > 5)
		mlx_destroy_image(img->mlx, img->sprite_ptr);
	i = -1;
	if (img->wmap != NULL)
		while (img->wmap[++i])
			ft_memdel((void*)&img->wmap[i]);
	ft_memdel((void*)&img->wmap);
}

void	gest_error(t_data *img, int code_erreur)
{
	int i;

	i = -1;
	if (code_erreur != 0)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_image(img->mlx, img->img);
		ft_memdel((void *)&(img->sp_order));
		ft_memdel((void *)&(img->sp_dist));
		ft_memdel((void *)&(img->east));
		ft_memdel((void *)&(img->north));
		ft_memdel((void *)&(img->south));
		ft_memdel((void *)&(img->west));
		ft_memdel((void *)&(img->sprite));
		ft_memdel((void *)&(img->zbuffer));
	}
	gest_error_next(img, code_erreur, i);
	exit(1);
}
