# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:19:42 by bafraiki          #+#    #+#              #
#    Updated: 2019/01/10 14:48:39 by bafraiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft.a

FILE		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_list_at.c ft_list_reverse.c ft_list_size.c ft_list_sort.c ft_swapptr.c ft_list_last.c ft_list_push_back.c ft_list_remove_if.c ft_list_find.c ft_lstadd.c ft_list_add_back.c ft_lst_add_cont.c

FLAGS		=	-Wall -Werror -Wextra

CC			= gcc

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

