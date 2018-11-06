# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:21:43 by bafraiki          #+#    #+#              #
#    Updated: 2018/11/05 19:34:11 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC			=	srcs/

INCLUDE		=	includes/

FILE		=	$(SRC)ft_putchar.c $(SRC)ft_putstr.c $(SRC)ft_strcmp.c $(SRC)ft_strlen.c $(SRC)ft_swap.c

FLAGS		=	-Wall -Werror -Wextra

CC			= 	ar rcs	

OBJ			=	$(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $@ $^

%.o: %.c
	gcc -I $(INCLUDE) -o $@ -c $? $(FLAGS)

clean: $(OBJ)
	rm $(OBJ)

fclean: all clean
	rm $(NAME)

re: all fclean 
	make

norme:
	norminette $(FILE)

.PHONY: all re clean fclean
	# **************************************************************************** #

