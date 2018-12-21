/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:17:09 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/21 20:20:47 by salquier         ###   ########.fr       */
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
}

int		erase(char **grid, t_shape **lst)
{
	int		k;
	t_shape	*elem;
			
	elem = *lst;
	k = 0;
	while (k < size_square(&elem, 1))
		ft_memset(grid[k++], '.', size_square(&elem, 1));
	return (0);
}

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

char	**generate_big_grid(t_shape **begin)
{
	int		i;
	char	**grid;
	t_shape *elem;

	elem = *begin;
	grid = (char **)malloc(sizeof(char *) * size_square(&elem, 0));
	while (i < size_square(&elem, 0))
	{
		grid[i] = (char *)malloc(sizeof(char) * size_square(&elem, 0));
		ft_memset(grid[i], '.', size_square(&elem, 0));
		printf("grid[%d] : %s\n", i, grid[i]);
		i++;
	}
	return (grid);
}
