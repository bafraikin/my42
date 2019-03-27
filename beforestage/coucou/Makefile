# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:00:28 by salquier          #+#    #+#              #
#    Updated: 2019/03/27 19:59:32 by bafraiki         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -I mlx/ -I includes -I ./libft/includes

CC = gcc $(CFLAGS)

LIB = -L ./libft -lft -L mlx -lmlx

OBJECTS = $(SRC:.c=.o)

.PHONY : all clean fclean re

%.o: %.c
	$(CC) -o $@ -c $?

all: $(NAME) 

./libft/libft.a:
	make -C libft/

./mlx/libmlx.a:
	make -C mlx/

LIBCLEAN:
	make clean -C libft/
	make clean -C mlx/

LIBFCLEAN:
	make fclean -C libft/
	make clean -C mlx/

$(NAME): ./libft/libft.a $(OBJECTS) ./mlx/libmlx.a
	$(CC) -o $@ $(OBJECTS) $(LIB) -framework OpenGL -framework AppKit 

clean: $(OBJECTS) LIBCLEAN
	rm $(OBJECTS)

fclean: all LIBFCLEAN
	rm $(NAME)
	rm $(OBJECTS)

re: fclean
	make

