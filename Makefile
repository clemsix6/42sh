##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## my make file
##

NAME = 42sh
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NBR_OF_FILES := $(words $(SRCS))
CC = gcc #-fsanitize=address

CFLAGS_LIB = -I./includes -L./lib/my -lmy
CFLAGS = -Wall -W -Wextra -g3 #-fsanitize=address

all: lib_make $(NAME)

lib_make:
	@make -C lib/my

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ $(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CFLAGS_LIB)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ rm -f $(OBJS)
		@make -C lib/my clean

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ rm -f $(NAME)
		@make -C lib/my fclean

re: 	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
