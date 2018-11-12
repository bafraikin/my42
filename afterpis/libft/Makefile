# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:19:42 by bafraiki          #+#    #+#              #
#    Updated: 2018/11/12 18:37:19 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft.a


FILE		=	ft_atoi.c  ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_strcat.c  ft_strchr.c  ft_strcmp.c  ft_strcpy.c  ft_strdup.c  ft_strlcat.c  ft_strlen.c  ft_strncat.c  ft_strncmp.c  ft_strncpy.c  ft_strnstr.c  ft_strrchr.c  ft_strstr.c  ft_tolower.c  ft_toupper.c ft_strnew.c 

FLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJ			=	$(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) -o $@ -c $? $(FLAGS)

clean: $(OBJ)
	rm $(OBJ)

fclean: all clean
	rm $(NAME)

re: all fclean 
	make

norme:
	norminette $(FILE)

.PHONY: all re clean fclean

