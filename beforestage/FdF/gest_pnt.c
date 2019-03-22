/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_pnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:19:20 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/22 15:49:23 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	*ft_fill_pnt(t_pnt *to_fill, int y, int x, int z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
	return (to_fill);
}

void	ft_cal_pnt(t_pnt *to_calc, int (*f)(int x, int y), int nb)
{
	to_calc->x = (*f)(to_calc->x, nb);
	to_calc->y = (*f)(to_calc->y, nb);
	to_calc->z = (*f)(to_calc->z, nb);
}

void	ft_pnt_vs_pnt(t_pnt *pnt1, int (*f)(int x, int y), t_pnt *pnt2)
{
	pnt1->x = (*f)(pnt1->x, pnt2->x);
	pnt1->y = (*f)(pnt1->y, pnt2->y);
	pnt1->z = (*f)(pnt1->z, pnt2->z);
}

int		ft_x(int *rendu, int x, int y)
{
	*rendu = x - y;
	return (x);
}

void	ft_y(int *rendu, int x, int y)
{
	*rendu = (x + y) / 2;
}
