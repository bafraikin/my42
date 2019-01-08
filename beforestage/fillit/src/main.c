/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:56 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/08 15:31:51 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_grid_validity(int fd, t_shape **begin)
{
	char		*grid[130];
	t_check		nb;
	char		form[4][2];

	nb.i = 0;
	ft_store_grid(fd, grid);
	while (grid[nb.i] && (nb.line = 0) == 0)
	{
		nb.hash = 0;
		while (grid[nb.i] && *grid[nb.i] != '\0' && nb.line++ < 4)
			if (ft_strlen_strchr(grid[nb.i++], &(nb.hash)) != 4)
				exit(EXIT_FAILURE);
		if (nb.hash != 4 || nb.line != 4
				|| (grid[nb.i] && ((!grid[nb.i + 1]) || (*grid[nb.i] != '\0'))))
			exit(EXIT_FAILURE);
		ft_check_fill(&grid[nb.i - 4], form);
		if (!((follow_pcs(form, 0, &(nb.min_y), &(nb.max_y))
						&& follow_pcs(form, 1, &(nb.min_x), &(nb.max_x))
						&& adjacent_pcs(form))))
			exit(EXIT_FAILURE);
		ft_add_end(begin, ft_new(form, &nb));
		if ((nb.hash = 0) == 0 && grid[nb.i])
			nb.i++;
	}
}
void	ft_print_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("grid[%d] : %s\n", i, grid[i]);
		i++;
	}
}

char	**generate_big_grid(t_shape **begin)
{
	int		i;
	char	**grid;
	t_shape *elem;

	i = 0;
	elem = *begin;
	grid = (char **)malloc(sizeof(char *) * size_square(&elem, 0));
	while (i < size_square(&elem, 0))
	{
		grid[i] = (char *)malloc(sizeof(char) * size_square(&elem, 0));
		ft_memset(grid[i], '.', size_square(&elem, 0));
		i++;
	}
	return (grid);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_shape	*begin;
	t_grid	bgrid;

	if (argc != 2)
	{
		write(1, "usage: ./fillit <file>\n", 23);
		return (1);
	}
	if (!((fd = open(argv[1], O_RDONLY)) > 0))
		return (1);
	ft_bzero(&bgrid, sizeof(bgrid));
	ft_grid_validity(fd, &(bgrid.begin));
	bgrid.grid = generate_big_grid(&(bgrid.begin));
	bgrid.size = size_square(&(bgrid.begin), 1);
	fillit_baby(&bgrid, bgrid.begin, ft_lst_size(&(bgrid.begin)));
	ft_print_grid(bgrid.grid, bgrid.size);
	return (0);
}
