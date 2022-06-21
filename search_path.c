/*
** EPITECH PROJECT, 2022
** search_path
** File description:
** search_path
*/

#include "include/my.h"
#include "include/minishell.h"

int is_path(char *tok)
{
    char pth[] = "PATH\0";

    for (int i = 0; i < my_strlen(pth); i++) {
        if (tok[i] != pth[i]){
            return 0;
        }
    }
    return 1;
}

int search_path(char **env)
{
    char *tok = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        tok = my_strtok(env[i], '=');
        if (is_path(tok) == 1)
            return i;
        free(tok);
    }
    return 0;
}
