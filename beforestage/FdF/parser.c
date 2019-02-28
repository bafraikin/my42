/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:03:23 by bafraiki          #+#    #+#             */
/*   Updated: 2019/02/28 13:21:53 by bafraiki         ###   ########.fr       */
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

void	ft_copy_ptr(char **src, char **dst)
{
	int i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	dst[i] = 0;
}

void	ft_copy_line_split(char **dst, char *line, int *nb)
{
	int i;
	char **line_split;
	i = -1;

	if (!(line_split = ft_strsplit(line, 32)))
		exit(EXIT_FAILURE);
	free(line);
	if (*nb == ft_nb_elem(line_split) || *nb == -1)
		*nb = ft_nb_elem(line_split);
	else
		exit(EXIT_FAILURE);
	if (!(dst[0] = (char*)malloc(sizeof(char) * *nb + 1)))
		exit(EXIT_FAILURE);
	while (++i < *nb)
	{
		dst[0][i] = ft_atoi(line_split[i]);
		if (dst[0][i] == 0 && line_split[i][0] != 48)
			exit(EXIT_FAILURE);
		free(line_split[i]);
	}
	free(line_split[i]);
	dst[0][*nb] = -128;
	free(line_split);
}

char **ft_parse_map(int fd)
{
	int mall;
	char *line;
	char **tmp;
	char **map;
	int nb;
	int j;

	map = NULL;
	j = -1;
	mall = 0;
	nb = -1;
	map = 0;
	while (get_next_line(fd, &line) > 0 && ++j >= 0)
	{
		tmp = (char**)malloc(sizeof(char*) * (mall + 1));
		tmp[mall] = 0;
		ft_copy_ptr(map, tmp);
		mall++;
		map = (char**)malloc(sizeof(char*) * (mall + 1));
		map[mall] = 0;
		ft_copy_ptr(tmp, map);
		ft_copy_line_split(&map[j], line, &nb);	
	}
	if (get_next_line(fd, &line) < 0)
		exit(EXIT_FAILURE);
	return (map);
}
