/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** condition_parse.c
*/

#include "include/my.h"
#include "include/minishell.h"
#include <stdbool.h>

bool have_semicolon(char *cmd)
{
    for (int i = 0; cmd[i] != '\0' ; i++) {
        if (cmd[i] == ';') {
            return true;
        }
    }
    return false;
}

int have_redirect(char *cmd)
{
    for (int i = 0; cmd[i] != '\0' ; i++) {
        if (cmd[i] == '<' && cmd[i + 1] == '<') {
            return 1;
        } else if (cmd[i] == '<') {
            return 2;
        }
        if (cmd[i] == '>' && cmd[i + 1] == '>') {
            return 3;
        } else if (cmd[i] == '>') {
            return 4;
        }
    }
    return 0;
}

bool have_pipe(char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '|')
            return true;
    }
    return false;
}

bool have_double_esperluette(char *cmd)
{
    for (int i = 0; cmd[i] != '\0' ; i++) {
        if (cmd[i] == '&' && cmd[i + 1] == '&') {
            return true;
        }
    }
    return false;
}

bool have_double_pipe(char *cmd)
{
    for (int i = 0; cmd[i] != '\0' ; i++) {
        if (cmd[i] == '|' && cmd[i + 1] == '|') {
            return true;
        }
    }
    return false;
}
