/*
** EPITECH PROJECT, 2022
** add_char
** File description:
** add_char
*/

#include "my.h"

char *add_char(char *dest, char src)
{
    int i;
    char *result = malloc(sizeof(char)* my_strlen(dest) + 2);
    for (int a = 0; a <  my_strlen(dest) + 2; a++) {
        result[a] = '\0';
    }
    for (i = 0; i < my_strlen(dest); i++){
        result[i] = dest[i];
    }
    result[i] = src;
    return result;
}
