# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:00:28 by salquier          #+#    #+#              #
#    Updated: 2019/01/08 17:54:00 by salquier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = ./src

SRC = main.c check.c fillit.c gest_letter.c list.c list2.c print.c solver.c \
	  utils.c get_next_line.c 

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRCDIR)/$(SRC)
	gcc -o $(NAME) $(SRCDIR)/$(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)
