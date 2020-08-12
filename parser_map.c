/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>

int		parsing_map(char *line, t_data *bag)
{
	size_t i;

	bag->countline += 1;
	bag->wmap = ft_realloc(bag->wmap, sizeof(char*) * (bag->countline + 1));
	i = count_valid_char(line);
	if (i != ft_strlen(line))
	{
		ft_putstr_fd("Wrong char on map", 2);
		return (0);
	}
	else
		bag->wmap[bag->countline] = ft_strdup(line);
	return (0);
}

int		count_valid_char(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == 'N' ||
	line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\t')
		i++;
	return (i);
}

int		find_dot(char *line)
{
	int i;

	i = 0;
	while (line[i] != '.')
		i++;
	return (i);
}
