/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** set_pwd
*/

#include "include/my.h"
#include "include/minishell.h"

int is_pdw(char *tok)
{
    char pth[] = "PWD\0";

    for (int i = 0; i < my_strlen(pth); i++) {
        if (tok[i] != pth[i]){
            return 0;
        }
    }
    return 1;
}

bool search_pwd(char *str)
{
    char *tok = NULL;
    tok = my_strtok(str, '=');
    if (is_pdw(tok) == 1)
        return true;
    free(tok);
    return false;
}

llist set_pwd(llist env, char pwd[1024])
{
    element *tmp = env;
    while (tmp != NULL) {
        if (search_pwd(tmp->val)) {
            tmp->val = malloc(sizeof(char) * my_strlen(pwd) + 5);
            tmp->val = setenv_name(tmp->val, "PWD=");
            tmp->val = add_str(tmp->val, pwd);
            return env;
        }
        tmp = tmp->nxt;
    }
    return NULL;
}
