/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/05 17:50:58 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>



int	ft_x(int x, int y)
{
	return (x - y);
}

int	ft_y(int x, int y)
{
	return ((x + y) / 2);
}





int main(int argc, char *argv[])
{

	void *mlx_ptr;
	void *win_ptr;
	float i;
	int x;
	int y;
	int angle;
	int width;


	angle = 1;
	width = 200;
	x = 500;
	y = 200;
	i = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "coucou");
	while (++i < width)
	{

		/*
		   mlx_pixel_put(mlx_ptr, win_ptr, i - place, (i + place) / 2, 2551000);
		   mlx_pixel_put(mlx_ptr, win_ptr, i - (place + width), (i + place + width) / 2, 2551000);
		   mlx_pixel_put(mlx_ptr, win_ptr, place - i, (i + place) / 2, 2551000);
		   mlx_pixel_put(mlx_ptr, win_ptr, (place + width - i), (i + place + width) / 2, 2551000);
		   */
		mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y), ft_y(x + i, y), 2551000);
		mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + width), ft_y(x + i, y + width), 2551000);
		mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x, y + i), ft_y(x, y + i), 2551000);
		mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + width, y + i) , ft_y(x + width, y + i), 2551000);
		if (i < width / 2)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + i / 2, 2551000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (((width / 2) / 2) - ((i - width / 2) / 2)), 2551000);
		if (i < width / 2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/6), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/6) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/7), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/7) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/8), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/8) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/9), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/9) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/10), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/10) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/11), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 12/11) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 13/6), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 13/6) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 14/6), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 14/6) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 15/6), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 15/6) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 17/6) + 1, 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 17/6) + 1, 2551000);
		}
		else
		{
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (((width / 2) * (12/6)) - ((i - width / 2) * (12/6))), 2551000);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), (ft_y(x + i, y + 100) + (((width / 2) * (12/6)) - ((i - width / 2) * (12/6)))) + 1, 2551000);
		}
		if (i < width / 2)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - i *  2, 2551000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - (((width / 2) * 2) - ((i - width / 2) * 2)), 2551000);
		if (i < width / 2)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - i / 2, 2551000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - (((width / 2) / 2 ) - ((i - width / 2) / 2)), 2551000);
	}
	mlx_loop(mlx_ptr);
	return 0;
}
