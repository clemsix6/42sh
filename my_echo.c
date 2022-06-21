/*
** EPITECH PROJECT, 2022
** echo
** File description:
** echo
*/

#include "include/my.h"
#include "include/minishell.h"

void print_basic_echo(int nbr, char **str)
{
    for (int i = 1; i < nbr - 1; i++) {
        printf("%s ", str[i]);
    }
    printf("%s\n", str[nbr - 1]);
}

void print_n_echo(int nbr, char **str)
{
    for (int i = 2; i < nbr - 1; i++) {
        printf("%s ", str[i]);
    }
    printf("%s", str[nbr - 1]);
}

void check_flags(int argc, char **argv)
{
    if (strcmp(argv[1], "-n") == 0)
        print_n_echo(argc, argv);
    else
        print_basic_echo(argc, argv);
}

llist my_echo(int argc, char **argv, llist env)
{
    int nb = my_strlen_of2darray(argv);
    if (nb >= 2)
        check_flags(nb, argv);
    return env;
}
