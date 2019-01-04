/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:25:15 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/04 17:22:21 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int		size_square(t_shape **lst, int boolean)
{
	int		height;
	int		width;
	t_shape	*elem;
	int result;

	elem = *lst;
	if (!boolean)			// max
	{
		height = 0;
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
	else					// min
	{
		result = ft_power_2(ft_lst_size(lst) * 4);
		if (result >= elem->height && result >= elem->width)
			return (result);
		if (elem->height > elem->width)
			return (elem->height);
		return (elem->width);
	}
}

void	fillit_baby(char **big_grid, t_shape *begin, int size)
{
	int index;
	char *tab;
	t_letter *head;

	head = NULL;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	printf("size : %d\n", size);
	ft_build_utils(tab, &head, size);
	printf("coucou\n");
	index = 0;
	while (index < size)
	{
		index = give_me_a_letter(index, tab, &head, 0);
		place_piece(big_grid, find_elem(begin, tab[index]), size_square(&begin, 1));
		index++;
	}
	ft_print_grid(big_grid, &begin);
}
