/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** parse_operator.c
*/

#include "include/minishell.h"
#include "include/my.h"

int malloc_right(char *str, char sepator)
{
    int result = 0;
    for (int i = 0; str[i] != sepator; i++) {
        result += 1;
    }
    return result;
}

char *take_left(char *str, int index)
{
    char *result = malloc(sizeof(char) * index + 1);
    int i = 0;

    for (i = 0; i < index; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}

int count_right(char *str, int index)
{
    int i = 0;

    for (i = index; str[i] != '\0'; i++);
    return i;
}

char *take_right(char *str, int index)
{
    char *result = malloc(sizeof(char) * count_right(str, index) + 1);
    int i = 0;

    for (i = 0; str[i + index + 1] != '\0'; i++) {
        result[i] = str[i + index + 1];
    }
    result[i] = '\0';
    return result;
}
