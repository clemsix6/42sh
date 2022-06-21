/*
** EPITECH PROJECT, 2022
** my_env
** File description:
** my_env
*/

#include "include/my.h"
#include "include/minishell.h"

llist my_env(int ac UNUSED, char **argv UNUSED, llist env UNUSED)
{
    element *tmp = env;
    while (tmp != NULL) {
        my_putstr(tmp->val);
        my_putchar('\n');
        tmp = tmp->nxt;
    }
    return env;
}
