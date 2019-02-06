/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/06 14:17:23 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

#include <unistd.h>


int	ft_x(int x, int y)
{
	return (x - y);
}

int	ft_y(int x, int y)
{
	return ((x + y) / 2);
}


int	tarace(void *param)
{
	int i;
	t_fdf *win = (t_fdf*)param;
	usleep(100000);
	printf("%d\n", win->i);
	write(1, "coucou\n", 7);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->x + win->i++, win->y + 100, 2552111);
	return (1);
}


int main(int argc, char *argv[])
{

	t_fdf win;
	float i;
	int x;
	int y;

	win.width = 200;
	win.x = 500;
	win.y = 200;
	i = -1;
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 1000, 1000, "coucou");
	while (++i < win.width)
	{
		/*
		   mlx_pixel_put(win.mlx_ptr, win.win_ptr, i - place, (i + place) / 2, 2551000);
		   mlx_pixel_put(win.mlx_ptr, win.win_ptr, i - (place + win.width), (i + place + win.width) / 2, 2551000);
		   mlx_pixel_put(win.mlx_ptr, win.win_ptr, place - i, (i + place) / 2, 2551000);
		   mlx_pixel_put(win.mlx_ptr, win.win_ptr, (place + win.width - i), (i + place + win.width) / 2, 2551000);
		   */
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y), ft_y(x + i, y), 2551000);
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + win.width), ft_y(x + i, y + win.width), 2551000);
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x, y + i), ft_y(x, y + i), 2551000);
		mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + win.width, y + i) , ft_y(x + win.width, y + i), 2551000);
		if (i < win.width / 2)
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + i / 2, 2551000);
		else
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (((win.width / 2) / 2) - ((i - win.width / 2) / 2)), 2551000);
		if (i < win.width / 2)
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 2) + 1, 2551000);
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (i * 2), 2551000);
		}
		else
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) + (((win.width / 2) * (12/6)) - ((i - win.width / 2) * (12/6))), 2551000);
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), (ft_y(x + i, y + 100) + (((win.width / 2) * (12/6)) - ((i - win.width / 2) * (12/6)))) + 1, 2551000);
		}
		if (i < win.width / 2)
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - i *  2, 2551000);
		else
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - (((win.width / 2) * 2) - ((i - win.width / 2) * 2)), 2551000);
		if (i < win.width / 2)
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - i / 2, 2551000);
		else
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, ft_x(x + i, y + 100), ft_y(x + i, y + 100) - (((win.width / 2) / 2 ) - ((i - win.width / 2) / 2)), 2551000);
	}
	mlx_loop_hook(win.mlx_ptr, tarace, (void*)&win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
