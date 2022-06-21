/*
** EPITECH PROJECT, 2022
** my_exit
** File description:
** my_exit
*/

#include "include/my.h"
#include "include/minishell.h"

llist my_exit(int ac UNUSED, char **argv UNUSED, llist env UNUSED)
{
    if (ac == 1)
        exit(0);
    exit(my_getnbr(argv[1]));
    return env;
}
