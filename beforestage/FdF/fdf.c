/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/04 19:57:14 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

/*	
	int	tarace(void *param)
	{
	t_fdf *win = (t_fdf*)param;
	usleep(100000);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->x + win->i++, win->y + 100, 2552111);
	return (1);
	}
 *
 *
 *
 *
 *
 *
 *	while (++i < win.width)
 {
 mlx_pixel_put(win.mlx_ptr, win.win_ptr, i - place, (i + place) / 2, 2551000);
 mlx_pixel_put(win.mlx_ptr, win.win_ptr, i - (place + win.width), (i + place + win.width) / 2, 2551000);
 mlx_pixel_put(win.mlx_ptr, win.win_ptr, place - i, (i + place) / 2, 2551000);
 mlx_pixel_put(win.mlx_ptr, win.win_ptr, (place + win.width - i), (i + place + win.width) / 2, 2551000);

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
//	mlx_loop_hook(win.mlx_ptr, tarace, (void*)&win);
//	*/

int	ft_x(int x, int y)
{
	return (x - y);
}

int	ft_y(int x, int y)
{
	return ((x + y) / 2);
}

void	ft_color_it(t_img *img, int x, int y, int color)
{
	int coord;

	if (x >= img->size || y >= img->size)
		return ;
	coord = 4 * x + img->size_line * y;
	img->data[coord] = color / 1000000 % 1000;
	img->data[coord + 1] = color / 1000 % 1000;
	img->data[coord + 2] = color % 1000;
	//ft_color_it(&img, 0, 0, 255255255);
}

int main(int argc, char *argv[])
{
	t_pars	*pars;
	t_mlx	mlx;
	t_img	img;
	int fd;
	int lol;
	int tmp;
	int i;
	int j;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	pars = ft_parse_map(fd);


	img.size = (pars->nb_l > pars->size_l) ? pars->nb_l * 30 : pars->size_l * 30;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, pars->size_l * 30, pars->nb_l * 30, "coucou");
	img.ptr = mlx_new_image(mlx.ptr, img.size, img.size);
	img.data = mlx_get_data_addr(img.ptr, &(img.bbp), &(img.size_line), &(img.endian));

	fd = -1;
	while (++fd <= pars->nb_l * 20 && (lol = 0) == 0)
	{
		tmp = fd;
		fd = 0;
		while (fd <= pars->size_l * 20 )
		{
			i = (((fd / 20) % 20 == 0) && fd > pars->size_l) ? pars->size_l - 1 : (fd / 20) % 20;
			j = (((tmp / 20) % 20 == 0) && tmp > pars->nb_l) ? pars->nb_l - 1 : (tmp / 20) % 20;
			printf("%d %d %d %d\n", i, j, tmp, pars->nb_l);

			if (i < pars->size_l - 1 && j < pars->nb_l)
				lol = (pars->map[j][i] != 0 && pars->map[j][i + 1] != 0) ? 1 : lol;
		/*	else
				lol = (pars->map[j][i] != 0) ? 1 : lol;
				*/
			if (((fd++ % 20 == 0) || (tmp % 20 == 0)) && lol)
				ft_color_it(&img, fd, tmp, 255255255);
			else if (((fd - 1 ) % 20 == 0) || (tmp % 20 == 0))
				ft_color_it(&img, fd, tmp, 255200155);
		}
		fd = tmp;
	}


	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 5, 5);
	mlx_loop(mlx.ptr);

	fd = 0;
	while (pars->map[fd])
		free(pars->map[fd++]);
	free(pars->map);

	/*


*/
	return (0);
}
