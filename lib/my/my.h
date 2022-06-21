/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef my
    #define my
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <signal.h>
    #include <sys/wait.h>

typedef struct element element;
struct element {
    char *val;
    struct element *nxt;
};

typedef element* llist;

void my_putchar(char c);
int my_strlen_jayson(const char *str);
int my_strlen(const char *str);
void my_putstr(const char *str);
int my_strlen_of2darray(char **str);
void my_printf (char *s, ...);
llist add_back(llist liste, char *valeur);
llist supprimerElement(llist list, char *valeur);
void print_list(llist liste);
void my_put_nbr(int nb);
int	my_strcmp(char *s1, char *s2);
char *add_char(char *dest, char src);
char *add_str(char *dest, char *src);
int my_getnbr(char const *str);
char *my_memcpy(char *dest, const char *src, size_t len);
char *my_strdup(char *str);

#endif
