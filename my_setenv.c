/*
** EPITECH PROJECT, 2022
** my_setenv
** File description:
** my_setenv
*/

#include "include/my.h"
#include "include/minishell.h"

char *setenv_name(char *dest, char *src);

bool search_in_env_cond(char *str1, char *str2)
{
    char *tok = NULL;
    tok = my_strtok(str1, '=');
    if (my_strlen(tok) != my_strlen(str2))
        return false;
    for (int i = 0; i < my_strlen(tok); i++) {
        if (tok[i] != str2[i])
            return false;
    }
    free(tok);
    return true;
}

bool search_in_env(llist env, char *str)
{
    element *tmp = env;
    while (tmp != NULL) {
        if (search_in_env_cond(tmp->val, str))
            return true;
        tmp = tmp->nxt;
    }
    return false;
}

char *set_zero(char *str, int size)
{
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    return str;
}

llist set_new_env(llist env, char *argv1, char *argv2)
{
    element *tmp = env;
    int size = my_strlen(argv2) + my_strlen(argv1);
    while (tmp != NULL) {
        if (search_in_env_cond(tmp->val, argv1)) {
            tmp->val = malloc(sizeof(char) * size + 1);
            tmp->val = set_zero(tmp->val, size);
            tmp->val = setenv_name(tmp->val, argv1);
            tmp->val = add_char(tmp->val, '=');
            tmp->val = add_str(tmp->val, argv2);
            return env;
        }
        tmp = tmp->nxt;
    }
    return false;
}

llist my_setenv(int ac UNUSED, char **argv UNUSED, llist env UNUSED)
{
    char *new_env = NULL;
    int size = my_strlen(argv[1]) + my_strlen(argv[2]);
    if (search_in_env(env, argv[1])) {
        env = set_new_env(env, argv[1], argv[2]);
    } else {
        new_env = malloc(sizeof(char) * size + 1);
        for (int i = 0; i < (my_strlen(argv[1]) + my_strlen(argv[2])); i++) {
            new_env[i] = '\0';
        }
        new_env = setenv_name(new_env, argv[1]);
        new_env = add_char(new_env, '=');
        new_env = add_str(new_env, argv[2]);
        env = add_back(env, new_env);
    }
    return env;
}
