/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_data	*resolution_fill(t_data *bag, char *line)
{
	int i;

	i = 1;
	bag->swidth = ft_atoi(line + i);
	if (bag->swidth > 1920)
		bag->swidth = 1920;
	i++;
	while (ft_isdigit(line[i]))
		i++;
	bag->sheight = ft_atoi(line + i);
	if (bag->sheight > 1080)
		bag->sheight = 1080;
	return (bag);
}
