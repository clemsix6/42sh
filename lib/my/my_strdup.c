/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *str)
{
    size_t len = my_strlen(str) + 1;
    char *new = NULL;

    new = malloc(sizeof(char) * len);
    my_memcpy(new, str, len);
    return new;
}
