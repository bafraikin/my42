/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:28 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/23 12:35:21 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

int					get_next_line(const int fd, char **line);

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
	int				r;
	int				tot;
	int				mod;
	char			*pl;
	char			*buff;
	char			*is_r;
	char			*tmp;
	t_list			*old;
}					t_read;

#endif
