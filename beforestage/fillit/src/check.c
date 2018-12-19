/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:36 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/19 14:22:25 by bafraiki         ###   ########.fr       */
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
		if ((nb_hash = 0) == 0 && grid[i])
			i++;
	}
	exit(EXIT_SUCCESS);
	return (0);
}
