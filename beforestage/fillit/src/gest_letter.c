/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:17:16 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/09 16:53:08 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_build_utils(char *tab, t_letter **begin, int size)
{
	tab[size] = 0;
	while (size-- > 0)
	{
		add_new_letter(begin, 'A' + size);
		tab[size] = '.';
	}
}

char	give_me_a_letter(int index, char *tab, t_letter **head, t_grid *bgrid)
{
	if (!(bgrid->rejet) && (tab[index] = (*head)->letter) != 0
			&& (remove_letter(head, tab[index]) == tab[index]))
		return (index);
	else if (bgrid->rejet->xgrid == -1 && bgrid->rejet->ygrid == -1)
	{
		add_new_letter(head, bgrid->rejet->letter);
		if (tab[index] == '.')
		{
			tab[index] = (*head)->letter;
			remove_letter(head, tab[index]);
			return (index);
		}
		else if (index > 0 && (tab[index] = '.') == '.'
		&& (bgrid->rejet = find_elem(bgrid->begin, tab[index - 1])) != NULL)
			return (give_me_a_letter(index - 1, tab, head, bgrid));
		tab[0] = '.';
		(bgrid->size)++;
		bgrid->ret = 1;
		return (-1);
	}
	else if (place_piece(bgrid, bgrid->rejet) && (bgrid->ret = 1) == 1)
		return (index);
	else
		return (give_me_a_letter(index, tab, head, bgrid));
}
