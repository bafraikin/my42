/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:36 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/09 17:09:03 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen_strchr(char *str, int *count)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			error();
		if (str[i] == '#')
			(*count)++;
		i++;
	}
	return (i);
}

int		follow_pcs(char form[4][2], int i, int *min, int *max)
{
	int j;
	int tmp[4];

	j = -1;
	while (++j < 4)
		tmp[j] = form[j][i];
	j = -1;
	while (++j < 3)
		if (tmp[j] > tmp[j + 1])
		{
			ft_swap(&tmp[j], &tmp[j + 1]);
			j = -1;
		}
	*min = tmp[0];
	*max = tmp[3];
	j = -1;
	while (++j < 3)
		if (tmp[j + 1] - tmp[j] > 1)
			error();
	return (1);
}

int		adjacent_pcs(char tab[4][2])
{
	int i;
	int j;
	int min;
	int t;

	i = 0;
	while (i < 4)
	{
		j = -1;
		min = 2;
		while (++j < 4)
			if (j != i)
			{
				t = ft_cmp(tab[i][0], tab[j][0]) + ft_cmp(tab[i][1], tab[j][1]);
				if (t < min)
					min = t;
			}
		if (min > 1)
			error();
		i++;
	}
	return (1);
}

void	ft_check_fill(char **grid, char form[4][2])
{
	int		i;
	int		j;
	int		k;
	int		lm[2];

	i = -1;
	lm[0] = 5;
	lm[1] = 0;
	k = 0;
	ft_add_value(form, 0, 0, k++);
	while (++i < 4 && (j = -1) < 0)
		while (++j < 4)
			if (grid[i][j] == '#' && lm[0] == 5 && (lm[0] = i) >= 0)
				lm[1] = j;
			else if (grid[i][j] == '#')
				ft_add_value(form, i - lm[0], j - lm[1], k++);
}

void	ft_store_grid(int fd, char **grid)
{
	int i;
	int ret;

	ret = 1;
	i = 0;
	while ((ret = get_next_line(fd, &grid[i])) > 0 && i <= 129)
		i++;
	if (ret == 0 && i <= 129 && i > 0)
	{
		free(grid[i]);
		grid[i] = 0;
	}
	else
		error();
}
