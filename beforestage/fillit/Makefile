# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:00:28 by salquier          #+#    #+#              #
#    Updated: 2019/01/08 18:50:21 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = src/

SRC = $(SRCDIR)main.c $(SRCDIR)check.c $(SRCDIR)fillit.c $(SRCDIR)gest_letter.c $(SRCDIR)list.c $(SRCDIR)list2.c $(SRCDIR)print.c $(SRCDIR)solver.c \
	  $(SRCDIR)utils.c $(SRCDIR)get_next_line.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

.PHONY : all clean fclean re

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc -o $@ -c $? $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -o $@ $(OBJECTS) -L libft/ -lft

clean: $(OBJECTS)
	rm $(OBJECTS)

fclean: all clean
	rm $(NAME)

re: fclean
	make
