/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:03:23 by bafraiki          #+#    #+#             */
/*   Updated: 2019/03/04 12:14:27 by bafraiki         ###   ########.fr       */
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

void	ft_copy_ptr(short **src, short **dst)
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

void	ft_copy_line_split(short **dst, char *line, int *nb)
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
	if (!(dst[0] = (short*)malloc(sizeof(short) * *nb + 1)))
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
	s_pars *pars;
	char *line;
	int j;

	map = NULL;
	j = 0;
	pars = (t_pars*)malloc(sizeof(t_pars));
	ft_bzero(pars, sizeof(t_pars));
	pars->size_l = -1;
	while (get_next_line(fd, &line) > 0)
	{
		pars->tmp = (char**)malloc(sizeof(char*) * (pars->>nb_l + 1)); // MALLOC
		pars->tmp[pars->nb_l] = 0;
		ft_copy_ptr(pars->map, pars->tmp);
		pars->nb_l++;
		pars->map = (char**)malloc(sizeof(char*) * (pars->nb_l + 1)); //MALLOC
		pars->map[pars->nb_l] = 0;
		ft_copy_ptr(pars->tmp, pars->map);
		ft_copy_line_split(&(pars->map[j++]), line, &pars->size_l);	
	}
	if (get_next_line(fd, &line) < 0)
		exit(EXIT_FAILURE);
	return (map);
}
