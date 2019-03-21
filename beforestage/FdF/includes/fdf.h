/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:17:46 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/21 12:24:42 by bafraiki         ###   ########.fr       */
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
	int color;
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
void	int_to_hex(int color, char hex[6]);
void	ft_color_it(t_img *img, int x, int y, t_pnt *pnt);
int		rgb_to_hex(int rgb[3]);
int		give_me_color(int nb);

#endif /* ifndef FDF_H */
