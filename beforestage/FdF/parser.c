/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:03:23 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/22 13:15:56 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int ft_nb_elem(char **split)
{
	int i;

	i = 0;
	while (*split)
	{
		i++;
		split++;
	}
	return (i);
}

void	ft_copy_ptr(char **src, char **dest)
{
	while (src)
	{
		dst = src
	
	}
}

int **ft_parse_map(int fd)
{
	int mall;
	char *line;
	char **line_split;
	char **tmp;
	char **map;
	int nb;
	int i;
	mall = 0;

	while (get_next_line(fd, &line) > 0)    				// MALLOC
	{
	mall += 10;



	map = (char**)malloc(sizeof(char*) * mall);
	line_split = ft_strsplit(line, 32); 			// MALLOC
	nb = ft_nb_elem(line_split);
	*map = (char*)malloc(sizeof(char) * nb);
	i = -1;
	while (++i < nb)
	{
		map[0][i] = ft_atoi(line_split[i]);
		if (map[0][i] == 0 && line_split[i][0] != 48)
			exit(EXIT_FAILURE);
	}
	}
	return (NULL);
}
