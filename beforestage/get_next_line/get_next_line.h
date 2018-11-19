/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:28 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/19 14:29:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>

# include <fcntl.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fdlin
{
	char			*l_line;
	char			*l_rest;
	int				size_line;
	int				size_rest;
	int				mode;
	int				fd;
}					t_fdlin;

typedef struct		s_read
{
	int				ret;
	int				total;
	int				mode;
	char			*ptr_l;
	char			*is_read;
	char			*tmp;
}					t_read;

#endif
