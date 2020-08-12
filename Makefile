# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 12:37:16 by fbuthod-          #+#    #+#              #
#    Updated: 2020/03/13 19:34:57 by fbuthod-         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    VARIABLES                                 #
# **************************************************************************** #

default: all

OS = $(shell uname)

NAME    =	Cub3D

HEADER	=	includes/cub3d.h

PRINTF	=	libftprintf.a

PRINTFS	=	ft_printf/libftprintf.a

LIBFTS	=	ft_printf/libft/libft.a

SRCS	=	cub3d.c \
			cub3d_utils.c \
			display_functions.c \
			display_functions1.c \
			display_functions2.c \
			display_functions3.c \
			display.c \
			error_functions.c \
			events_keycode.c \
			get_next_line.c \
			get_next_line_utils.c \
			initialize_function.c \
			mouvement_functions.c \
			parser_floor_ceiling.c \
			parser_map.c \
			parser_resolution.c \
			parser_texture.c \
			parser.c \
			init_texture.c \
			texture.c \
			sprite.c \
			screenshot.c \
			gest_error.c \
			check_map.c \
			check_map2.c \
			check_map3.c \
			initialize_function2.c \
			
			

# SRCS	=	test.c

OBJS	=	$(SRCS:.c=.o)

CC 		= clang

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g3 -Iincludes/ -Ift_printf/include/ -Ift_print/libft/

MLX		=	-lmlx -lm -framework OpenGL -framework AppKit

MLX_L	=	-lX11 -lXext -lmlx -lm -lbsd

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all		:	$(NAME) $(HEADER)

%.o		:	%.c $(HEADER)
ifeq (${OS}, Darwin)
	 		$(CC) $(CFLAGS) -c -I./minilibx/ $< -o $@
else
	 		$(CC) $(CFLAGS) -c $< -o $@
endif

$(NAME)	:	$(PRINTF) $(OBJS) $(HEADER)
ifeq (${OS}, Darwin)
			$(MAKE) -C minilibx/ all
endif
ifeq (${OS}, Darwin)
			# ${CC} -o $@ ${OBJS} -L./minilibx/ $(MLX)
			$(CC) $(CFLAGS) -o $@ $(SRCS) $(PRINTFS) -Lminilibx -Lft_printf $(MLX) -fsanitize=leak -g3
else
			# ${CC} -o $@ ${OBJS} -L./minilibx/ $(MLX_L)
			$(CC) $(CFLAGS) -o $@ $(SRCS) $(PRINTFS) -Lminilibx -Lft_printf $(MLX_L)
endif

$(PRINTF)	:
			$(MAKE) -C ft_printf all

clean	:
			$(MAKE) -C ft_printf $@
			$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(LIBFTS)
			$(RM) $(PRINTFS)
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean all re
