/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:36 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/19 19:21:08 by bafraiki         ###   ########.fr       */
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
			exit(EXIT_FAILURE);
		if (str[i] == '#')
			(*count)++;
		i++;
	}
	return (i);
}

int		follow_piece(char form[4][2], int i)
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
	j = -1;
	while (++j < 3)
		if (tmp[j + 1] - tmp[j] > 1)
			exit (EXIT_FAILURE);
	return (1);
}

int		adjacent_piece(char tab[4][2])
{
	int i;
	int j;
	int min;
	int t;

//	printf("%d %d\n%d %d\n%d %d\n%d %d\n\n", tab[0][0], tab[0][1], tab[1][0], tab[1][1], tab[2][0], tab[2][1], tab[3][0], tab[3][1]);
	i = 0;
	while (i < 4)
	{
		j = -1;
		min = 2;
		while (++j < 4)
			if (j != i)
			{
				t = ft_cmp(tab[i][0],tab[j][0]) + ft_cmp(tab[i][1], tab[j][1]);
				if (t < min)
					min = t;
			}
		if (min > 1)
			exit(EXIT_FAILURE);
		i++;
	}
	return (1);
}

void	ft_check_fill(char **grid, char form[4][2])
{
	int		i;
	int		j;
	int 	k;
	int		lm[2];

	i = -1;
	lm[0] = 5;
	lm[1] = 0;
	k = 0;
	ft_add_value(form, 0, 0, k++);
	while(++i < 4 && (j = -1) < 0)
		while (++j < 4)
			if (grid[i][j] == '#' && lm[0] == 5 && (lm[0] = i) >= 0)
				lm[1] = j;
			else if (grid[i][j] == '#')
				ft_add_value(form, i - lm[0], j - lm[1], k++);
}

void	ft_store_grid(int fd ,char **grid)
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
		exit(EXIT_FAILURE);
}

int	ft_grid_validity(int fd)
{
	char *grid[130];
	int i;
	int nb_line;
	int nb_hash;
	char form[4][2];

	i = 0;
	ft_store_grid(fd, grid);
	while (grid[i] && (nb_line = 0) == 0)
	{
		while (grid[i] && *grid[i] != '\0' && nb_line++ < 4)
			if (ft_strlen_strchr(grid[i++], &nb_hash) != 4)
				exit (EXIT_FAILURE);
		if (nb_hash != 4 || nb_line != 4
				|| (grid[i] && ((!grid[i + 1]) || (*grid[i] != '\0'))))
			exit(EXIT_FAILURE);
		ft_check_fill(&grid[i - 4], form);
		if (!((follow_piece(form, 0) && follow_piece(form, 1) && adjacent_piece(form))))
			exit(EXIT_FAILURE);
		if ((nb_hash = 0) == 0 && grid[i])
			i++;
	}
	exit(EXIT_SUCCESS);
	return (0);
}
