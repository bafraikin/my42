# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:00:28 by salquier          #+#    #+#              #
#    Updated: 2019/01/10 15:11:57 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = src/

SRC = $(SRCDIR)main.c $(SRCDIR)check.c $(SRCDIR)fillit.c $(SRCDIR)gest_letter.c\
	  $(SRCDIR)list.c $(SRCDIR)list2.c $(SRCDIR)print.c $(SRCDIR)solver.c \
	  $(SRCDIR)utils.c $(SRCDIR)get_next_line.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

.PHONY : all clean fclean re

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc -o $@ -c $? $(CFLAGS)

all: $(NAME) 

./libft/libft.a:
	make -C libft/

LIBCLEAN:
	make clean -C libft/

LIBFCLEAN:
	make fclean -C libft/

$(NAME): $(OBJECTS) ./libft/libft.a
	gcc -o $@ $(OBJECTS) -L libft/ -lft

clean: $(OBJECTS) LIBFCLEAN
	rm $(OBJECTS)

fclean: all clean LIBFCLEAN
	rm $(NAME)

re: fclean
	make
