/*
** EPITECH PROJECT, 2022
** my_unsetenv
** File description:
** my_unsetenv
*/

#include "include/my.h"
#include "include/minishell.h"

llist my_unsetenv(int ac UNUSED, char **argv UNUSED, llist env UNUSED)
{
    env = supprimerElement(env, argv[1]);
    return env;
}
