/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/22 11:08:44 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	ft_x(int *rendu, int x, int y)
{
	*rendu = x - y;
	return (x);
}

void	ft_y(int *rendu, int x, int y)
{
	*rendu = (x + y) / 2;
}

t_pnt	*ft_fill_pnt(t_pnt *to_fill, int y, int x, int z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
	return (to_fill);
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

int	ft_less(int y, int x)
{
	return (y - x);
}

int pythagore(int x, int y)
{
	return (round(sqrt(pow(x, 2) + pow(y, 2))));
}

void ft_cal_pnt(t_pnt *to_calc, int (*f)(int x, int y), int nb)
{
	to_calc->x = (*f)(to_calc->x, nb);
	to_calc->y = (*f)(to_calc->y, nb);
	to_calc->z = (*f)(to_calc->z, nb);
}

void ft_pnt_vs_pnt(t_pnt *pnt1, int (*f)(int x, int y), t_pnt *pnt2)
{
	pnt1->x = (*f)(pnt1->x, pnt2->x);
	pnt1->y = (*f)(pnt1->y, pnt2->y);
	pnt1->z = (*f)(pnt1->z, pnt2->z);
}

void ft_makeline(t_img *img, t_pars *pars, t_pnt *pnt1, t_pnt *pnt2)
{
	int		i;
	t_pnt	diff;
	int 	ratio;
	int		xy[2];

	i = -1;
	diff.z = (pnt2->z  - pnt1->z);
	diff.x = (pnt2->x - pnt1->x);
	diff.y = (pnt2->y - pnt1->y);
	ratio = diff.z != 0 ? pythagore(diff.x, diff.y) : img->pbc;
	img->f = img->f == 0 ? ratio / 2 : img->f;
	ft_cal_pnt(&diff, &ft_multiply, img->prec);
	ft_cal_pnt(&diff, &ft_divide, ratio * img->pbc);
	ft_cal_pnt(pnt1, &ft_multiply, img->prec);
	while (++i < ratio * img->pbc)
	{
		ft_pnt_vs_pnt(pnt1, &ft_add, &diff);
		ft_y(&xy[1], ft_x(&xy[0], pnt1->x, pnt1->y), pnt1->y);
		if (img->angle)
			ft_color_it(img, pnt1->x, pnt1->y, pnt1);
		else
			ft_color_it(img, xy[0], xy[1],  pnt1);
	}
}

void	ft_draw_me_a_sheep(t_pars *pars, t_img *img)
{
	int		i;
	int		j;
	t_pnt	pnt[2];

	i = -1;
	while (++i < pars->nb_l && (j = -1) < 0)
		while (++j < pars->size_l - 1)
		{	
			ft_cal_pnt(ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]), &ft_multiply, img->pbc);
			ft_cal_pnt(ft_fill_pnt(&pnt[1], i, j + 1, pars->map[i][j + 1]), &ft_multiply, img->pbc);
			ft_makeline(img, pars, &pnt[0], &pnt[1]);
			if (i < pars->nb_l - 1)
			{
				ft_cal_pnt(ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]), &ft_multiply, img->pbc);
				ft_cal_pnt(ft_fill_pnt(&pnt[1], i + 1, j, pars->map[i + 1][j]), &ft_multiply, img->pbc);
				ft_makeline(img, pars, &pnt[0], &pnt[1]);
				if (j == pars->size_l - 2)
				{
					ft_cal_pnt(ft_fill_pnt(&pnt[0], i, j + 1, pars->map[i][j + 1]), &ft_multiply, img->pbc);
					ft_cal_pnt(ft_fill_pnt(&pnt[1], i + 1, j + 1, pars->map[i + 1][j + 1]), &ft_multiply, img->pbc);
					ft_makeline(img, pars, &pnt[0], &pnt[1]);
				}
			}
		}
}

void	free_parsing(t_pars *pars)
{
	int i;

	i = 0;
	while (pars->map[i])
		free(pars->map[i++]);
	free(pars->map);
}

void	generate_win(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->img.size, mlx->img.size);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &(mlx->img.bbp), &(mlx->img.size_line), &(mlx->img.endian));
	ft_draw_me_a_sheep(mlx->pars, &(mlx->img));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	byebye(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	free_parsing(mlx->pars);
	mlx_clear_window (mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}

int key_hook(int keycode, void *params)
{
	t_mlx *mlx;

	mlx = (t_mlx*)params;
	if (keycode == 53)
		byebye(mlx);
	else if (keycode == 49)
		mlx->img.angle = (mlx->img.angle) ? 0 : 1;
	else if(keycode == 126)
		mlx->img.pbc += 1;
	else if(keycode == 125 && mlx->img.pbc - 1 > 0)
		mlx->img.pbc -= 1;
	else if(keycode == 123)
		mlx->img.d_x -= mlx->pars->nb_l;
	else if(keycode == 124)
		mlx->img.d_x += mlx->pars->nb_l;
	else if(keycode == 69)
		mlx->img.f--;
	else if(keycode == 78)
		mlx->img.f++;
	else if(keycode == 13)
		mlx->img.d_y-=10;
	else if(keycode == 1)
		mlx->img.d_y+=10;
	generate_win(mlx);
	return (0);
}

int	change_color(int button, int x,int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (button == 1 && x >= 85 + mlx->img.size && x <= 115 + mlx->img.size)
		if ( y >= 150 && y <= 350)
			mlx->img.color = give_me_color(y - 150);
	generate_win(mlx);
	return (1);
}

int main(int argc, char *argv[])
{
	t_pars	*pars;
	t_mlx	mlx;
	int fd;
	int color;
	int i;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	ft_bzero(&mlx, sizeof(t_mlx));
	ft_bzero(&mlx.img, sizeof(t_img));
	pars = ft_parse_map(fd);
	mlx.pars = pars;
	mlx.img.prec = 10000;
	mlx.img.angle = 1;
	mlx.img.color = 0xee6572;
	mlx.img.pbc = (pars->nb_l > pars->size_l) ? 900 / pars->nb_l / 2 : 1250 / pars->size_l / 2 ;
	mlx.img.d_x = mlx.img.pbc * pars->nb_l;
	mlx.img.d_y = pars->nb_l * mlx.img.pbc;
	mlx.img.size = (pars->nb_l > pars->size_l) ? 1500 : 1250;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.img.size + 200, mlx.img.size, "FDF");
	generate_win(&mlx);
	fd = -1;

	while (++fd < mlx.img.size && (i = -1) < 0)
	{
		if (fd > 150 && fd < 350)
			color = give_me_color(fd - 150);
		while (++i < 200)
			if (i >= 85 && i <= 115 && fd >= 150 && fd <= 350)
			{
				if (i != 85 && i != 115 && fd != 150 && fd != 350)
					mlx_pixel_put(mlx.ptr, mlx.win,i + mlx.img.size, fd, color);
			}
			else
				mlx_pixel_put(mlx.ptr, mlx.win,i + mlx.img.size, fd, i * fd *  100);
	}

	mlx_string_put ( mlx.ptr, mlx.win, mlx.img.size + 86, 41 ,  1000000000, "FDF");
	mlx_string_put ( mlx.ptr, mlx.win, mlx.img.size + 85, 40 ,  10000, "FDF");
	mlx_key_hook(mlx.win, &key_hook, &mlx);
	mlx_mouse_hook(mlx.win, &change_color, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
