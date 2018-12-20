/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:14:36 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/20 11:20:11 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

int				ft_grid_validity(int fd);
void			ft_add_value(char form[4][2], int i, int j, int k);
int				ft_cmp(int a, int b);
void			ft_swap(int *a, int *b);

typedef struct	s_shape {

	char		form[4][2];
	char		height;
	char		width;
	char		letter;
	t_shape		*next;
}				t_shape;

#endif
