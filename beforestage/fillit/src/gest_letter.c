/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:17:16 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 11:31:48 by bafraiki         ###   ########.fr       */
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

char	give_me_a_letter(int index, char *tab, t_letter **begin, char rejet)
{
	char letter;

	if (!rejet && (tab[index] = (*begin)->letter) != 0)
	{
		remove_letter(begin, tab[index]);
		return (index);
	}
	add_new_letter(begin, rejet);
	letter = there_is_highest(*begin, tab[index]);
	if (tab[index] < letter)
	{
		remove_letter(begin, letter);
		tab[index] = letter;
		return (index);
	}
	else if (index > 0)
	{
		tab[index] = '.';
		return (give_me_a_letter(index - 1, tab, begin, tab[index - 1]));
	}
	tab[index] = '.';
	return (-1);
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
}
*/
