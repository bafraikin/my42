/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:17:09 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/04 16:01:27 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	ft_print_grid(char **grid, t_shape **lst)
{
	int i;
	t_shape *elem;

	elem = *lst;
	i = 0;
	while (i < size_square(&elem, 1))
	{
		printf("grid[%d] : %s\n", i, grid[i]);
		i++;
	}
	printf("grid[%d] : %s\n", i, grid[i]);

}

void		erase(int undex, int deudex, char **grid, t_shape *lst, int nb_piece)
{
	int x;
	int y;
	int i;

	i = 0;
	x = lst->form[nb_piece - 1][0];
	y = lst->form[nb_piece - 1][1];
	undex -= x;
	deudex -= y;
	while (i < nb_piece)
	{
		x = lst->form[i][0];
		y = lst->form[i][1];
		grid[undex + x][deudex + y] = '.';
		i++;
	}
}

int		place_piece(char **grid, t_shape *elem, int size)
{
	int nb_piece;
	int i;
	int j;
	int x;
	int y;

	i = 0;
	nb_piece = 0;
	while(nb_piece != 4 && i <= size && (j = 0) == 0)
	{
		while (nb_piece != 4 && j < size && (nb_piece = 0)== 0)
		{
			if (grid[i][j] == '.')
				while (nb_piece < 4)
				{
					x = elem->form[nb_piece][0];
					y = elem->form[nb_piece][1];
					if (grid[i + x][j + y] == '.' && i + x >= 0 && i + x < size && j + y >= 0 && j + y < size)
					{
						grid[i + x][j + y] = elem->letter;
						nb_piece++;
					}
					else
					{
						erase(i, j, grid, elem, nb_piece);
						nb_piece = 5;
					}
				}
			j++;
		}
		i++;
	}
	ft_print_grid(grid, &elem);
	if (nb_piece == 4)
		return (1);
	return (0);
}

/*
   int		place_piece(char **grid, t_shape **lst, int size)
   {
   int		i;
   int		j;
   int		x;
   int		y;
   t_shape *elem;

   i = 0;		// index des coordonnees de mon tableau
   j = 0;		// 
   x = 0;		// ligne de la grille
   y = 0;		// colonne de la grille
   elem = *lst;
   while (i < 4 && x <= size && (y + j) <= size)
   {
   x = elem->form[i][0];
   y = elem->form[i][1];
   if (grid[x][y + j] == '.' && x >= 0 && (y + j >= 0))
   {
   grid[x][y + j] = elem->letter;
   i++;
   }
   else
   {
   i = erase(grid, &elem);
   j++;
   }
   if (x == (size - 1) && (y + j) == (size - 1))
   return (0);
   }
   printf("------- ////////// ----------\n");
   ft_print_grid(grid, &elem);
   return (1);
   }
   */
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
