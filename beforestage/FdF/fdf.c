/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:59:42 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/27 21:28:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		key_hook(int keycode, void *params)
{
	t_mlx *mlx;

	mlx = (t_mlx*)params;
	if (keycode == 53)
		byebye(mlx);
	else if (keycode == 49)
		mlx->img.angle = (mlx->img.angle) ? 0 : 1;
	else if (keycode == 126)
		mlx->img.pbc += 1;
	else if (keycode == 125 && mlx->img.pbc - 1 > 0)
		mlx->img.pbc -= 1;
	else if (keycode == 123)
		mlx->img.d_x -= mlx->pars->nb_l;
	else if (keycode == 124)
		mlx->img.d_x += mlx->pars->nb_l;
	else if ((keycode == 69 || keycode == 78))
		mlx->img.f += (keycode == 78) ? 1 : -1;
	else if (keycode == 13 || keycode == 1)
		mlx->img.d_y += (keycode == 1) ? 10 : -10;
	else if (keycode == 7 || keycode == 6)
		mlx->img.degrad += (keycode == 7) ? 0.2 : -0.2;
	generate_win(mlx);
	return (0);
}

int		change_color(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (button == 1 && x >= 85 + mlx->img.size && x <= 115 + mlx->img.size)
		if (y >= 150 && y <= 350)
			mlx->img.color = give_me_color(y - 150);
	generate_win(mlx);
	return (1);
}

void	ft_hud(t_mlx *mlx)
{
	int		fd;
	int		i;
	int		color;
	int		tmp;

	fd = -1;
	while (++fd < mlx->img.size && (i = -1) < 0)
	{
		if (fd > 150 && fd < 350)
			color = give_me_color(fd - 150);
		while (++i < 200)
			if (i >= 85 && i <= 115 && fd >= 150 && fd <= 350
					&& i != 85 && i != 115 && fd != 150 && fd != 350)
				mlx_pixel_put(mlx->ptr, mlx->win, i + mlx->img.size, fd, color);
			else
			{
				tmp = i * fd * 100;
				mlx_pixel_put(mlx->ptr, mlx->win, i + mlx->img.size, fd, tmp);
			}
	}
	mlx_string_put(mlx->ptr, mlx->win, mlx->img.size + 86, 41, 10000000, "FDF");
	mlx_string_put(mlx->ptr, mlx->win, mlx->img.size + 85, 40, 10000, "FDF");
}

void	ft_init_mlx(t_mlx *mlx, t_pars *pars)
{
	int size;

	mlx->img.prec = 10000;
	mlx->img.degrad = 0.3;
	mlx->img.angle = 1;
	mlx->img.color = 0xee6572;
	mlx->img.pbc = (pars->nb_l > pars->size_l) ? 900 / pars->nb_l / 2
		: 1250 / pars->size_l / 2;
	mlx->img.d_x = mlx->img.pbc * pars->nb_l;
	mlx->img.d_y = pars->nb_l * mlx->img.pbc;
	mlx->img.size = (pars->nb_l > pars->size_l) ? 1500 : 1250;
	size = mlx->img.size;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, size + 200, size, "FDF");
}

int		main(int argc, char *argv[])
{
	t_pars	*pars;
	t_mlx	mlx;
	int		fd;

	if (argc != 2)
		ft_error("usage: ./fdf valid_file_map\n");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("usage: ./fdf valid_file_map\n");
	ft_bzero(&mlx, sizeof(t_mlx));
	ft_bzero(&mlx.img, sizeof(t_img));
	pars = ft_parse_map(fd);
	mlx.img.max = pars->max;
	(pars->nb_l == 0) ? ft_error("map error\n") : 0;
	mlx.pars = pars;
	ft_init_mlx(&mlx, pars);
	generate_win(&mlx);
	ft_hud(&mlx);
	mlx_key_hook(mlx.win, &key_hook, &mlx);
	mlx_mouse_hook(mlx.win, &change_color, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
