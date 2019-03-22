/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:32:44 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/22 19:02:40 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate_win(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->img.size, mlx->img.size);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &(mlx->img.bbp),
			&(mlx->img.size_line), &(mlx->img.endian));
	ft_draw_me_a_sheep(mlx->pars, &(mlx->img));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	ft_makeline(t_img *img, t_pnt *pnt1, t_pnt *pnt2)
{
	int		i;
	t_pnt	diff;
	int		ratio;
	int		xy[2];

	i = -1;
	diff.z = (pnt2->z - pnt1->z);
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
			ft_color_it(img, xy[0], xy[1], pnt1);
	}
}

void	ft_draw_lamb(t_pnt *pnt1, t_pnt *pnt2, t_img *img)
{
	ft_cal_pnt(pnt1, &ft_multiply, img->pbc);
	ft_cal_pnt(pnt2, &ft_multiply, img->pbc);
	ft_makeline(img, pnt1, pnt2);
}

void	ft_draw_me_a_sheep(t_pars *pars, t_img *img)
{
	int		i;
	int		j;
	t_pnt	pnt[2];

	i = -1;
	while (++i < pars->nb_l && (j = -1) < 0 && i < img->size * img->pbc)
		while (++j < pars->size_l - 1 && j < img->size * img->pbc + img->d_x)
		{
			ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]);
			ft_fill_pnt(&pnt[1], i, j + 1, pars->map[i][j + 1]);
			ft_draw_lamb(&pnt[0], &pnt[1], img);
			if (i < pars->nb_l - 1)
			{
				ft_fill_pnt(&pnt[0], i, j, pars->map[i][j]);
				ft_fill_pnt(&pnt[1], i + 1, j, pars->map[i + 1][j]);
				ft_draw_lamb(&pnt[0], &pnt[1], img);
				if (j == pars->size_l - 2)
				{
					ft_fill_pnt(&pnt[0], i, j + 1, pars->map[i][j + 1]);
					ft_fill_pnt(&pnt[1], i + 1, j + 1, pars->map[i + 1][j + 1]);
					ft_draw_lamb(&pnt[0], &pnt[1], img);
				}
			}
		}
}

void	byebye(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	free_parsing(mlx->pars);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}
