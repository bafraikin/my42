
NAME = Sully

SRC = Sully.c

CFLAGS =  

CC = gcc $(CFLAGS)

OBJECTS = $(SRC:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $?

all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

clean: $(OBJECTS)
	rm $(OBJECTS)

fclean: all
	rm $(OBJECTS)
	rm -f $(NAME)_*
	rm $(NAME)

re: fclean
	make

.PHONY : all clean fclean re 
