/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:38:49 by ksam              #+#    #+#             */
/*   Updated: 2020/03/06 02:19:53 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 512
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_line
{
	char			*buffer_read;
	char			*buffer_temp;
	char			*buffer_stock;
	int				a_read;
	int				b_index;
}					t_line;

int					get_next_line(const int fd, char **line);
int					end_condition(t_line *list, char **line);
int					buffer_update(t_line *list, char **line);
int					ft_strichr(const char *s, int c);

size_t				gnl_strlen(const char *s);
void				*gnl_memset(void *b, int c, size_t len);
void				*gnl_calloc(size_t count, size_t size);
char				*gnl_strjoin(char *s1, char *s2);
char				*gnl_substr(char *s, unsigned int start, size_t len);

#endif
