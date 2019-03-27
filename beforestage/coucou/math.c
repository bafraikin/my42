/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:58:06 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/22 14:59:57 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_multiply(int y, int x)
{
	return (y * x);
}

int		ft_divide(int y, int x)
{
	return (y / x);
}

int		ft_add(int y, int x)
{
	return (y + x);
}

int		ft_less(int y, int x)
{
	return (y - x);
}

int		pythagore(int x, int y)
{
	return (round(sqrt(pow(x, 2) + pow(y, 2))));
}
