/*
** EPITECH PROJECT, 2022
** parse_path
** File description:
** parse_path
*/

#include "include/my.h"
#include "include/minishell.h"

int number_of_doublepoints(char *env)
{
    int count = 0;

    for (int i = 0; i < my_strlen(env); i++) {
        if (env[i] == ':')
            count += 1;
    }
    return count + 1;
}

int size_of_link(char *env, int index)
{
    int count = 0;

    while (env[index + count] != ':' && env[index + count] != '\0') {
        count += 1;
    }
    return count;
}

char **parse_path(char *env)
{
    int size = number_of_doublepoints(env);
    char **result = malloc(sizeof(char *) * (size + 1));
    int index_env = 5;
    int size_link = 0;
    int j = 0;
    for (int i = 0; i < size; i++) {
        size_link = size_of_link(env, index_env);
        result[i] = malloc(sizeof(char) * size_link + 1);
        for (j = 0; j < size_link; j++) {
            result[i][j] = env[index_env];
            index_env += 1;
        }
        result[i][j++] = '\0';
        index_env += 1;
    }
    result[size ] = NULL;
    return result;
}
