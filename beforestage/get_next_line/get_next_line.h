/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:28 by bafraiki          #+#    #+#             */
/*   Updated: 2018/11/27 14:01:14 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>

# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_fd
{
	char			*l_line; //not_sure
	char			*l_rest; //not_sure
	char			*old_line;
	char			*old_rest;
	int				size_line;
	int				size_rest;
	int				mode;
	int				fd;
}					t_fd;

typedef struct		s_read
{
	int				r;
	int				tot;
	int				mod;
	char			*pl;  //not a str
	char			*buff; //free
	char			*is_r;
	char			*tmp; //free
	void			*old; //pas a lui
}					t_read;

#endif
