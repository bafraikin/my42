/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:14:36 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/20 14:54:51 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct 		s_grid {
	int				i;
	int				line;
	int				hash;
	int				min_y;
	int				max_y;
	int				min_x;
	int				max_x;
} 					t_grid;

typedef struct		s_shape {

	char			form[4][2];
	char			height;
	char			width;
	char			letter;
	struct s_shape	*next;
}					t_shape;

void				ft_grid_validity(int fd, t_shape **begin);
void				ft_add_value(char form[4][2], int i, int j, int k);
int					ft_cmp(int a, int b);
void				ft_swap(int *a, int *b);
t_shape				*ft_new(char shape[4][2], t_grid *nb);
void				ft_add_end(t_shape **lst, t_shape *new);
void				ft_print_list(t_shape **lst);
int					ft_lst_size(t_shape **lst);
int					ft_power_2(int nb);
int					size_square(t_shape **lst, int boolean);

#endif
