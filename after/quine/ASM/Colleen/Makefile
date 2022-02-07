all:
	nasm -f elf64 Colleen.s && gcc -static Colleen.o -o Colleen
clean: all
	rm Colleen.o
fclean: all clean
	rm Colleen
