/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		check_arg_next(int argc, char **argv, t_data *img, char *ptr)
{
	if (argc == 3)
	{
		if ((ptr = ft_strrchr(argv[1], '.')))
		{
			if (find_cub_extension(ptr) != 0)
			{
				printf("Error\nWrong argument.");
				return (-1);
			}
		}
		if (ft_strncmp(argv[2], "--save", 6) == 0)
		{
			img->screenshot = 1;
			return (0);
		}
		else
		{
			ft_printf("Error\nWrong argument.");
			return (-1);
		}
	}
	return (0);
}

int		check_arg(int argc, char **argv, t_data *img)
{
	char *ptr;

	ptr = NULL;
	if (argc > 3)
	{
		ft_printf("Error\nToo many arguments.");
		return (-1);
	}
	if (argc < 2)
	{
		ft_printf("Error\nMap file missing.");
		return (-1);
	}
	if (argc == 2)
	{
		if ((ptr = ft_strrchr(argv[1], '.')))
		{
			if (find_cub_extension(ptr) != 0)
			{
				printf("Error\nWrong argument.");
				return (-1);
			}
		}
	}
	return (check_arg_next(argc, argv, img, ptr));
}

int		find_cub_extension(char *target)
{
	if (ft_strlen(target) != 4)
		return (-1);
	if (target[0] != '.')
		return (-1);
	if (target[1] != 'c' && target[1] != 'C')
		return (-1);
	if (target[2] != 'u' && target[2] != 'U')
		return (-1);
	if (target[3] != 'b' && target[3] != 'B')
		return (-1);
	return (0);
}

void	ft_memdel(void **str)
{
	free(*str);
	*str = NULL;
}
