
NAME = Grace

SRC = Grace.c

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
	rm $(NAME)

re: fclean
	make

.PHONY : all clean fclean re 
