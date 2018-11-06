# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:19:42 by bafraiki          #+#    #+#              #
#    Updated: 2018/11/06 14:07:52 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	ft_display_file

INCLUDE		=	includes/

SRC			=	srcs/

FILE		=	$(SRC)main.c 

FLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJ			=	$(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) -I $(INCLUDE) -o $@ -c $? $(FLAGS)

clean: $(OBJ)
	rm $(OBJ)

fclean: all clean
	rm $(NAME)

re: all fclean 
	make

norme:
	norminette $(FILE)

.PHONY: all re clean fclean

