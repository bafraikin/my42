/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:14:36 by bafraiki          #+#    #+#             */
/*   Updated: 2019/01/07 14:47:24 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct 		s_check {
	int				i;
	int				line;
	int				hash;
	int				min_y;
	int				max_y;
	int				min_x;
	int				max_x;
} 					t_check;

typedef struct		s_letter {
	char			letter;
	struct s_letter	*next;
}					t_letter;

typedef struct		s_shape {

	char			form[4][2];
	char			height;
	char			width;
	char			letter;
	struct s_shape	*next;
}					t_shape;

typedef struct		s_grid {
	char			**grid;
	t_shape			*begin;
	int 			size;
	t_shape			*rejet;
}					t_grid;

int					place_piece(t_grid *bgrid, t_shape *elem);
void				erase(int undex, int deudex, t_grid *bgrid, int nb_piece);
char				give_me_a_letter(int index, char *tab, t_letter **head, t_grid *bgrid);
void				fillit_baby(t_grid *bgrid, t_shape *begin, int size_l);
void				ft_grid_validity(int fd, t_shape **begin);
void				ft_add_value(char form[4][2], int i, int j, int k);
int					ft_cmp(int a, int b);
void				ft_swap(int *a, int *b);
t_shape				*ft_new(char shape[4][2], t_check *nb);
void				ft_add_end(t_shape **lst, t_shape *new);
void				ft_print_list(t_shape **lst);
int					ft_lst_size(t_shape **lst);
int					ft_power_2(int nb);
int					size_square(t_shape **lst, int boolean);
char				**generate_big_grid(t_shape **begin);
t_letter			*ft_new_letter(char c);
void				add_new_letter(t_letter **begin, char c);
char				remove_letter(t_letter **begin, char c);
void				ft_build_utils(char *tab, t_letter **begin, int size);
t_shape				*find_elem(t_shape *begin, int nb);
void				ft_print_grid(char **grid, int size);

#endif
