# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:19:42 by bafraiki          #+#    #+#              #
#    Updated: 2018/11/06 18:27:57 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft.a

INCLUDE		=	includes/

SRC			=	srcs/

FILE		=	$(SRC)ft_memset.c $(SRC)ft_bzero.c $(SRC)ft_memcpy.c

FLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJ			=	$(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

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

