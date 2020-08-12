/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:51:43 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 23:02:01 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/include/libftprintf.h"
# include "../includes/get_next_line.h"
# include "key_linux.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>

typedef struct		s_data
{
	int				lol;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				move_up;
	int				move_down;
	int				rotation_left;
	int				rotation_right;
	int				move_directional_left;
	int				move_directional_right;
	int				nb_down_key;
	int				x;
	int				i;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	int				color_ceiling;
	int				color_floor;
	double			movespeed;
	double			rotspeed;
	double			frametime;
	int				swidth;
	int				sheight;
	int				floor_color_r;
	int				floor_color_g;
	int				floor_color_b;
	int				ceiling_color_r;
	int				ceiling_color_g;
	int				ceiling_color_b;
	char			**wmap;
	int				countline;
	char			*cardinal;
	int				tracked;
	void			*img_ptr;
	int				*img_data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				*data_sprite;
	int				texwidth;
	int				texheight;
	int				size_line;
	void			*img_no_ptr;
	void			*img_so_ptr;
	void			*img_we_ptr;
	void			*img_ea_ptr;
	void			*sprite_ptr;
	int				no_width;
	int				no_height;
	int				so_width;
	int				so_height;
	int				we_width;
	int				we_height;
	int				ea_width;
	int				ea_height;
	int				sp_width;
	int				sp_height;
	int				sp_w;
	int				sp_h;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	char			*path_to_sprite_texture;
	double			wallx;
	int				tex_x;
	int				tex_y;
	double			texpos;
	double			step;
	double			*zbuffer;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				sp_screen;
	double			transx;
	double			transy;
	double			inv_det;
	double			sp_x;
	double			sp_y;
	int				sp_nbr;
	int				*sp_order;
	double			*sp_dist;
	size_t			calc;
	char			dir_player;
	int				wmap_false;
	int				screenshot;
}					t_data;

typedef	union
{
	int				color;
	char			argb[4];
}					t_color;

typedef struct		s_sprites
{
	double		x;
	double		y;
}					t_sprites;

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

int					main(int ac, char **av);
void				test(t_data *img);
void				move_directional_right(t_data *img);
void				move_directional_left(t_data *img);
void				fps_count(t_data *img);
void				parser(t_data *img, char *av);
int					parsing_map(char *line, t_data *bag);
int					count_valid_char(char *line);
void				floor_fill(t_data *img, char *line);
void				ceiling_fill(t_data *img, char *line);
t_data				*no_texture_fill(t_data *img, char *line);
t_data				*so_texture_fill(t_data *img, char *line);
t_data				*we_texture_fill(t_data *img, char *line);
t_data				*ea_texture_fill(t_data *img, char *line);
t_data				*sprite_texture_fill(t_data *bag, char *line);
int					find_dot(char *line);
t_data				*resolution_fill(t_data *bag, char *line);
void				if_forest(t_data *bag, char *line);
int					check_arg(int argc, char **argv, t_data *img);
int					find_cub_extension(char *target);
void				parse_init(t_data *img);
void				camera_init(t_data *bag);
void				display_init(t_data *img);
void				ft_init(t_data *img);
void				window_init(t_data *img);
void				display(t_data *img);
void				setup_raytracer(t_data *img);
void				ray_pos_dir(t_data *img);
void				case_detect(t_data *img);
void				ray_len(t_data *img);
void				step_side_distance(t_data *img);
void				calcul_stepx(t_data *img);
void				calcul_stepy(t_data *img);
void				dda_calculs(t_data *img);
void				dda_algorithm(t_data *img);
void				fisheye_adjustment(t_data *img);
void				height_wall(t_data *img);
void				fill_stripe(t_data *img);
void				print_wall(t_data *img);
int					close_window(t_data *data);
int					event_key_up(int keycode, t_data *img);
int					event_key_down(int keycode, t_data *img);
void				event_key(int keycode, t_data *img, int code);
int					calculate(t_data *img);
void				move(t_data *img);
void				draw(t_data *img);
void				init_texture(t_data *img);
void				draw_floor_ceiling(t_data *img);
void				texture(t_data *img);
void				calculate_sprite(t_data *img, int x);
void				draw_sprite(t_data *img, int i);
void				alloc_sprite_order(t_data *img);
void				save_bitmap(char *filename, t_data *img);
void				gest_error(t_data *img, int code_erreur);
void				ft_memdel(void **str);
void				exit_texture(t_data *img);
void				ft_putstr(char *s);
void				check_map(t_data *img);
void				ft_check_space(t_data *img, int i, int j);
void				ft_check_line(t_data *img, int i, int k);
void				ft_check_space_next_3(t_data *img, int i, int j);
int					ft_all_line2(t_data *img, int i, int k);

#endif
