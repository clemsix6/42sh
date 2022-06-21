/*
** EPITECH PROJECT, 2022
** get_buildin
** File description:
** get_buildin
*/

#include "include/my.h"
#include "include/minishell.h"

typedef struct builtin_t {
    char *name;
    llist (*fct_ptr) (int ac, char **argv , llist env);
} builtin_t;

const builtin_t builtins[] = {
    {"exit", my_exit},
    {"cd", my_cd},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"env", my_env},
    {"echo", my_echo}
};

llist get_builtin(int ac, char *name, char **av, llist env)
{
    for (int i = 0; i < 6; i++){
        if (strcmp(name, builtins[i].name) == 0){
            env = builtins[i].fct_ptr(ac, av, env);
            return env;
        }
    }
    return NULL;
}
