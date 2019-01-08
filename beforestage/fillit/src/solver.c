/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:25:15 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/08 14:06:07 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_square(t_shape **lst, int boolean)
{
	int		height;
	int		width;
	t_shape	*elem;
	int		result;

	elem = *lst;
	if (!boolean && (height = 0) == 0)
	{
		width = 0;
		while (elem)
		{
			height += elem->height;
			width += elem->width;
			elem = elem->next;
		}
		if (height > width)
			return (height);
		return (width);
	}
	result = ft_power_2(ft_lst_size(lst) * 4);
	if (result >= elem->height && result >= elem->width)
		return (result);
	if (elem->height > elem->width)
		return (elem->height);
	return (elem->width);
}

void	fillit_baby(t_grid *bgrid, t_shape *begin, int size_l)
{
	int			index;
	char		*tab;
	t_letter	*head;

	head = NULL;
	if (!(tab = (char *)malloc(sizeof(char) * (size_l + 1))))
		exit(EXIT_FAILURE);
	ft_build_utils(tab, &head, size_l);
	index = -1;
	bgrid->ret = 1;
	while (index <= size_l - 1 || bgrid->ret == 0)
	{
		if (bgrid->ret)
		{
			index++;
			if (index <= size_l - 1)
			{
				index = give_me_a_letter(index, tab, &head, bgrid);
				bgrid->ret = place_piece(bgrid, find_elem(begin, tab[index]));
			}
		}
		else if ((index = give_me_a_letter(index, tab, &head, bgrid)) > -2)
			if (bgrid->ret == 0)
				bgrid->ret = place_piece(bgrid, find_elem(begin, tab[index]));
	}
}
