/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:25:15 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/21 16:16:55 by bafraiki         ###   ########.fr       */
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
