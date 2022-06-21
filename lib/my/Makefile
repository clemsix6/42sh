##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefil
##

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -W -Wextra -g3
TARGET = libmy.a
HEADER_NAME = my.h

all: $(TARGET)
	@echo "\033[1;36m[ LIB COMPILED ] \033[0m"

$(TARGET): $(OBJ)
	@ar rc $(TARGET) $(OBJ)
	@cp $(HEADER_NAME) ../../include

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(TARGET)

re : fclean all

%.o:	%.c
		@ $(CC) -o $@ -c $< $(CFLAGS)
