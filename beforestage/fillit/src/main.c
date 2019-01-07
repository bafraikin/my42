/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:16:56 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 20:30:39 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int		fd;
	t_shape *begin;
	t_grid 	bgrid;

	if (argc != 2)
	{
		write(1, "usage: ./fillit name_of_file\n", 25);
		return (1);
	}
	if (!((fd = open(argv[1], O_RDONLY)) > 0))
		return (1);
	ft_bzero(&bgrid, sizeof(bgrid));
	ft_grid_validity(fd, &(bgrid.begin));   //maybe begin should be a **
	//printf("%d\n", size_square(&begin, 0));
	//printf("%d\n", size_square(&begin, 1));
	bgrid.grid = generate_big_grid(&(bgrid.begin));
	bgrid.size = size_square(&(bgrid.begin), 1);
	fillit_baby(&bgrid, bgrid.begin, ft_lst_size(&(bgrid.begin)));
	//printf("%d\n", place_piece(generate_big_grid(&begin), begin, size_square(&begin, 1)));
	ft_print_grid(bgrid.grid, bgrid.size);
	return (0);
}
