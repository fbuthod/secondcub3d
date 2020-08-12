/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	bitmap_image(t_data *img, int fd, t_bpm2 bitinf)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bitinf, sizeof(bitinf));
	y = img->sheight - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img->swidth)
		{
			ble = img->addr[y * img->swidth + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
}

void		save_bitmap(char *filename, t_data *img)
{
	int		fd;
	t_bpm	bitheader;
	t_bpm2	bitinf;

	ft_memcpy(&bitheader.bitmap_type, "BM", 2);
	bitheader.file_size = img->swidth * img->sheight * 4 + 54;
	bitheader.reserved1 = 0;
	bitheader.reserved2 = 0;
	bitheader.offset_bits = 0;
	bitinf.size_header = sizeof(bitinf);
	bitinf.width = img->swidth;
	bitinf.height = img->sheight;
	bitinf.planes = 1;
	bitinf.bit_count = 32;
	bitinf.compression = 0;
	bitinf.image_size = img->swidth * img->sheight * 4 + 54;
	bitinf.ppm_x = 2;
	bitinf.ppm_y = 2;
	bitinf.clr_used = 0;
	bitinf.clr_important = 0;
	fd = open(filename, O_RDONLY | O_CREAT, S_IRWXU);
	close(fd);
	fd = open(filename, O_RDWR);
	write(fd, &bitheader, 14);
	bitmap_image(img, fd, bitinf);
}
