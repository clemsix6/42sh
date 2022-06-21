/*
** EPITECH PROJECT, 2022
** add_str
** File description:
** add_str
*/

#include "my.h"

char *add_str(char *dest, char *src)
{
    int index = 0;
    int i = 0;
    int size_dest = 0;
    if (dest != NULL) {
        size_dest = my_strlen(dest);
    }
    int size_src = my_strlen(src);
    char *result = malloc(sizeof(char) * (size_dest + size_src) + 1);
    for (int j = 0; j < (size_dest + size_src) + 1; j++) {
        result[j] = '\0';
    }
    for (index = 0; index < size_dest; index++) {
        result[index] = dest[index];
    }
    for (i = 0; i < size_src; i++) {
        result[i + index] = src[i];
    }
    return result;
}
