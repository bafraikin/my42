/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:30:21 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/27 21:03:08 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_degrade(char *data, float *diff, short index)
{
	if (*diff == 0 || data[index] == -1)
		return ;
	if (data[index] > data[(index + 1) % 3]
			&& data[index] > data[(index + 2 % 3)])
	{
		if (((data[0] + *diff) / 255) >= 1 && (data[0] = -1) < 0)
			*diff -= (255 - data[0]);
		else
		{
			data[0] = data[0] + *diff;
			*diff = 0;
		}
	}
}

void	ft_color_it(t_img *img, int x, int y, t_pnt *pnt)
{
	int		coord;
	int		color;
	int		i;
	float	diff;

	diff = (pnt->z / img->prec - 0) * img->degrad;
	color = img->color;
	x = x / img->prec + img->d_x;
	y = y / img->prec + (pnt->z / img->prec) / (img->f) * -1 + img->d_y;
	if (x >= img->size || y >= img->size || y < 0 || x < 0)
		return ;
	coord = 4 * x + img->size_line * y;
	img->data[coord + 0] = 0xff & img->color;
	img->data[coord + 1] = ((0xff00 & img->color) >> 8);
	img->data[coord + 2] = ((0xff0000 & img->color) >> 16);
	i = -1;
	while (++i <= 2 && diff != 0)
	{
		ft_make_degrade(&img->data[coord], &diff, 0);
		ft_make_degrade(&img->data[coord], &diff, 1);
		ft_make_degrade(&img->data[coord], &diff, 2);
	}
}

int		rgb_to_hex(int rgb[3])
{
	char	*hex;
	char	h[6];
	int		b;
	int		r;
	int		i;

	r = 0;
	hex = "0123456789abcdef";
	i = -1;
	while (++i <= 2 && (h[i * 2] = hex[rgb[i] / 16]) >= 0)
		h[i * 2 + 1] = hex[(rgb[i] / 16) / 16];
	i = 6;
	while (--i >= 0 && (b = pow(16, 5 - i)) >= 1)
		r += (h[i] >= '0' && h[i] <= '9') ? (h[i] - 48) * b : (h[i] - 87) * b;
	return (r);
}

int		give_me_color(int nb)
{
	int		ij[4];
	int		space;
	short	order[5];
	int		rgb[3];
	int		boolean;

	order[0] = 1;
	order[1] = 0;
	order[2] = 2;
	order[3] = 1;
	order[4] = 0;
	rgb[0] = 160;
	rgb[1] = 0;
	rgb[2] = 0;
	ij[2] = 0;
	ij[3] = 160;
	space = 4;
	ij[0] = -1;
	while (++ij[0] < nb && (ij[1] = order[ij[0] / 40]) >= 0)
	{
		if (rgb[ij[1]] <= ij[2] || rgb[ij[1]] >= ij[3])
			boolean = (rgb[ij[1]] == ij[2]) ? 1 : 0;
		rgb[ij[1]] += (boolean) ? space : -space;
	}
	return (rgb_to_hex(rgb));
}
