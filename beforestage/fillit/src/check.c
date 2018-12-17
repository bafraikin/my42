/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:36 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/17 16:29:55 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_store_grid(int fd ,char **grid)
{
	int i;
	int ret;

	ret = 1;
	i = -1;
	while (++i < 129 && ret > 0)
		ret = get_next_line(fd, &grid[i]);
	if (ret == 0 && i <= 129)
		grid[i] = 0;
	else
		exit(EXIT_FAILURE);
}

int	ft_grid_validity(int fd)
{
	char *grid[130];
	int i;

	i = -1;
	ft_store_grid(fd, grid);
	while (grid[++i])
		printf("%s\n", grid[i]);
	return (0);
}

