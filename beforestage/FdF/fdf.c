/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/08 18:41:27 by bafraiki         ###   ########.fr       */
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

void	ft_color_it(t_img *img, int x, int y, int color)
{
	int coord;

	if (x >= img->size || y >= img->size)
		return ;
	coord = 4 * x + img->size_line * y;
	img->data[coord] = color / 1000000 % 1000;
	img->data[coord + 1] = color / 1000 % 1000;
	img->data[coord + 2] = color % 1000;
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
		pnt1->x += diff.x;
		pnt1->y += diff.y;
		pnt1->z += diff.z;
		ft_y(&xy[1], ft_x(&xy[0], pnt1->x, pnt1->y), pnt1->y);
		if (img->angle)
			ft_color_it(img, pnt1->x / img->prec + img->d_x, pnt1->y / img->prec + img->d_y + (pnt1->z / img->prec) / (img->f) * -1  ,  255 + pnt1->z * img->f);
		else
			ft_color_it(img, xy[0] / img->prec + img->d_x , xy[1] / img->prec + (pnt1->z / img->prec) / (img->f) * -1 + img->d_y  ,  255 + pnt1->z * img->f);
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

void generate_win(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		mlx_clear_window(mlx->ptr, mlx->win);
	}
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->img.size, mlx->img.size);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &(mlx->img.bbp), &(mlx->img.size_line), &(mlx->img.endian));
	ft_draw_me_a_sheep(mlx->pars, &(mlx->img));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

int key_hook(int keycode, void *params)
{
	t_mlx *mlx;

	mlx = (t_mlx*)params;
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		free_parsing(mlx->pars);
		mlx_clear_window (mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(EXIT_SUCCESS);
	}
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
	generate_win(mlx);
	return (0);
}

int main(int argc, char *argv[])
{
	t_pars	*pars;
	t_mlx	mlx;
	int fd;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	ft_bzero(&mlx, sizeof(t_mlx));
	pars = ft_parse_map(fd);
	mlx.pars = pars;
	mlx.img.prec = 10000;
	mlx.img.angle = 1;
	mlx.img.pbc = (pars->nb_l > pars->size_l) ? 900 / pars->nb_l / 2 :  1250 / pars->size_l / 2 ;
	mlx.img.d_x = mlx.img.pbc * pars->nb_l;
	mlx.img.d_y = pars->nb_l * mlx.img.pbc;
	mlx.img.size = (pars->nb_l > pars->size_l) ? 1500 : 1250;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1500, 1250, "FDF");
	generate_win(&mlx);
	mlx_key_hook(mlx.win, &key_hook, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
