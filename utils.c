/*
** EPITECH PROJECT, 2022
** utils
** File description:
** utils
*/

#include "include/my.h"
#include "include/minishell.h"

int my_strlen_shell(char const *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return i;
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++){
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

int comt_result(char *arg, int i, int result)
{
    if (arg[i + 1] != '\0') {
        result += 1;
    }
    return result;
}

int comt(char *arg)
{
    int result = 0;
    if (arg[0] != ' ') {
        result += 1;
    }
    for (int i = 0; i < my_strlen(arg); i++){
        if (arg[i] == ' ' && arg[i + 1] != ' '){
            result = comt_result(arg, i, result);
        }
    }
    return result;
}

char *initialize(char *str)
{
    int i = 0;

    while (42){
        if (str[i] == '\n'){
            str[i] = '\0';
            return str;
        }
        i++;
    }
}
