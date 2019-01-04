/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:17:16 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/04 17:27:25 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	ft_build_utils(char *tab, t_letter **begin, int size)
{
	tab[size] = 0;
	while(size-- > 0)
	{
		printf("A + size : %c\n", 'A' + size);
		add_new_letter(begin, 'A' + size);
		printf("size2 : %d\n", size);
		tab[size] = '.';
	}
	ft_print(*begin);
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

	if (*begin == NULL)
		return (-2);
	else if (!rejet && (tab[index] = (*begin)->letter) != 0)
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


/*int main(int argc, char *argv[])
{
	t_letter *begin;
	char tab[] = {'A', 'B', '.'};
	remove_letter(&begin, 'A');
	remove_letter(&begin, 'B');
	ft_print(begin);
	printf("\n");

	give_me_a_letter(1, tab, &begin, 'B');
	give_me_a_letter(1, tab, &begin, 'C');
	printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
	give_me_a_letter(1, tab, &begin, 0);
	give_me_a_letter(2, tab, &begin, 0);
	give_me_a_letter(2, tab, &begin, 'C');
	give_me_a_letter(1, tab, &begin, 'C');
	printf("%c %c %c\n", *tab, *(tab + 1), *(tab + 2));
	give_me_a_letter(1, tab, &begin, 0);
	give_me_a_letter(1, tab, &begin, 'A');
	give_me_a_letter(2, tab, &begin, 0);
	printf("%c\n", give_me_a_letter(2, tab, &begin, 'A'));
	printf("ici %c %c %c\n", *tab, *(tab + 1), *(tab + 2));
	ft_print(begin);
	printf("\nprintlist\n");
	return 0;
}*/
