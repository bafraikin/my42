/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:17:09 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/08 17:29:47 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erase(int undex, int deudex, t_grid *bgrid, int nb_piece)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < nb_piece)
	{
		x = bgrid->rejet->form[i][0];
		y = bgrid->rejet->form[i][1];
		bgrid->grid[undex + x][deudex + y] = '.';
		i++;
	}
}

int		ft_init_pl_p(int *i, int *j, t_shape *elem, t_grid *bgrid)
{
	if (elem->xgrid == -1)
	{
		elem->xgrid = 0;
		elem->ygrid = 0;
		*j = 0;
		*i = 0;
	}
	else
	{
		erase(elem->xgrid, elem->ygrid, bgrid, 4);
		*i = elem->xgrid;
		*j = elem->ygrid + 1;
		if (*j >= bgrid->size && (*j = 0) == 0)
		{
			*i = elem->xgrid + 1;
			if (elem->xgrid >= bgrid->size && (elem->xgrid = -1) < 0)
			{
				elem->ygrid = -1;
				return (0);
			}
		}
	}
	bgrid->rejet = elem;
	return (1);
}

int		try_piece(t_grid *bgrid, int i, int j, int nb_piece)
{
	int y;
	int x;

	x = bgrid->rejet->form[nb_piece][0] + i;
	y = bgrid->rejet->form[nb_piece][1] + j;
	if (bgrid->grid[x][y] == '.' && x >= 0 && x < bgrid->size
			&& y >= 0 && y < bgrid->size)
	{
		bgrid->grid[x][y] = bgrid->rejet->letter;
		nb_piece++;
	}
	else
	{
		erase(i, j, bgrid, nb_piece);
		return (5);
	}
	if (nb_piece == 4)
		bgrid->rejet = NULL;
	return (nb_piece);
}

int		place_piece(t_grid *bgrid, t_shape *elem)
{
	int nb_piece;
	int i;
	int j;

	if (ft_init_pl_p(&i, &j, elem, bgrid) == 0)
		return (0);
	nb_piece = 0;
	while (nb_piece != 4 && i < bgrid->size)
	{
		j = (i > elem->xgrid) ? 0 : j;
		while (nb_piece != 4 && j < bgrid->size && (nb_piece = 0) == 0)
		{
			if (bgrid->grid[i][j] == '.')
				while (nb_piece < 4)
					nb_piece = try_piece(bgrid, i, j, nb_piece);
			j++;
		}
		i++;
	}
	elem->xgrid = (nb_piece == 4) ? i - 1 : -1;
	elem->ygrid = (nb_piece == 4) ? j - 1 : -1;
	if (nb_piece == 4)
		return (1);
	return (0);
}
