/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:17:09 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 20:30:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	ft_print_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("grid[%d] : %s\n", i, grid[i]);
		i++;
	}

}

void		erase(int undex, int deudex, t_grid *bgrid, int nb_piece)
{
	int x;
	int y;
	int i;

	i = 0;
/*	system("clear");
	printf("erase %d %d %d\n",undex, deudex, nb_piece);*/
//	ft_print_grid(bgrid->grid, bgrid->size);
//	usleep(200000);
	while (i < nb_piece)
	{
		x = bgrid->rejet->form[i][0];
		y = bgrid->rejet->form[i][1];
		bgrid->grid[undex + x][deudex + y] = '.';
//	system("clear");
//		printf("%d %d\n",undex, deudex);
//		ft_print_grid(bgrid->grid, bgrid->size);
//		usleep(200000);
		i++;
	}
}

int		place_piece(t_grid *bgrid, t_shape *elem)
{
	int nb_piece;
	int i;
	int j;
	int x;
	int y;

	if (elem->xgrid == -1)
	{
		elem->xgrid = 0;
		elem->ygrid = 0;
		j = 0;
		i = 0;
	}
	else
	{
		erase(elem->xgrid, elem->ygrid, bgrid, 4);
		i = elem->xgrid;
		j = elem->ygrid + 1;
		if (j >= bgrid->size)
		{
			j = 0;
			i = elem->xgrid + 1;
			if (elem->xgrid >= bgrid->size)
			{
				elem->xgrid = -1;
				elem->ygrid = -1;
				return (0);
			}
		}
	}
	printf("i : %d\n",i);
//	sleep(1);
	nb_piece = 0;
	bgrid->rejet = elem;
	while(nb_piece != 4 && i < bgrid->size)
	{
		j = (i > elem->xgrid) ? 0 : j;
		while (nb_piece != 4 && j < bgrid->size && (nb_piece = 0) == 0)
		{
			if (bgrid->grid[i][j] == '.')
				while (nb_piece < 4)
				{
					x = elem->form[nb_piece][0];
					y = elem->form[nb_piece][1];
					if (bgrid->grid[i + x][j + y] == '.' && i + x >= 0 && i + x < bgrid->size && j + y >= 0 && j + y < bgrid->size)
					{
						printf("%d %d\n", i + x, j + y);
						bgrid->grid[i + x][j + y] = elem->letter;
						nb_piece++;
//					system("clear");
//						printf("\n");
//						ft_print_grid(bgrid->grid, bgrid->size);
//						usleep(200000);
					}
					else
					{
						if (nb_piece >= 0)
						{
							x = elem->form[nb_piece - 1][0];
							y = elem->form[nb_piece - 1][1];
						}
						erase(i, j, bgrid, nb_piece);
						nb_piece = 5;
					}
					if (nb_piece == 4)
					{
						elem->xgrid = i;
						elem->ygrid = j;
					}
				}
			j++;
		}
		i++;
	}
	if (nb_piece == 4)
	{
		bgrid->rejet = NULL;
		return (1);
	}
	elem->xgrid = -1;
	elem->ygrid = -1;
	return (0);
}

char	**generate_big_grid(t_shape **begin)
{
	int		i;
	char	**grid;
	t_shape *elem;

	i = 0;
	elem = *begin;
	grid = (char **)malloc(sizeof(char *) * size_square(&elem, 0));
	while (i < size_square(&elem, 0))
	{
		grid[i] = (char *)malloc(sizeof(char) * size_square(&elem, 0));
		ft_memset(grid[i], '.', size_square(&elem, 0));
		printf("grid[%d] : %s\n", i, grid[i]);
		i++;
	}
	printf("===============\n");
	return (grid);
}
