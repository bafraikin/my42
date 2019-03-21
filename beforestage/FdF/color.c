/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:30:21 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/21 12:29:01 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_to_hex(int color, char hex[6])
{
	int i;
	int result;

	i = -1;
	while (++i <= 5)
	{
		hex[i] = (color) % 16;
		color /= 16;
	}
}

void	ft_color_it(t_img *img, int x, int y, t_pnt *pnt)
{
	int coord;
	char hex[6];

	x = x / img->prec + img->d_x;
	y = y / img->prec + (pnt->z / img->prec) / (img->f) * -1 + img->d_y;
	if (x >= img->size || y >= img->size || y < 0 || x < 0)
		return ;
	coord = 4 * x + img->size_line * y;
	int_to_hex(img->color, hex);
	img->data[coord + 2] = hex[5] * pow(16, 1) + hex[4];
	img->data[coord + 1] = hex[3] * pow(16, 1) + hex[2];
	img->data[coord + 0] = hex[1] * pow(16, 1) + hex[0];
}

int rgb_to_hex(int rgb[3])
{
	char *hex;
	char h[6];
	int b;
	int result;
	int i;

	result = 0;
	hex = "0123456789abcdef";
	i = -1;
	while (++i <= 2 && (h[i * 2] =  hex[rgb[i] / 16]) >= 0)
		h[i * 2 + 1] = hex[(rgb[i] / 16)/ 16];
	i = 6;
	while (--i >= 0 && (b = pow(16, 5 - i)) >= 1)
		result += (h[i] >= '0' && h[i] <= '9') ? (h[i] - 48) * b: (h[i] - 87) * b;
	return (result);
}

int give_me_color(int nb)
{
	int ij[4];
	int space;
	short order[5];
	int rgb[3];
	int boolean;

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
	return(rgb_to_hex(rgb));
}
