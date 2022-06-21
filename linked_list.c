/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** linked list
*/

#include "include/my.h"
#include "include/minishell.h"

int size_ll(llist list)
{
    int result = 0;
    element *tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->val);
        result += 1;
        tmp = tmp->nxt;
    }
    return result;
}

char **ll_to_env(llist ll_env)
{
    int size = size_ll(ll_env);
    element *tmp = ll_env;
    char **list = malloc(sizeof(char *) * size + 2);
    int i = 0;
    while (tmp != NULL) {
        list[i] = tmp->val;
        tmp = tmp->nxt;
        i++;
    }
    list[i] = NULL;
    return list;
}

llist env_to_ll(char **env)
{
    llist ll_env = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        ll_env = add_back(ll_env, my_strdup(env[i]));
    }
    return ll_env;
}
