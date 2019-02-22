/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:03:23 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/22 20:10:10 by bafraiki         ###   ########.fr       */
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

void	ft_print_test(char **map)
{
	int i;
	int j;


	j = 0;
	i = 0;
	printf("%p\n", *map);
	printf("%p\n", map[1]);
	while (map[i])
	{
		while(map[i][j] != -128)
		{
			printf("%d \n", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	ft_copy_ptr(char **src, char **dst)
{
	int i;

	i = 0;
	if (!src || *src)
		return ;
	printf("ici\n");
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void	ft_copy_line_split(char **dst, char **line_split, int nb)
{
	int i;

	i = -1;
	dst[0] = (char*)malloc(sizeof(char) * nb + 1); // malloc
	while (++i < nb)
	{
		dst[0][i] = ft_atoi(line_split[i]);
		if (dst[0][i] == 0 && line_split[i][0] != 48)
			exit(EXIT_FAILURE);
		free(line_split[i]);
	}
	free(line_split[i]);
	dst[0][nb] = -128;
	free(line_split);  //peut etre que le dernier line split n'est pas free
}

char **ft_parse_map(int fd)
{
	int mall;
	char *line;
	char **line_split;
	char **tmp;
	char **map;
	int nb;
	int j;
	j = -1;
	mall = 0;
	nb = -1;
	map = 0;
	while (get_next_line(fd, &line) > 0 && ++j >= 0)			// MALLOC
	{
		tmp = (char**)malloc(sizeof(char*) * (mall + 1));
		tmp[mall] = 0;
		ft_copy_ptr(map, tmp);
		ft_print_test(tmp);
		mall++;
		map = (char**)malloc(sizeof(char*) * (mall + 1));
		map[mall] = 0;
		ft_copy_ptr(tmp, map);
		line_split = ft_strsplit(line, 32); 	// MALLOC
		if (nb == ft_nb_elem(line_split) || nb == -1)
			nb = ft_nb_elem(line_split);
		else
			exit(EXIT_FAILURE);
		ft_copy_line_split(&map[j], line_split, nb);	
		ft_print_test(map);
	}
	if (get_next_line(fd, &line) < 0)			// MALLOC
		exit(EXIT_FAILURE);
	ft_print_test(map);
	return (map);
}
