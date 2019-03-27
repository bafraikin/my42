/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:17:46 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/27 18:52:18 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct	s_pars
{
	short	**map;
	short	**tmp;
	int		size_l;
	int		nb_l;
}				t_pars;

typedef struct	s_img
{
	int		size;
	void	*ptr;
	char	*data;
	int		bbp;
	int		size_line;
	short	pbc;
	int		prec;
	int		endian;
	int		d_x;
	int		f;
	int		d_y;
	int		angle;
	int		color;
	float	degrad;
}				t_img;

typedef struct	s_color
{
	int		index;
	int		color;
}				t_color;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		height;
	int		width;
	t_img	img;
	t_pars	*pars;
}				t_mlx;

typedef struct	s_pnt
{
	int		x;
	int		y;
	int		z;
}				t_pnt;

t_pars			*ft_parse_map(int fd);
void			int_to_hex(int color, char hex[6]);
void			ft_color_it(t_img *img, int x, int y, t_pnt *pnt);
int				rgb_to_hex(int rgb[3]);
int				give_me_color(int nb);
int				ft_multiply(int y, int x);
int				ft_divide(int y, int x);
int				ft_add(int y, int x);
int				ft_less(int y, int x);
int				pythagore(int x, int y);
t_pnt			*ft_fill_pnt(t_pnt *to_fill, int y, int x, int z);
void			ft_cal_pnt(t_pnt *to_calc, int (*f)(int x, int y), int nb);
void			ft_pnt_vs_pnt(t_pnt *pnt1, int (*f)(int x, int y), t_pnt *pnt2);
int				ft_x(int *rendu, int x, int y);
void			ft_y(int *rendu, int x, int y);
void			byebye(t_mlx *mlx);
void			generate_win(t_mlx *mlx);
void			ft_draw_me_a_sheep(t_pars *pars, t_img *img);
void			free_parsing(t_pars *pars);
void			ft_error(char *str);

#endif
