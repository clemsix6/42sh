/*
** EPITECH PROJECT, 2022
** my_cd
** File description:
** my_cd
*/

#include "include/my.h"
#include "include/minishell.h"

int is_old_pdw(char *tok)
{
    char pth[] = "OLDPWD\0";

    for (int i = 0; i < my_strlen(pth); i++) {
        if (tok[i] != pth[i]){
            return 0;
        }
    }
    return 1;
}

bool search_old_pwd(char *str)
{
    char *tok = NULL;
    tok = my_strtok(str, '=');
    if (is_old_pdw(tok) == 1)
        return true;
    free(tok);
    return false;
}

char *setenv_name(char *dest, char *src)
{
    for (int i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    return dest;
}

llist set_old_pdw(llist env, char old_pdw[1024])
{
    element *tmp = env;
    while (tmp != NULL) {
        if (search_old_pwd(tmp->val)) {
            tmp->val = malloc(sizeof(char) * my_strlen(old_pdw) + 8);
            tmp->val = setenv_name(tmp->val, "OLDPWD=");
            tmp->val = add_str(tmp->val, old_pdw);
            return env;
        }
        tmp = tmp->nxt;
    }
    return NULL;
}

void chdir_condition(char **argv)
{
    if (chdir(argv[1]) == -1) {
        my_putstr(argv[1]);
        my_putstr(": Not a directory.\n");
    }
}

void cd_tiret(llist env)
{
    char *new_path = NULL;
    element *tmp = env;
    while (tmp != NULL) {
        if (search_old_pwd(tmp->val)) {
            new_path = strtok(my_strdup(tmp->val), "=");
            new_path = strtok(NULL, "=");
            chdir(new_path);
            return;
        }
        tmp = tmp->nxt;
    }
}

llist my_cd(int ac UNUSED, char **argv UNUSED, llist env)
{
    char pwd[1024] = {0};
    char old_pdw[1024] = {0};
    getcwd(old_pdw, sizeof(old_pdw));
    if (my_strlen_of2darray(argv) == 2) {
        if (argv[1][0] == '-') {
            cd_tiret(env);
        }else {
            chdir_condition(argv);
        }
    }else {
        chdir("/home");
    }
    env = set_old_pdw(env, old_pdw);
    getcwd(pwd, sizeof(pwd));
    env = set_pwd(env, pwd);
    return env;
}
