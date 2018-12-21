/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:25:15 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/21 15:23:00 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int		size_square(t_shape **lst, int boolean)
{
	int		height;
	int		width;
	t_shape	*elem;

	if (boolean)	// min
		return (ft_power_2(ft_lst_size(lst) * 4));
	else			// max
	{
		elem = *lst;
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
}



char *ft_letter_that_are_not_in_tab(char *tab, int size)
{
	int		i;
	int		j;
	char	alpha[size + 1];
	char	not_present[size + 1];

	i = -1;
	while(++i <= size)
	{
		alpha[i] = 'A' + i;
		not_present[i] = '.';
	}
	alpha[size] = 0;
	not_present[size] = 0;
	i = -1;

	while (alpha[++j] != 0)
		while(tab[++i] != '.' && tab[i] != 0 && (j = -1) < 0)
			if (tab[i] == alpha[j])
}

	ABC....... 5
int		ft_increment(int size, int mode, char *tab)
{
	int i;

	i = 0;
	if (mode == 1)
		while (tab[++i] != '.' && tab[i] != '\0')

	else if (mode == 2)
}


/* si madame a reussi a placer elle m'envoit 1 je lui envoit la prochaine lettre
 * sinon elle me dit d'incrementer
