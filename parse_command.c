/*
** EPITECH PROJECT, 2022
** parse_command
** File description:
** parse_command
*/

#include "include/my.h"
#include "include/minishell.h"

int my_strlen_getline(char * str)
{
    int len = 0;

    while (str[len] != '\n') {
        len += 1;
    }
    return len;
}

char **mem_2d_array(int size)
{
    char **result = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i <= size; i++) {
        result[i] = NULL;
    }
    return result;
}

char **parse_command(char *arg, char *separator)
{
    int i = 0;
    int size = comt(arg);
    char **result = mem_2d_array(size);
    result[0] = strtok(arg, separator);
    for (i = 1; i < size; i++) {
        result[i] = strtok(NULL, separator);
    }
    result[size] = NULL;
    return result;
}
