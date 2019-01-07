/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:25:15 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 11:37:51 by bafraiki         ###   ########.fr       */
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

void	ft_print(t_letter *begin)
{
	t_letter *elem;

	elem = begin;
	while (elem)
	{
		printf("%c ", elem->letter);
		elem = elem->next;
	}
}

void	fillit_baby(char **big_grid, t_shape *begin, int size)
{
	int index;
	int ret;
	char *tab;
	t_letter *head;

	head = NULL;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	ft_build_utils(tab, &head, size);
	index = -1;
	ret = 1;
	while (index < size)
	{
		//when index == -1 size_sqre++
		if (ret)
		{
		index++;
		index = give_me_a_letter(index, tab, &head, 0);
		ret = place_piece(big_grid, find_elem(begin, tab[index]), size_square(&begin, 1));
		}
		else
		{
		index = give_me_a_letter(index, tab, &head, tab[index]);
		ret = place_piece(big_grid, find_elem(begin, tab[index]), size_square(&begin, 1));
		}
	printf("%d\n", index);
		sleep(1);
	}
	ft_print_grid(big_grid, &begin);
}
