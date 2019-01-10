/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:04:28 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/10 14:49:42 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_fd
{
	char	*l_line;
	char	*l_rest;
	int		size_line;
	int		size_rest;
	int		mode;
	int		fd;
}					t_fd;

typedef struct		s_read
{
	int		r;
	int		tot;
	int		mod;
	char	*pl;
	char	*buff;
	char	*is_r;
	char	*tmp;
	void	*old;
}					t_read;

#endif
