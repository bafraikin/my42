/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/07 15:15:55 by bafraiki         ###   ########.fr       */
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
//
//
//

while (++fd <= pars->nb_l * img.pbc)
{
tmp = fd;
fd = 0;
while (fd <= pars->size_l * img.pbc)
{

i = (((fd / img.pbc) % pars->size_l == 0) && fd > pars->size_l) ? pars->size_l - 1 : (fd / img.pbc) % pars->size_l;
j = (((tmp / img.pbc) % pars->nb_l == 0) && tmp > pars->nb_l) ? pars->nb_l - 1 : (tmp / img.pbc) % pars->nb_l;
if (i < pars->size_l - 1 && j < pars->nb_l)
lol = (pars->map[j][i] != 0 && pars->map[j][i + 1] != 0) ? 1 : 0;
else if (i < pars->size_l && j < pars->nb_l - 1)
lol = (pars->map[j][i] != 0 && pars->map[j + 1][i] != 0) ? 1 : lol;
//////////////
if (((fd % img.pbc == 0) || (tmp % img.pbc == 0)) && lol)
ft_color_it(&img, fd, tmp, 0 + 10 * pars->map[j][i]);
else if (((fd) % img.pbc == 0) || (tmp % img.pbc == 0))
ft_color_it(&img, fd, tmp, 255200155);
/////////////
if (((fd % img.pbc == 0) || (tmp % img.pbc == 0)) && lol)
	ft_color_it(&img, ft_x(fd, tmp), ft_y(fd, tmp), 0 + 10 * pars->map[j][i]);
else if (((fd) % img.pbc == 0) || (tmp % img.pbc == 0))
	ft_color_it(&img, ft_x(fd, tmp), ft_y(fd, tmp), 255200155);
	/////////////
	fd++;
	}
fd = tmp;
}
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

void	ft_fill_pnt(t_pnt *to_fill, int y, int x, int z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}

int	ft_multiply(int y, int x)
{
	return (y * x);
}

int	ft_divide(int y, int x)
{
	return (y / x);
}

int	ft_add(int y, int x)
{
	return (y + x);
}

void ft_cal_pnt(t_pnt *to_calc, int (*f)(int x, int y), int nb)
{
	to_calc->x = (*f)(to_calc->x, nb);
	to_calc->y = (*f)(to_calc->y, nb);
	to_calc->z = (*f)(to_calc->z, nb);
}

void ft_makeline(t_img *img, t_pnt *pnt1, t_pnt *pnt2)
{
	int 	i;
	t_pnt	diff;
	int		prec;

	i = -1;
	prec = img->prec;
	/*
	ft_fill_pnt(&diff, pnt2->x - pnt1->x,  pnt2->y - pnt1->y,  pnt2->z - pnt1->z);
	ft_cal_pnt(&diff, ft_multiply, img->prec);
	ft_cal_pnt(&diff, ft_divide, img->pbc);
*/
	pnt2->z /= img->pbc;
	pnt1->z /= img->pbc;
	diff.x = (pnt2->x - pnt1->x) * prec / img->pbc;
	diff.y = (pnt2->y - pnt1->y) * prec / img->pbc;
	diff.z = (pnt2->z  - pnt1->z) * prec / img->pbc;
	ft_cal_pnt(pnt1, ft_multiply, prec);
	while (pnt1->x < pnt2->x * prec || pnt1->y < pnt2->y * prec)
	{
		pnt1->x += diff.x;
		pnt1->y += diff.y;
		pnt1->z += diff.z;
		int	x = ft_x(pnt1->x, pnt1->y);
		int	y = ft_y(pnt1->x, pnt1->y);
		ft_color_it(img, pnt1->x / prec, (pnt1->y / prec + (pnt1->z / prec)  * 3 * -1),  150 +  255 + pnt1->z / prec * 25000);
	}
}

int main(int argc, char *argv[])
{
	t_pars	*pars;
	t_mlx	mlx;
	t_img	img;
	int fd;
	t_pnt pnt[2];
	int i;
	int j;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	pars = ft_parse_map(fd);

	img.prec = 10000;
	img.pbc = (pars->nb_l > pars->size_l) ? 900 / pars->nb_l / 2 :  1250 / pars->size_l / 2 ;
	img.size = (pars->nb_l > pars->size_l) ? 1500 : 1250;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1500, 1250, "coucou");
	img.ptr = mlx_new_image(mlx.ptr, img.size, img.size);
	img.data = mlx_get_data_addr(img.ptr, &(img.bbp), &(img.size_line), &(img.endian));
	i = -1;
	while (++i < pars->nb_l && (j = -1) < 0)
	{
		while (++j < pars->size_l - 1)
		{	
			ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]);
			ft_cal_pnt(&pnt[0], &ft_multiply, img.pbc);
			ft_fill_pnt(&pnt[1], i, j + 1, pars->map[i][j + 1]);
			ft_cal_pnt(&pnt[1], &ft_multiply, img.pbc);
			ft_makeline(&img, &pnt[0], &pnt[1]);

			if (i < pars->nb_l - 1)
			{
			ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]);
			ft_cal_pnt(&pnt[0], &ft_multiply, img.pbc);
			ft_fill_pnt(&pnt[1], i + 1, j, pars->map[i + 1][j]);
			ft_cal_pnt(&pnt[1], &ft_multiply, img.pbc);
			ft_makeline(&img, &pnt[0], &pnt[1]);
			}
		}
		if (i < pars->nb_l - 1)
		{
			ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]);
			ft_cal_pnt(&pnt[0], &ft_multiply, img.pbc);
			ft_fill_pnt(&pnt[1], i + 1, j, pars->map[i + 1][j]);
			ft_cal_pnt(&pnt[1], &ft_multiply, img.pbc);
			ft_makeline(&img, &pnt[0], &pnt[1]);
		}
	}
	//mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, pars->size_l * img.pbc, pars->nb_l * img.pbc);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 80, 80);
	mlx_loop(mlx.ptr);

	fd = 0;
	while (pars->map[fd])
		free(pars->map[fd++]);
	free(pars->map);
	return (0);
}
