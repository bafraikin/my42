# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:00:28 by salquier          #+#    #+#              #
#    Updated: 2019/03/22 18:44:28 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	color.c \
		fdf.c \
		free.c \
		gest_pnt.c \
		gest_windows.c \
		get_next_line.c \
		math.c \
		parser.c

CFLAGS = -Wall -Wextra -Werror -I mlx/ -I includes -L mlx -lmlx -L libft -lft -I ./libft/includes

OBJECTS = $(SRC:.c=.o)

.PHONY : all clean fclean re

%.o: %.c
	gcc -o $@ -c $? $(CFLAGS)

all: $(NAME) 

./libft/libft.a:
	make -C libft/

./mlx/mlx.a:
	make -C mlx/

LIBCLEAN:
	make clean -C libft/
	make clean -C mlx/

LIBFCLEAN:
	make fclean -C libft/
	make clean -C mlx/

$(NAME): ./libft/libft.a ./mlx/mlx.a $(OBJECTS)
	gcc -o $@ $(OBJECTS) $(CFLAGS) -framework OpenGL -framework AppKit 

clean: $(OBJECTS) LIBFCLEAN
	rm $(OBJECTS)

fclean: all clean LIBFCLEAN
	rm $(NAME)

re: fclean
	make

