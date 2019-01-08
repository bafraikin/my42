/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:20:57 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/08 17:46:11 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lst_size(t_shape **lst)
{
	int		size;
	t_shape	*elem;

	size = 0;
	elem = *lst;
	if (!(lst))
		size = 0;
	while (elem)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

t_shape	*ft_new(char shape[4][2], t_check *nb)
{
	t_shape *new;
	int		i;

	i = 0;
	if ((new = (t_shape*)malloc(sizeof(t_shape))) == NULL)
		error();
	while (i < 4)
	{
		ft_add_value(new->form, shape[i][0], shape[i][1], i);
		i++;
	}
	new->height = nb->max_y - nb->min_y + 1;
	new->width = nb->max_x - nb->min_x + 1;
	if (new->height + new->width > 5)
		error();
	new->xgrid = -1;
	new->ygrid = -1;
	new->next = NULL;
	return (new);
}

void	ft_add_end(t_shape **lst, t_shape *new)
{
	t_shape	*elem;
	int		i;

	if (new == NULL)
		error();
	if (!(*lst) && (*lst = new) != NULL)
		new->letter = 'A';
	else
	{
		i = 1;
		elem = *lst;
		while (elem->next)
		{
			elem = elem->next;
			i++;
		}
		elem->next = new;
		new->letter = i + 'A';
	}
}

t_shape	*find_elem(t_shape *begin, int nb)
{
	nb = (nb - 'A') + 1;
	while (nb-- > 1)
		begin = begin->next;
	return (begin);
}
