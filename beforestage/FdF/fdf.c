/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/05 16:39:48 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>



int	ft_x(x, y)
{
	return (x - y);
}

int	ft_y(x, y)
{
	return ((x + y) / 2);
}





int main(int argc, char *argv[])
{

	void *mlx_ptr;
	void *win_ptr;
	int i;
	int x;
	int y;
	int width;


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
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - i / 2, 2551000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - (((width / 2) / 2 ) - ((i - width / 2) / 2)), 2551000);
	}
	mlx_loop(mlx_ptr);
	return 0;
}
