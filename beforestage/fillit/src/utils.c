/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:32:22 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/08 18:47:25 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_power_2(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i++;
	return (i);
}

void	ft_add_value(char form[4][2], int i, int j, int k)
{
	form[k][0] = i;
	form[k][1] = j;
}

int		ft_cmp(int a, int b)
{
	if (b < a)
		return (a - b);
	else
		return (b - a);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
