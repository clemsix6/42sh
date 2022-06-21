/*
** EPITECH PROJECT, 2022
** my_strtok
** File description:
** my_strtok
*/

#include "include/my.h"
#include "include/minishell.h"

int size_word_env(char *env, char delimiter)
{
    int i = 0;

    while (env[i] != delimiter) {
        i++;
    }
    return i;
}

char *my_strtok(char *env, char delimiter)
{
    char *result = malloc(sizeof(char) * size_word_env(env, delimiter) + 1);

    for (int i = 0; i < size_word_env(env, delimiter) + 1; i++) {
        result[i] = '\0';
    }
    for (int i = 0; i < size_word_env(env, delimiter); i++) {
        result[i] = env[i];
    }
    return result;
}
