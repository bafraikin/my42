/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:17:46 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/08 18:14:20 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct	s_pars
{
	short **map;
	short **tmp;
	int size_l;
	int nb_l;
}				t_pars;

typedef struct	s_img
{
	int size;
	void *ptr;
	char *data;
	int bbp;
	int size_line;
	short pbc;
	int prec;
	int endian;
	int d_x;
	int f;
	int d_y;
	int angle;
}				t_img;

typedef struct	s_mlx
{
	void *ptr;
	void *win;
	int height;
	int width;
	t_img img;
	t_pars *pars;
}				t_mlx;


typedef struct	s_pnt
{
	int x;
	int y;
	int z;
}				t_pnt;



t_pars *ft_parse_map(int fd);

#endif /* ifndef FDF_H */
