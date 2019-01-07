/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:17:16 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 20:17:06 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_build_utils(char *tab, t_letter **begin, int size)
{
	tab[size] = 0;
	while(size-- > 0)
	{
		add_new_letter(begin, 'A' + size);
		tab[size] = '.';
	}
}

int		there_is_highest(t_letter *begin, char c)
{
	t_letter *elem;

	elem = begin;
	while (elem)
		if (elem->letter > c)
			return (elem->letter);
		else
			elem = elem->next;
	return (0);
}

void		find_erase(t_grid *bgrid)
{
	int i;
	int j;
	t_shape *rejet;

	i = bgrid->size;
	j = bgrid->size;
	printf("%d %d\n", i,j);
	while (i-- > 0 && (j = bgrid->size - 1) > 0)
		while (j-- > 0)
			if (bgrid->grid[i][j] == bgrid->rejet->letter)
				erase(i, j, bgrid, 4);
}

void	ft_print(t_letter *begin)
{
	t_letter *elem;

	elem = begin;
	while (elem)
	{
		printf("%c", elem->letter);
		elem = elem->next;
	}
}

char	give_me_a_letter(int index, char *tab, t_letter **head, t_grid *bgrid)
{
	char letter;

	if (!(bgrid->rejet) && (tab[index] = (*head)->letter) != 0)
	{
		remove_letter(head, tab[index]);
		return (index);
	}
	else if (bgrid->rejet->xgrid == -1 && bgrid->rejet->ygrid == -1)
	{
		add_new_letter(head, bgrid->rejet->letter);
		letter = there_is_highest(*head, tab[index]);
		if (tab[index] < letter)
		{
			remove_letter(head, letter);
			tab[index] = letter;
			return (index);
		}
		else if (index > 0)
		{
			tab[index] = '.';
			bgrid->rejet = find_elem(bgrid->begin, tab[index - 1]);
			return (give_me_a_letter(index - 1, tab, head, bgrid));
		}
		tab[index] = '.';
		(bgrid->size)++;
		bgrid->ret = 1;
		return (-1);
	}
	else if (place_piece(bgrid, bgrid->rejet))
	{
		bgrid->ret = 1;
		return (index);
	}
	else
		return (give_me_a_letter(index, tab, head, bgrid));
}

/*
   int main(int argc, char *argv[])
   {
   t_letter *begin;
   char *tab;

   tab = (char*)malloc(3);
   ft_build_utils(tab, &begin, 3);
   ft_print(begin);
   printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
   printf("\n");
   give_me_a_letter(0, tab, &begin, 0);
   give_me_a_letter(0, tab, &begin, 'A');
   ft_print(begin);
   printf("\n");

   printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
   give_me_a_letter(1, tab, &begin, 0);
   printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
   give_me_a_letter(1, tab, &begin, 'A');
   give_me_a_letter(1, tab, &begin, 'C');
   give_me_a_letter(1, tab, &begin, 0);
   give_me_a_letter(2, tab, &begin, 0);
   give_me_a_letter(2, tab, &begin, 'B');
   give_me_a_letter(2, tab, &begin, 0);
   int a = give_me_a_letter(2, tab, &begin, 'A');
   printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
   printf("%d\n",a);
   ft_print(begin);
   printf("\n");

   return 0;
   }*/
